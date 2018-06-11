#pragma once

#include <vector>

namespace engine {
	class GameObject {
		std::vector<GameObject*> m_children;
		std::vector<class Component*> m_components;
	public:
		GameObject();
		virtual ~GameObject();

		virtual bool Init();
		virtual void Update();
		virtual void Draw() const;
		virtual bool Shutdown();

		void AddChildObject(GameObject* go);
		inline std::vector<GameObject*> GetChildren() const { return m_children; }

		void AddComponent(class Component* c);

		template <class T>
		T* GetComponent() const {
			for (class Component* c : m_components) {
				T* comp = dynamic_cast<T*>(c);

				if (comp)
					return comp;
			}

			return nullptr;
		}

		std::vector<class Component*> GetComponent() const { return m_components; }
	};
}
