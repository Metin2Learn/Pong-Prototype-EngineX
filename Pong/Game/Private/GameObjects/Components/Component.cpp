//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Component.h"

Component::Component(GameObject* _gameObject)
	: gameObject(_gameObject)
{
}

Component::~Component()
{
}

GameObject& Component::GetGO() const
{
	return *gameObject;
}

void Component::Initialize()
{

}

void Component::Destroy()
{

}