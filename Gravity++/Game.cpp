#include "Game.h"

using namespace wn2d;

sf::Vector2u Game::SCREEN_SIZE;

Game::Game(unsigned int width, unsigned int height, const char* title, bool lighting) :
		sf::RenderWindow(),
		EntityManager(this){
	state = INITIALIZING;
	style = sf::Style::Resize;
	this->title = title;
	SCREEN_SIZE = { width, height };
	videoMode.width = width;
	videoMode.height = height;
	videoMode.bitsPerPixel = 32;
}

void Game::init(){
	sf::RenderWindow::create(videoMode, title, style, settings);

	if (lightingEnabled) {
		//TODO
	}
}

void Game::setWindowSize(const sf::Vector2u size) {
	SCREEN_SIZE = size;
	videoMode.width = size.x;
	videoMode.height = size.y;
	sf::RenderWindow::setSize(size);
}

sf::Vector2u Game::getWindowSize() {
	return{ videoMode.width, videoMode.height };
}

sf::Vector2f Game::getViewPosition() {
	return sf::RenderWindow::getView().getCenter();
}

void Game::goFullscreen(){
	if (sf::RenderWindow::isOpen()) {
		sf::RenderWindow::close();
		style = sf::Style::Fullscreen;
		init();
	} else {
		style = sf::Style::Fullscreen;
	}
}

// starts the game loop running
GameState Game::run()
{
	state = LOADING;

	//Call init for each component
	//EntityManager::init();

	state = RUNNING;
	sf::Clock clock;
	clock.restart();

	while (state == RUNNING) {
		//TODO check for pause and break loop

		timeStep = clock.getElapsedTime().asSeconds();
		clock.restart();

		//handle Input 
		/*if (InputManager::handleInput() == CLOSE) {
			state = CLOSING;
			return state;
			}*/

		//handle events
		//EventManager::handleEvents();

		//update entities
		EntityManager::update(timeStep);

		sf::RenderWindow::clear();

		//draw renderables
		sf::RectangleShape white;
		white.setSize({ (float)getSize().x, (float)getSize().y });
		white.setFillColor(sf::Color::White);
		white.setOrigin(white.getSize().x / 2.0f, white.getSize().y / 2.0f);
		white.setPosition(getViewPosition());
		sf::RenderWindow::draw(white);
		EntityManager::draw(*this);

		if (lightingEnabled) {
			//TODO
		}

		sf::RenderWindow::display();
	}

	if (state == CLOSING) {
		return state;
	}
	return IDLE;
}

GameState Game::getState() {
	return state;
}

void Game::closing(){
	state = CLOSING;
	//EntityManager::destroyAll();
}

void Game::close() {
	sf::RenderWindow::close();
	//EntityManager::destroyAll();
	//EntityManager::removeDeadEntities();
	state = CLOSED;
}

sf::FloatRect Game::getCameraRect() {
	sf::Vector2f cameraPos = { getView().getCenter().x - (getSize().x / 2.0f), getView().getCenter().y - (getSize().y / 2.0f) };
	sf::FloatRect viewRect = { cameraPos.x, cameraPos.y, (float)getSize().x, (float)getSize().y };
	return viewRect;
}