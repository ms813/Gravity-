#pragma once

#include <iostream>
#include <algorithm>
#include "Entity.hpp"
#include "SFML/System/Clock.hpp"

using std::cout;
using std::endl;
using std::sort;
using std::remove_if;

namespace wn2d {

	class EntityManager {
	private:
		vector<unique_ptr<Entity>> entities{};

		bool iterating;
		vector<Entity*> queuedEntities{};

		void addQueuedComponents() {
			for (auto entity : queuedEntities) {
				unique_ptr<Entity> uniqueEntityPtr{ entity };
				entities.emplace_back(move(uniqueEntityPtr));
			}
			queuedEntities.clear();
		}

		bool zOrderDirty;
		Game* game;

	public:
		EntityManager(Game* game) : 
			zOrderDirty(false),
			iterating(false),
			game(game) {

		}

		Entity& createEntity(string name) {
			Entity* entity = new Entity(name, this);

			if (!iterating) {
				unique_ptr<Entity> uniqueEntityPtr{ entity };
				entities.emplace_back(move(uniqueEntityPtr));
			} else {
				queuedEntities.emplace_back(entity);
			}

			zOrderDirty = true;
			return *entity;
		}

		void init() {
			iterating = true;
			for (auto& entity : entities) {
				entity->onStart();
			}
			iterating = false;
		}

		void update(float frameTime) {
			removeDeadEntities();
			iterating = true;
			for (auto& entity : entities) {
				entity->update(frameTime);
			}
			iterating = false;
			addQueuedComponents();
		}

		void draw(sf::RenderTarget& target) {
			if (zOrderDirty) {
				// do a sort, probably a static function in its own class
				zOrderDirty = false;
			}
			iterating = true;
			for (auto& entity : entities) {
				entity->draw(target);
			}
			iterating = false;
		}

		void destroyAll(){
			iterating = true;
			for (auto& entity : entities) {
				entity->destroy();
			}
			iterating = false;
		}

		void removeDeadEntities(){
			entities.erase(
				remove_if(begin(entities),
				end(entities),
				[](const unique_ptr<Entity>& entity){
					if (!entity->isAlive()){
						cout << entity->getName() << " destroyed" << endl;
						return true;
					}
					return false;
				}),
				end(entities)
			);
		}

		void zOrderUpdated() {
			zOrderDirty = true;
		}

		Game* getGame() {
			return game;
		}

	};

}