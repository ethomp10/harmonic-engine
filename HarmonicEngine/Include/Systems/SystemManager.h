#pragma once

#include "Singleton.h"
#include "Window.h"

#include <vector>
#include <algorithm>

namespace engine {
	class SystemManager : public Singleton<SystemManager> {
		friend Singleton;

		std::vector<class System*> m_systems;
	protected:
		SystemManager() {
			m_systems.emplace_back(new Window);
		}
	public:
		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();

		template<class T>
		T* GetSystem() const {
			/*System* s = std::find_if(m_systems.begin(), m_systems.end(), [T](System * s) -> bool {
				return dynamic_cast<T>(s) != nullptr;
			});*/

			for (System* s : m_systems) {
				T* currentSystem = dynamic_cast<T*>(s);
				if (currentSystem)
					return currentSystem;
			}

			return nullptr;
		}

		inline const std::vector<class System*>& GetSystems() const {
			return m_systems;
		}
	};
}
