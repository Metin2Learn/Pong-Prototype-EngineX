//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

template<typename T>
class Singleton {

public:

	static void CreateInstance() {

		if (instance == nullptr) {

			instance = new T();
		}
	}

	static void DestroyInstance() {

		delete instance;
		instance = nullptr;
	}

	static T* GetInstance() {

		return instance;
	}

protected:
	Singleton() {

	}

	virtual ~Singleton() {

	}

private:
	static T* instance;
};