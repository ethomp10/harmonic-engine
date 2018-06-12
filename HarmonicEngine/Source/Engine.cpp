#include "Engine.h"

#include "Systems/SystemManager.h"
#include "Systems/Logger.h"
#include "Systems/Window.h"

#include "Resources/ShaderProgram.h"
#include "Resources/MeshData.h"

#include "Scene/GameObject.h"
#include "Scene/MeshComponent.h"

#include "../stbimage/stb_image.h"

#include <GL/glew.h>
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <vector>

const char* vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"layout (location = 1) in vec3 aColour;\n"
	"uniform mat4 transform;\n"
	"out vec3 ourColour;\n"
	"void main() {\n"
	"	gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"	ourColour = aColour;\n"
	"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
	"in vec3 ourColour;\n"
	"out vec4 fragColour;\n"
	"void main() {\n"
	"	fragColour = vec4(ourColour, 1.0f);\n"
	"}\0";

float verticies[] = {
	// Positions			// Colours
	0.5f, 0.5f, 0.0f,		0.5f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f,		0.0f, 0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 0.5f,
	-0.5f, 0.5f, 0.0f,		0.5f, 0.5f, 0.5f
};

unsigned indicies[] = {
	0, 1, 3,
	1, 2, 3
};

float texCoords[] = {
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f
};

engine::MeshData md (std::vector<float> (verticies, verticies + sizeof(verticies) / sizeof(verticies[0])),
	std::vector<int> (indicies, indicies + sizeof(indicies) / sizeof(indicies[0])));
engine::ShaderProgram sp(vertexShaderSource, fragmentShaderSource);

engine::MeshComponent mc(&md, &sp);

engine::GameObject go;

int width, height, nrChannels;
unsigned char *data = stbi_load("wall.jpg", &width, &height, &nrChannels, 0);

engine::Engine::~Engine() {
	SystemManager::GetInstance().Shutdown();
}

int engine::Engine::Init() {
#if !_DEBUG
	Logger::SetCurrentLogLevel(ELogTypes::LT_Error);
#endif
	Logger::Log("Initializing Engine...");

	if (!SystemManager::GetInstance().Init())
		return 2;

	md.Init();
	sp.Init();

	mc.Init();

	go.AddComponent(&mc);

	return 0;
}

void engine::Engine::Run() {
	while (!SystemManager::GetInstance().GetSystem<InputSystem>()->WasCloseRequested()) {
		// Timing
		{
			static uint64_t frameCounter = 0;
			static double elapsedSeconds = 0.0;
			static std::chrono::high_resolution_clock clock;
			static auto t0 = clock.now();

			++frameCounter;
			auto t1 = clock.now();
			auto deltaTime = t1 - t0;
			t0 = t1;

			elapsedSeconds += deltaTime.count() * 1e-9;
			if (elapsedSeconds > 1.0) {
				char buffer[500];
				auto fps = frameCounter / elapsedSeconds;
				sprintf_s(buffer, 500, "FPS: %f\n", fps);

				std::cout << buffer << std::endl;

				frameCounter = 0;
				elapsedSeconds = 0.0;
			}
		}

		SystemManager::GetInstance().Update();
		go.Update();

		SystemManager::GetInstance().Draw();
		go.Draw();

		InputSystem* input = SystemManager::GetInstance().GetSystem<InputSystem>();

		if (input->WasKeyPressed(SDLK_SPACE)) {
			std::cout << "Pressing space" << std::endl;
		}

		if (input->IsKey(SDLK_w)) {
			go.Translate(0.0f, 0.0005f, 0.0f);
		}

		if (input->IsKey(SDLK_s)) {
			go.Translate(0.0f, -0.0005f, 0.0f);
		}

		if (input->IsKey(SDLK_a)) {
			go.Translate(-0.0005f, 0.0f, 0.0f);
		}

		if (input->IsKey(SDLK_d)) {
			go.Translate(0.0005f, 0.0f, 0.0f);
		}
	}
}
