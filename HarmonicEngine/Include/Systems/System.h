#pragma once

#include "Singleton.h"

namespace engine {
	enum class ESystemType : unsigned __int8 {
		ST_WINDOW,
		ST_INPUT,
		ST_GRAPHICS,
		ST_TOTAL_SYSTEMS
	};

	class System {
		ESystemType m_type;
	public:
		System(ESystemType t) : m_type(t) {}
		virtual ~System() {}

		virtual bool Init() {
			return true;
		}
		virtual void Update() {}
		virtual void Draw() const {}
		virtual bool Shutdown() {
			return true;
		}
	};
}
