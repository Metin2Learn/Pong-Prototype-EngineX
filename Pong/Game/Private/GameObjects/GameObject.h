//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Transforms/Transform.h"

#include <vector>

class Component;
enum class ComponentType;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	static std::vector<GameObject*> gameObjects;	//All gameObjects in the game

	std::string tag;	//A tag to recognize which gameObject is this

	virtual void Initialize();	//Initializes the components of the gameObject

	Transform& GetTransform() const;	//Transform of the gameObject

	void AddComponent(Component* component);	//Adds a component to the gameObject
	
	template<class T>
	T* GetComponent()	//Returns the component with the specified type
	{
		for (Component* component : *components)
		{
			T* out = dynamic_cast<T*>(component);
			if (out != nullptr)
			{
				return out;
			}
		}

		return nullptr;
	}
	
	template<class T>
	std::vector<T*>* GetComponents()	//Returns all the components with the specified type
	{
		std::vector<T*>* foundComponents = new std::vector<T*>();

		for (Component* component : *components)
		{
			T* out = dynamic_cast<T*>(component);
			if (out != nullptr)
			{
				foundComponents->push_back(out);
			}
		}

		return foundComponents;
	}

protected:
	std::vector<Component*>* components;	//All components in the gameObject
	Transform* transform;	//GameObject has a Transform as default because the GO occupies a position in the space
};