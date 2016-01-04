#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <fstream>
#include <rapidjson/document.h>

#include "Entity.h"
#include "EntityFactory.h"
#include "PhysicsController.h"
#include "EventHandler.h"



class Scene
{
public:
	Scene();
	virtual ~Scene();
	bool draw(sf::RenderWindow &window);
	bool update(const float dt);
	bool handleInput(sf::RenderWindow &window);
	bool loadLevelJSON(const std::string path);

private:
	std::vector<std::shared_ptr<Entity>> entities;
	bool VERLET_STATE;
	rapidjson::Document levelData;
	EventHandler _eventHandler;
	EntityFactory _factory;
};

