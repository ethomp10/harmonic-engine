#pragma once

#include "Systems/Singleton.h"

#include <unordered_map>

namespace engine {
	class Resource;
	
	class ResourceManager : public Singleton<ResourceManager> {
		std::unordered_map<std::string, Resource*> m_resources;
	protected:
		ResourceManager();
	public:
		~ResourceManager();

		void AddResource(std::string key, Resource* r);
		Resource* GetResource(std::string key);
	};
}
