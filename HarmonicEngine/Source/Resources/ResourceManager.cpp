#include "Resources/ResourceManager.h"

namespace engine {
	ResourceManager::ResourceManager() {

	}

	ResourceManager::~ResourceManager() {

	}

	void ResourceManager::AddResource(std::string key, Resource* r) {
		m_resources[key] = r;
	}

	Resource * ResourceManager::GetResource(std::string key) {
		// Try to find key in map
		auto itr = m_resources.find(key);
		if (itr != m_resources.end()) {
			// If key was found, return the resource
			return m_resources[key];
		}

		// Return nullptr if the key wasn't found
		return nullptr;
	}
}
