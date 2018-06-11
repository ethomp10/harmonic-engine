#pragma once

#include "Resource.h"

#include <vector>

namespace engine {
	class MeshData : public Resource {
		std::vector<float> m_verticies;
		std::vector<int> m_indicies;
	public:
		MeshData(const std::vector<float>& verticies, const std::vector<int>& indicies);
		~MeshData();

		bool Init() override;
		bool Shutdown() override;

		inline std::vector<float> GetVerticies() const { return m_verticies; }
		inline std::vector<int> GetIndicies() const { return m_indicies; }
	};
}
