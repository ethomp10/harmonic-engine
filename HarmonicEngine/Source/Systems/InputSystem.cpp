#include "Systems/InputSystem.h"

#include <SDL/SDL.h>

namespace engine {
	InputSystem::InputSystem() : m_shouldClose(false), System(ESystemType::ST_INPUT) {

	}

	InputSystem::~InputSystem() {

	}

	bool InputSystem::Init() {
		return true;
	}

	void InputSystem::Update() {
		SDL_Event e;

		m_previousKeys = m_keys;

		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				m_shouldClose = true;
				break;
			case SDL_KEYDOWN:
				m_keys[e.key.keysym.sym] = true;
				break;
			case SDL_KEYUP:
				m_keys[e.key.keysym.sym] = false;
				break;
			default:
				break;
			}
		}
	}

	void InputSystem::Draw() const {

	}

	bool InputSystem::Shutdown() {
		return true;
	}

	bool InputSystem::IsKey(unsigned __int32 k) {
		return m_keys[k];
	}

	bool InputSystem::WasKeyPressed(unsigned __int32 k) {
		return !m_previousKeys[k] && m_keys[k];
	}
	
	bool InputSystem::WasKeyReleased(unsigned __int32 k) {
		return m_previousKeys[k] && !m_keys[k];
	}
}
