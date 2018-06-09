#include "Engine.h"

#include "Systems/SystemManager.h"
#include "Systems/Logger.h"
#include "Systems/Window.h"

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <chrono>
#include <Windows.h>

engine::Engine::~Engine() {
	SystemManager::GetInstance().Shutdown();
}

int engine::Engine::Init() {
#if !_DEBUG
	Logger::SetCurrentLogLevel(ELogTypes::LT_Error);
#endif
	Logger::Log("Initializing Engine...");

	if (!SystemManager::GetInstance().Init())
		return 2;

	return 0;
}

void engine::Engine::Run() {
	bool quit = false;

	SDL_Event e;

	while (!quit) {
		// Timing
		{
			static uint64_t frameCounter = 0;
			static double elapsedSeconds = 0.0;
			static std::chrono::high_resolution_clock clock;
			static auto t0 = clock.now();

			++frameCounter;
			auto t1 = clock.now();
			auto deltaTime = t1 - t0;
			t0 = t1;

			elapsedSeconds += deltaTime.count() * 1e-9;
			if (elapsedSeconds > 1.0) {
				char buffer[500];
				auto fps = frameCounter / elapsedSeconds;
				sprintf_s(buffer, 500, "FPS: %f\n", fps);

				std::cout << buffer << std::endl;

				frameCounter = 0;
				elapsedSeconds = 0.0;
			}
		}

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

		glEnableClientState(GL_COLOR_ARRAY);

		// Draw triangle
		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0, 0);
		glVertex2f(0, 500);
		glVertex2f(500, 500);
		glEnd();
	}
}
