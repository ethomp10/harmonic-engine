#pragma once

namespace engine {
	class Component {
	public:
		Component() {};
		virtual ~Component() {};

		virtual bool Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() const = 0;
		virtual bool Shutdown() = 0;
	};
}
