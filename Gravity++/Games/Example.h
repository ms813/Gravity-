#pragma once
#include "../Game.hpp"
#include "ExampleComponent.h"

using namespace wn2d;

void loadGame(Game* game) {
	//create entities

	Entity& exampleEntity = game->createEntity("Example");
	exampleEntity.addComponent<ExampleComponent>(sf::Vector2f{ 500, 500 });

}