#include "Scene/MeshComponent.h"
#include "Scene/GameObject.h"

#include "Resources/ShaderProgram.h"
#include "Resources/MeshData.h"
#include "Resources/Texture.h"

#include <GL/glew.h>

namespace engine {
	MeshComponent::MeshComponent(MeshData* md, ShaderProgram* sp, Texture* texture) :
	m_meshData(md), m_shaderProgram(sp), m_texture(texture) {

	}

	MeshComponent::~MeshComponent() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteVertexArrays(1, &VBO);
		glDeleteVertexArrays(1, &EBO);
	}

	bool MeshComponent::Init() {
		// Create buffers
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(m_meshData->GetVerticies()[0]) * m_meshData->GetVerticies().size(), m_meshData->GetVerticies().data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_meshData->GetIndicies()[0]) * m_meshData->GetIndicies().size(), m_meshData->GetIndicies().data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		m_texture->Init();
		glUniform1i(glGetUniformLocation(m_shaderProgram->GetID(), "texture1"), 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		return true;
	}

	void MeshComponent::Update() {
		unsigned int transformLoc = glGetUniformLocation(m_shaderProgram->GetID(), "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(m_parent->GetTransform()));
	}

	void MeshComponent::Draw() const {
		m_shaderProgram->Use();
		m_texture->Use();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	bool MeshComponent::Shutdown() {
		return true;
	}
}
