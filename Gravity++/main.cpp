#include "Game.h"
#include "Games/Example.h"

#include <Windows.h>

using namespace wn2d;

int main()
{
	unsigned int width = GetSystemMetrics(SM_CXSCREEN);
	unsigned int height = GetSystemMetrics(SM_CYSCREEN);
	Game game(width, height, "White Nitro 2D");

	loadGame(&game);

	game.init();
	game.setVerticalSyncEnabled(true);

	GameState state = game.run();

	if (state == CLOSING) {
		game.close();
	} else {
		game.close();
	}

	return 0;
}