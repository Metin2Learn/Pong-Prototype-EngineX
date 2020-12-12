//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Collision/Collider.h"

class CircleCollider : public Collider
{
public:
	//The transform of the game object that holds the collider
	CircleCollider(GameObject* gameObject);
	virtual ~CircleCollider();

	virtual ComponentType GetType() const override;

	virtual void CalculateCollision() override;
	virtual void RemoveCollisionWith(Collider& other, CollisionData data) override;
};