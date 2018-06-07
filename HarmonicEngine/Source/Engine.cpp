#include "Engine.h"

#include "Systems/SystemManager.h"
#include "Systems/Logger.h"
#include "Systems/Window.h"

#include <SDL/SDL.h>
#include <iostream>
#include <chrono>
#include <Windows.h>

engine::Engine::~Engine() {
	SystemManager::GetInstance().Shutdown();
	CloseSDL();
}

int engine::Engine::Init() {
#if !_DEBUG
	Logger::SetCurrentLogLevel(ELogTypes::LT_Error);
#endif
	Logger::Log("Initializing Engine...");

	if (!InitSDL()) {
		return 1;
	}

	if (!SystemManager::GetInstance().Init())
		return 2;

	return 0;
}

void engine::Engine::Run() {
	bool quit = false;

	SDL_Event e;

	LARGE_INTEGER t;
	QueryPerformanceFrequency(&t);

	while (!quit) {
		const auto start = std::chrono::high_resolution_clock::now();

		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			default:
				break;
			}
		}

		SystemManager::GetInstance().Update();
		SystemManager::GetInstance().Draw();

		const auto end = std::chrono::high_resolution_clock::now();
		const auto durationMS = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

		std::cout << durationMS.count() << "us" << std::endl;
	}
}

bool engine::Engine::InitSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		Logger::Log("Failed to initialize SDL", ELogTypes::LT_Error);

		return false;
	}

	return true;
}

bool engine::Engine::CloseSDL() {
	SDL_Quit();

	return true;
}
