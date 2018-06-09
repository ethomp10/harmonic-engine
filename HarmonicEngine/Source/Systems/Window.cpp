#include "Systems/Window.h"
#include "Systems/Logger.h"

#include <SDL/SDL.h>
#include <GL/glew.h>

namespace engine {
	Window::Window() : System(ESystemType::ST_WINDOW) {

	}

	Window::~Window() {

	}

	bool Window::Init() {
		InitSDL();

		m_window = SDL_CreateWindow("Harmonic Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		if (!m_window) {
			Logger::Log("Failed to create window", ELogTypes::LT_Error);
		}

		// GL stuff
		SDL_GLContext glContext = SDL_GL_CreateContext(m_window);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		return true;
	}

	void Window::Update() {
		SDL_GL_SwapWindow(m_window);
	}

	void Window::Draw() const {

	}

	bool Window::Shutdown() {
		return ShutdownSDL();
	}

	bool Window::InitSDL() {
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			Logger::Log("Failed to initialize SDL", ELogTypes::LT_Error);

			return false;
		}

		// Disable Vsync
		SDL_GL_SetSwapInterval(0);

		return true;
	}

	bool Window::ShutdownSDL() {
		SDL_FreeSurface(m_surface);
		m_surface = nullptr;

		SDL_DestroyWindow(m_window);
		m_window = nullptr;

		SDL_Quit();

		return true;
	}
}
