#include <Engine.h>
#include <iostream>

int main(int argc, char* args[]) {
	engine::Engine e;
	
	if (e.Init() > 0) {
		return -1;
	}

	e.Run();

	return 0;
}
