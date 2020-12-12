//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Behaviours/BehaviourScript.h"
#include "Engine/Public/SDL.h"

//Determines the behaviour of a player
class Player : public BehaviourScript
{
public:

	virtual void Update(float deltaTime) override;

	virtual void OnCollision(CollisionData& data) override;

	virtual ComponentType GetType() const = 0;

protected:
	Player(GameObject* gameObject);
	virtual ~Player();

	virtual void ReadInput() = 0;	//The input depends on the childrens
	virtual void Move(float deltaTime);

	float speed;
	float vertical;

	Vector2 lastPosition;
};