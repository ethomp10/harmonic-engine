#pragma once

#include "Systems/System.h"

namespace engine {
	class Graphics : public System {
	public:
		Graphics();
		~Graphics();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
	private:
		bool InitOpenGL();
		bool ShutdownOpenGL();
	};
}
