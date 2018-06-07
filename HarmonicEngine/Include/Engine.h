#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H

namespace engine {
	class Engine {
	public:
		~Engine();

		int Init();
		void Run();
	private:
		bool InitSDL();
		bool CloseSDL();
	};
}

#endif // !_ENGINE_H
