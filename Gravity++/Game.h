#pragma once

#include<SFML/Graphics.hpp>
#include "Scene.h"

class Game
{
public:
	Game();
	~Game();

	// starts the game loop running
	int run();
};
