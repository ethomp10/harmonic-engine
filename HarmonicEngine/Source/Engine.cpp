#include "Engine.h"
#include "Systems/Logger.h"

int engine::Engine::init()
{
#if !_DEBUG
	Logger::SetCurrentLogLevel(ELogTypes::LT_Error);
#endif
	Logger::Log("Initializing Engine...");

	return 0;
}

void engine::Engine::run()
{
}
