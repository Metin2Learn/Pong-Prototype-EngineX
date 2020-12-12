//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Prefabs/Wall.h"
#include "Game/Private/GameObjects/Components/Collision/AABBCollider.h"

Wall::Wall()
{
	AABBCollider* collider = new AABBCollider(this);

	transform->SetScale(Vector2(800, 10));

	tag = "Wall";

	AddComponent(collider);
}

Wall::~Wall()
{

}