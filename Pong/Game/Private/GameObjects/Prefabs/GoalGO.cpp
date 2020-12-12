//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Prefabs/GoalGO.h"
#include "Game/Private/GameObjects/Components/Transforms/Transform.h"
#include "Game/Private/GameObjects/Components/Behaviours/Goal/Goal.h"
#include "Game/Private/GameObjects/Components/Collision/AABBCollider.h"

GoalGO::GoalGO(std::string id)
{
	Goal* goal = new Goal(this, id);
	AABBCollider* collider = new AABBCollider(this);
	collider->isTrigger = true;

	transform->SetScale(Vector2(20, 600));

	AddComponent(goal);
	AddComponent(collider);
}

GoalGO::~GoalGO()
{

}