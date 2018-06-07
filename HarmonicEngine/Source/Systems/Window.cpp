#include "Systems/Window.h"
#include "Systems/Logger.h"
#include <SDL/SDL.h>

namespace engine {
	Window::Window() : System(ESystemType::ST_WINDOW) {

	}

	Window::~Window() {

	}

	bool Window::Init() {
		m_window = SDL_CreateWindow("Harmonic Engine", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

		if (!m_window) {
			Logger::Log("Failed to create window", ELogTypes::LT_Error);
		} else {
			m_surface = SDL_GetWindowSurface(m_window);
		}

		return true;
	}

	void Window::Update() {
		SDL_UpdateWindowSurface(m_window);
	}

	void Window::Draw() const {

	}

	bool Window::Shutdown() {
		SDL_FreeSurface(m_surface);
		m_surface = nullptr;

		SDL_DestroyWindow(m_window);
		m_window = nullptr;

		return true;
	}
}
