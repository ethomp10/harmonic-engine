#pragma once

#include "Component.h"

namespace engine {
	class MeshComponent : public Component {
		unsigned int VAO, VBO, EBO;
		class MeshData* m_meshData;
		class ShaderProgram* m_shaderProgram;
	public:
		MeshComponent(class MeshData* md, class ShaderProgram* sp);
		~MeshComponent();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
	};
}
