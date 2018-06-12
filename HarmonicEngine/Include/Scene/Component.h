#pragma once

namespace engine {
	class Component {
	protected:
		class GameObject* m_parent;
	public:
		Component() {};
		virtual ~Component() {};

		virtual bool Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() const = 0;
		virtual bool Shutdown() = 0;

		inline void SetParent(class GameObject* go) { m_parent = go; }
	};
}
