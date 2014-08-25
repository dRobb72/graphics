#pragma once

#include <SDL\SDL.h>
#include <GL\glew.h>

#include "Sprite.h"

#include <iostream>
#include <string>
#include <random>
#include <ctime>

enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:
	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();

	SDL_Window* _window;
	GameState _gameState;

	Sprite _sprite;

	int _screenWidth;
	int _screenHeight;

	const bool INPUT_INFO = false;
};

