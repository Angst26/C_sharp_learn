
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "Game.h"





int main(int argc, char* args[])
{
	AllocConsole();
	freopen("CON", "w", stdout);
	Game *g_game;
	g_game = new Game();
	g_game->init("Chapter1", 100, 100, 640, 580, false);

	while (g_game->running()) {
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}

