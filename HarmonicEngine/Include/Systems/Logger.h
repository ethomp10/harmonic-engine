#pragma once
#ifndef _LOGGER_H
#define _LOGGER_H

#include "Singleton.h"
#include "Utilities/EngineTypes.h"

namespace engine {
	class Logger : public Singleton<Logger> {
	private:
		// Allows singleton to access the protected constructor
		friend Singleton;
		ELogTypes m_currentLevel;
	protected:
		Logger() : m_currentLevel(ELogTypes::LT_General) {}
	public:
		static void Log(const char* message, ELogTypes l = ELogTypes::LT_General);
		static ELogTypes GetCurrentLogLevel();
		static void SetCurrentLogLevel(ELogTypes l);
	};
}

#endif // !_LOGGER_H
