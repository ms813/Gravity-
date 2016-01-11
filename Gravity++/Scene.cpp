#include "Scene.h"

Scene::Scene():
VERLET_STATE(true)
{	
	loadLevelJSON("resources/leveldata/level1.json");
	
	auto ptr = std::make_shared<PhysicsSystem>(_physicsSystem);
	_entityFactory.registerListener(ptr);

	std::shared_ptr<Entity> asteroid(new Entity()); 
	_entityFactory.buildEntity("asteroid", asteroid);
	
	entities.push_back(asteroid);	
}


Scene::~Scene()
{
}


bool Scene::draw(sf::RenderWindow &window)
{		
	for (auto &entity : entities)
	{
		entity->draw(window);
	}

	return true;
}


bool Scene::update(const float dt)
{
	_physicsSystem.update(dt, VERLET_STATE);
	for (auto &entity : entities){
		entity->update(dt, VERLET_STATE);
	}

	VERLET_STATE = !VERLET_STATE;
	return true;
}

bool Scene::handleInput(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}

	return true;
}


bool Scene::loadLevelJSON(const std::string path)
{
	using namespace rapidjson;
	using namespace std;

	ifstream inputStream(path);
	string fileContents((istreambuf_iterator<char>(inputStream)),
		istreambuf_iterator<char>());

	const char* chars = fileContents.c_str();
	StringStream s(chars);
	
	levelData.ParseStream(s);
	
	cout << levelData["bobby"].GetString() << endl;
	return true;
}

