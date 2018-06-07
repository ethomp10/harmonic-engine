#include "Systems/SystemManager.h"

namespace engine {
	bool SystemManager::Init() {
		for (System* s : m_systems) {
			if (!s->Init())
				return false;
		}

		return true;
	}

	void SystemManager::Update() {
		for (System* s : m_systems) {
			s->Update();
		}
	}
	 
	void SystemManager::Draw() const {
		for (System* s : m_systems) {
			s->Draw();
		}
	}

	bool SystemManager::Shutdown() {
		for (System* s : m_systems) {
			if (!s->Shutdown())
				return false;
		}

		return true;
	}
}
