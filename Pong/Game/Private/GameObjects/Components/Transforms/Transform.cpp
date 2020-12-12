//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Transform.h"
#include "Game/Private/DataStructures/Vector2.h"

Transform::Transform(GameObject* _gameObject) 
	: Component(_gameObject)
{

	position = new Vector2();
	scale = new Vector2();
}

Transform::~Transform() 
{

}

Vector2 Transform::GetPosition() const 
{
	return *position;
}

void Transform::SetPosition(Vector2 position) 
{
	*this->position = position;
}

Vector2 Transform::GetScale() const 
{
	return *scale;
}

void Transform::SetScale(Vector2 scale) 
{
	*this->scale = scale;
}

ComponentType Transform::GetType() const
{
	return ComponentType::Transform;
}