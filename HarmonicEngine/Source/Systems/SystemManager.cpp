#include "Systems/SystemManager.h"

namespace engine {
	SystemManager::SystemManager() {
		m_systems.emplace_back(new Window);
		m_systems.emplace_back(new Graphics);
		m_systems.emplace_back(new InputSystem);
	}

	SystemManager::~SystemManager() {
		for (System* s : m_systems) {
			delete s;
			s = nullptr;
		}

		m_systems.clear();
	}

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
