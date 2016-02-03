#pragma once

#include<SFML/Graphics.hpp>
#include "EntityManager.h"
//#include "EventManager.h"
//#include "nxe\Lighting.h"

namespace wn2d{

	enum GameState{
		RUNNING		/*!< The game is currently in the main loop.*/,
		IDLE		/*!< The game is not in the main loop but the window is open and everything is initialized. */,
		CLOSING		/*!< The x or escape has been pressed and the game will close soon.*/,
		PAUSED		/*!< The game is in the main loop but is not running.*/,
		LOADING		/*!< The components are currently being initialized.*/,
		INITIALIZING/*!< The game is currently being initialized.*/,
		CLOSED		/*!< The window has been closed and the components in the scene have been destroyed.*/
	};

	class Game : public sf::RenderWindow, public EntityManager/*, public EventManager, public nxe::Lighting, public InputManager*/
	{
	public:
		sf::Sprite globalLightSprite;

		Game(unsigned int width, unsigned int height, const char* title, bool lighting = false);
		
		void init();
		void setWindowSize(const sf::Vector2u size);
		sf::Vector2u getWindowSize();
		sf::Vector2f getViewPosition();

		void goFullscreen();

		GameState run();
		GameState getState();
		void closing();
		void close();

		sf::FloatRect getCameraRect();
		static sf::Vector2u SCREEN_SIZE;

	private:

		float timeStep;
		GameState state;
		sf::VideoMode videoMode;
		int style;
		sf::ContextSettings settings;
		sf::String title;

		bool lightingEnabled = false;

		sf::Shader unShadowShader;
		sf::Shader lightOverShapeShader;
		sf::Texture penumbraTexture;
		sf::Texture directionalLightTexture;

	};
}
