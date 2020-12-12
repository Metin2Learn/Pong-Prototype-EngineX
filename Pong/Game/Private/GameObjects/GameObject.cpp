//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/GameObject.h"
#include <algorithm>


GameObject::GameObject()
{
	gameObjects.push_back(this);
	components = new std::vector<Component*>();

	//I don't add it to the components vector because I don't want to be able to delete the Transform from the GO
	transform = new Transform(this);
}

GameObject::~GameObject()
{
	gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), this), gameObjects.end());

	for (Component* component : *components)
	{
		component->Destroy();

		delete component;
	}

	components->clear();
	delete components;
	delete transform;
}

void GameObject::Initialize()
{
	for (Component* component : *components)
	{
		component->Initialize();
	}
}

Transform& GameObject::GetTransform() const
{
	return *transform;
}

void GameObject::AddComponent(Component* component)
{
	components->push_back(component);
}

std::vector<GameObject*> GameObject::gameObjects;