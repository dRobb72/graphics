#include "MainGame.h"

MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1280;
	_screenHeight = 720;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();

	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

	gameLoop();
}

void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit" << std::endl;
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
}


void MainGame::initSystems()
{
	//initialize sdl
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Graphics", 
							   SDL_WINDOWPOS_CENTERED, 
							   SDL_WINDOWPOS_CENTERED, 
							   _screenWidth, _screenHeight,
							   SDL_WINDOW_OPENGL);	

	if (_window == nullptr)
	{
		fatalError("[ERROR]: SDL Window Not Created\n");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);

	if (glContext == nullptr)
	{
		fatalError("[ERROR]: Could not create context\n");
	}

	GLenum errorCheck = glewInit();
	if (errorCheck != GLEW_OK)
	{
		fatalError("[ERROR]: Could Not Initialize Glew\n");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;
	
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			if (INPUT_INFO) printf("X: %d | Y: %d\n", evnt.motion.x, evnt.motion.y);
			break;
		case SDL_KEYDOWN:
			if (INPUT_INFO) printf("KeyCode of key pressed: %d\n", evnt.key.keysym.scancode);
			break;
		default:
			if (INPUT_INFO) printf("[INPUT]: Nothing To Process, Moving On\n");
			break;
		}
	}
}

void MainGame::drawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_sprite.draw();

	SDL_GL_SwapWindow(_window);
}
