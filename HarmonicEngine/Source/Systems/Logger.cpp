#include "Systems/Logger.h"
#include <iostream>

namespace engine {
	void Logger::Log(const char* message, ELogTypes l) {
		if (l >= Logger::GetInstance().m_currentLevel)
			std::cout << message << std::endl;
	}

	ELogTypes Logger::GetCurrentLogLevel() {
		return Logger::GetInstance().m_currentLevel;
	}

	void Logger::SetCurrentLogLevel(ELogTypes l) {
		Logger::GetInstance().m_currentLevel = l;
	}
}
 