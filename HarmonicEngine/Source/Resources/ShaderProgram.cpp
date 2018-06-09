#include "Resources/ShaderProgram.h"

#include <iostream>
#include <GL/glew.h>

namespace engine {
	ShaderProgram::ShaderProgram(const char* vertexSource, const char* fragmentSource) : m_vertexSource(vertexSource), m_fragmentSource(fragmentSource) {
		
	}
	
	ShaderProgram::~ShaderProgram() {

	}

	bool ShaderProgram::Init() {
		// Compile vertex shaders
		int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &m_vertexSource, NULL);
		glCompileShader(vertexShader);

		int success;
		char infolog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
			std::cout << "Error compiling vertex shader: " << infolog << std::endl;
			
			return false;
		}

		// Compile fragment shader
		int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &m_fragmentSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
			std::cout << "Error compiling fragment shader: " << infolog << std::endl;

			return false;
		}

		// Create program to link shaders together
		m_id = glCreateProgram();
		glAttachShader(m_id, vertexShader);
		glAttachShader(m_id, fragmentShader);
		glLinkProgram(m_id);

		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_id, 512, NULL, infolog);
			std::cout << "Error linking shader program: " << infolog << std::endl;

			return false;
		}

		// Cleanup
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return true;
	}

	bool ShaderProgram::Shutdown() {
		return true;
	}

	void ShaderProgram::Use() {
		glUseProgram(m_id);
	}
}
