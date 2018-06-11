#include "Resources/MeshData.h"

namespace engine {
	MeshData::MeshData(const std::vector<float>& verticies, const std::vector<int>& indicies) : m_verticies(verticies), m_indicies(indicies) {

	}

	MeshData::~MeshData() {
		m_verticies.clear();
		m_indicies.clear();
	}

	bool MeshData::Init() {
		return true;
	}

	bool MeshData::Shutdown() {
		return true;
	}
}
