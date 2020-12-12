//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/ComponentType.h"

#include <vector>
#include <algorithm>

class GameObject;

class Component
{
public:

	Component(GameObject* gameObject);
	virtual ~Component();

	virtual ComponentType GetType() const = 0;
	GameObject& GetGO() const;

	virtual void Initialize();
	virtual void Destroy();

protected:

	template<class T>
	void AddToComponentVector(std::vector<T*>& componentVector)
	{
		componentVector.push_back((T*)this);
	}

	template<class T>
	void RemoveFromComponentVector(std::vector<T*>& componentVector)
	{
		componentVector.erase(std::remove(componentVector.begin(), componentVector.end(), this), componentVector.end());
	}

protected:
	GameObject* gameObject;
};