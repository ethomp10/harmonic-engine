#pragma once

#include "Systems/System.h"

// Forward declaration
struct SDL_Window;
struct SDL_Surface;

namespace engine {
	class Window : public System {
		SDL_Window* m_window;
		SDL_Surface* m_surface;
	public:
		Window();
		~Window();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
	};
}
