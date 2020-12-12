//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Component.h"
#include "Game/Private/GameObjects/Components/Transforms/Transform.h"
#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/GameObjects/Components/Collision/CollisionCalculator.h"
#include "Game/Private/GameObjects/Components/Collision/CollisionData.h"

#include <vector>

class Vector2;

//A collider class which allows inheritance to its childs.
//This allows me to use the other colliders functionality in a polymorphic way
class Collider : public Component {
	
public:
	static std::vector<Collider*> colliders;

	virtual void CalculateCollision() = 0;

	ComponentType GetType() const override;

	virtual void Initialize() override;
	virtual void Destroy() override;

	bool isTrigger;		//Determones if the collider allows overlapping
	
protected:
	void OnCollision(CollisionData& other);
	void OnTrigger(Collider& other);
	virtual void RemoveCollisionWith(Collider& other, CollisionData data) = 0;

	Collider(GameObject* gameObject);
	virtual ~Collider();

	//TODO: Add size independent of the scale
};