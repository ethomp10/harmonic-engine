#include "Engine.h"
#include "Systems/Logger.h"

#include <SDL/SDL.h>

engine::Engine::~Engine() {
	CloseSDL();
}

int engine::Engine::Init() {
#if !_DEBUG
	Logger::SetCurrentLogLevel(ELogTypes::LT_Error);
#endif
	Logger::Log("Initializing Engine...");

	InitSDL();

	return 0;
}

void engine::Engine::Run() {
}

void engine::Engine::InitSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		Logger::Log("Failed to initialize SDL", ELogTypes::LT_Error);
	} else {
		m_window = SDL_CreateWindow("Harmonic Engine", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

		if (!m_window) {
			Logger::Log("Failed to create window", ELogTypes::LT_Error);
		} else {
			m_surface = SDL_GetWindowSurface(m_window);
		}
	}
}

void engine::Engine::CloseSDL() {
	SDL_FreeSurface(m_surface);
	m_surface = nullptr;

	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	SDL_Quit();
}
