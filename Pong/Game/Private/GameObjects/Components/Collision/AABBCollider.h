//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Collision/Collider.h"

class AABBCollider : public Collider {

public:
	//The transform of the game object that holds the collider
	AABBCollider(GameObject* gameObject);
	virtual ~AABBCollider();

	virtual ComponentType GetType() const override;

	//Returns data of the collision int data
	virtual void CalculateCollision() override;
	virtual void RemoveCollisionWith(Collider& other, CollisionData data) override;

};