#pragma once
#ifndef _SINGLETON_H
#define _SINGLETON_H

namespace engine {
	template <class T>
	class Singleton {
	private:
		static T* m_instance;
	protected:
		// Protected constructor
		Singleton() {}
	public:
		static T& GetInstance() {
			if (m_instance) {
				return *m_instance;
			}

			m_instance = new T();

			return *m_instance;
		}
	};

	template <class T>
	T* Singleton<T>::m_instance = nullptr;
}

#endif // !_SINGLETON_H
