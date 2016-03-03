#pragma once

#include <vector>
#include <array>
#include <iostream>
#include <bitset>
#include <assert.h>
#include "SFML/System/Time.hpp"
#include "Component.hpp"

using std::string;
using std::vector;
using std::array;
using std::unique_ptr;
using std::bitset;
using std::move;
using std::cerr;
using std::endl;
using std::forward;


namespace wn2d {
#define MAX_COMPONENTS 64

	class Component;
	class EntityManager;
	class Game;

	class Entity
	{
		friend class EntityManager;
	private:
		EntityManager* owner;
		Game* game;

		bitset<MAX_COMPONENTS> componentBitset;
		string name;
		bool alive{ true };
		int z = 0;

		vector <unique_ptr<Component>> components;
		array<Component*, MAX_COMPONENTS> componentArray; // stops entities becoming insanely complex (not actually nessecary)

		bool iterating{ false };
		vector<Component*> queuedComponents;

		Entity(string name, EntityManager* owner);

		void addQueuedComponents();

	public:
		template<class T>
		bool hasComponent(){
			return componentBitset[getComponentTypeID<T>()];
		}

		template<class T, typename... args>
		T& addComponent(args&&... componentArgs) {
			assert(!hasComponent<T>()); // throw if this entity already has this component 

			T* component = new T(forward<args>(componentArgs)...); // create component with relevant args
			size_t componentID = getComponentTypeID<T>(); // creates unique id for component types
			component->id = componentID;
			component->setOwner(this);
			component->setGame(game);
			if (!iterating) {
				unique_ptr<Component> uniqueComponentPtr{ component };
				components.emplace_back(move(uniqueComponentPtr));
				componentArray[componentID] = component;
				componentBitset[componentID] = true;
				component->init();
			} else {
				this->queuedComponents.emplace_back(component);
			}
			cout << "Added component" << endl;
			return *component;
		}

		template<class T>
		T& getComponent(){
			assert(hasComponent<T>());
			auto componentPtr(componentArray[getComponentTypeID<T>()]);
			return *static_cast<T*>(componentPtr);
		}

		void onStart();
		bool update(float frameTime);
		void draw(sf::RenderTarget& target);
		int getZ();
		void setZ(int newZ);

		Game* getGame();
		const string getName();
		bool isAlive();
		void destroy();
	};
}



