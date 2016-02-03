#include "Game.h"
#include "EntityManager.h"

using namespace wn2d;

Entity::Entity(string name, EntityManager* owner) : name(name), owner(owner) {
	game = owner->getGame();
}

const string Entity::getName() {
	return name;
}

void Entity::onStart() {
	for (auto& component : components) {
		component->init();
	}
}

bool Entity::update(float frameTime) {
	iterating = true;
	for (auto& component : components) {
		component->update(frameTime);
	}
	iterating = false;
	addQueuedComponents();
	return false;
}

void Entity::draw(sf::RenderTarget& target) {
	for (auto& component : components) {
		component->draw(target);
	}
}

int Entity::getZ() {
	return z;
}

void Entity::setZ(int newZ) {
	z = newZ;
	//TODO
}

Game* Entity::getGame(){
	return game;
}

bool Entity::isAlive() {
	return alive;
}

void Entity::destroy(){
	alive = false;
}

//TODO: NOT TESTED
void Entity::addQueuedComponents(){
	for (auto component : queuedComponents){
		unique_ptr<Component> uniqueComponentPtr{ component };
		components.emplace_back(move(uniqueComponentPtr));
		componentArray[component->id] = component;
		componentBitset[component->id] = true;
		component->onStart();
	}
	queuedComponents.clear();
}