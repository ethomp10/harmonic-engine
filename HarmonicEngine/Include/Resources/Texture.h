#pragma once

#include "Resource.h"

namespace engine {
	class Texture : public Resource {
	private:
		unsigned int m_id;
	public:
		Texture(const char* texturePath);
		~Texture();

		bool Init() override;
		bool Shutdown() override;

		void Use();

		inline unsigned int GetID() const { return m_id; }
	};
}
