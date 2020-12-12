//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/DataStructures/Vector2.h"


class Collider;

class CollisionData
{
public:
	CollisionData();
	~CollisionData();

	void SetOther(Collider* collider);
	Collider& GetOther() const;

	Vector2 collisionPoint;
	Vector2 normal;

private:
	Collider* other;
};