#include "Resources/Texture.h"

#include <GL/glew.h>

namespace engine {
	Texture::Texture(const char* texturePath) {
		glGenTextures(1, &m_id);
	}
	Texture::~Texture() {

	}

	bool Texture::Init() {
		return true;
	}

	bool Texture::Shutdown() {
		return true;
	}

	void Texture::Use() {
		glBindTexture(GL_TEXTURE_2D, m_id);
	}
}
