#pragma once

#include <vector>

#include "../../glm/glm.hpp"
#include "../../glm/gtc/matrix_transform.hpp"
#include "../../glm/gtc/type_ptr.hpp"

namespace engine {
	class GameObject {
		glm::vec4 m_position;
		glm::vec4 m_scale;
		glm::vec4 m_rotation;

		glm::mat4 m_transform;

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

		inline std::vector<class Component*> GetComponent() const { return m_components; }
		inline const glm::mat4& GetTransform() const { return m_transform; }

		void Translate(float x, float y, float z);
	};
}
