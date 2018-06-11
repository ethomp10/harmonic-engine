#include "Scene/GameObject.h"
#include "Scene/Component.h"

namespace engine {
	GameObject::GameObject() {

	}

	GameObject::~GameObject() {

	}

	bool GameObject::Init() {
		return true;
	}

	void GameObject::Update() {
		for (Component* c : m_components) {
			c->Update();
		}

		for (GameObject* go : m_children) {
			go->Update();
		}
	}

	void GameObject::Draw() const {
		for (Component* c : m_components) {
			c->Draw();
		}

		for (GameObject* go : m_children) {
			go->Draw();
		}
	}

	bool GameObject::Shutdown() {
		return true;
	}

	void GameObject::AddChildObject(GameObject* go) {
		m_children.push_back(go);
	}

	void GameObject::AddComponent(class Component* c) {
		m_components.push_back(c);
	}
}
