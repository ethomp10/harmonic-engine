#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H

struct SDL_Window;
struct SDL_Surface;

namespace engine {
	class Engine {
		SDL_Window* m_window;
		SDL_Surface* m_surface;
	public:
		~Engine();

		int Init();
		void Run();
	private:
		void InitSDL();
		void CloseSDL();
	};
}

#endif // !_ENGINE_H
