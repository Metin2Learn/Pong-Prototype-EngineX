//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Collision/CollisionData.h"

class Vector2;
class Transform;
class Collider;

class CollisionCalculator
{
public:
	//All collision cases required for the game
	static bool PointToCircle(Vector2 point, Collider& circleA, bool needsData, CollisionData& data);
	static bool PointToRectangle(Vector2 point, Collider& rectangleA, bool needsData, CollisionData& data);
	static bool CircleToCircle(Collider& circleA, Collider& circleB, bool needsData, CollisionData& data);
	static bool CircleToRectangle(Collider& circleA, Collider& rectangleB, bool needsData, CollisionData& data);
	static bool RectangleToRectangle(Collider& rectangleA, Collider& rectangleB, bool needsData, CollisionData& data);

private:
	CollisionCalculator() {

	}
	~CollisionCalculator() {

	}

};