#pragma once

#include "Resource.h"

#include <string>

namespace engine {
	class ShaderProgram : public Resource {
	private:
		int m_id;

		const char* m_vertexSource;
		const char* m_fragmentSource;
	public:
		ShaderProgram(const char* vertexSource, const char* fragmentSource);
		~ShaderProgram();

		bool Init() override;
		bool Shutdown() override;

		void Use();
	};
}
