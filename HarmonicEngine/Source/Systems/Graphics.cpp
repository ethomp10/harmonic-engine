#include "Systems/Graphics.h"
#include "Systems/Logger.h"

#include <GL/glew.h>

namespace engine {
	Graphics::Graphics() : System(ESystemType::ST_GRAPHICS) {

	}

	Graphics::~Graphics() {

	}

	bool Graphics::Init() {
		return InitOpenGL();
	}

	void Graphics::Update() {
	}

	void Graphics::Draw() const {
		glClearDepth(1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Graphics::Shutdown() {
		return true;
	}

	bool Graphics::InitOpenGL() {
		GLenum error = glewInit();
		if (error != GLEW_OK) {
			Logger::Log("Glew failed to initialize", ELogTypes::LT_Error);

			return false;
		}

		// Background colour
		glClearColor(0.2f, 0.3f, 0.7f, 1.0f);

		return true;
	}

	bool Graphics::ShutdownOpenGL() {
		return true;
	}
}
