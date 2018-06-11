#pragma once

#include "System.h"

#include <map>
#include <SDL/SDL.h>

namespace engine {
	class InputSystem : public System {
		bool m_shouldClose;

		std::map<unsigned __int32, bool> m_keys;
		std::map<unsigned __int32, bool> m_previousKeys;
	public:
		InputSystem();
		~InputSystem();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		bool IsKey(unsigned __int32 k);
		bool WasKeyPressed(unsigned __int32 k);
		bool WasKeyReleased(unsigned __int32 k);

		inline bool WasCloseRequested() const { return m_shouldClose; }
	};
}
