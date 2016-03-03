#pragma once

#include <string>
#include <bitset>
#include <memory>
#include <algorithm>
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "Utilities.hpp"

using std::string;
using std::size_t;
using std::bitset;
using std::is_base_of;

namespace wn2d {

	inline size_t getComponentID() NOEXCEPT{
		static size_t lastID{ 0u };
		return lastID++;
	}

	template<class T>
	inline size_t getComponentTypeID() NOEXCEPT{
		//static_assert(is_base_of<component, T>::value, "T must inherit from Component!");
		static size_t typeID{ getComponentID() };
		return typeID;
	}

	class Entity;
	class Game;

	class Component{
		friend class Entity;

	private:
		size_t id;

	protected:
		Entity* owner{ nullptr };
		Game* game{ nullptr };

		Component() {

		}

		virtual void init(){

		}

		virtual void onStart(){

		}

		virtual void update(float frameTime) {

		}

		virtual void draw(sf::RenderTarget& target) {
			
		}

		void setOwner(Entity* owner) {
			this->owner = owner;
		}

		void setGame(Game* game) {
			this->game = game;
		}
	public:
		virtual ~Component() {

		}

		Entity* getOwner() {
			return owner;
		}
	};
}