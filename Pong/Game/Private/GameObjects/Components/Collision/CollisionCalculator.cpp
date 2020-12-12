//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Collision/CollisionCalculator.h"
#include "Game/Private/DataStructures/Vector2.h"
#include "Game/Private/GameObjects/Components/Transforms/Transform.h"
#include "Game/Private/Libraries/Math.h"
#include "Game/Private/GameObjects/Components/Collision/Collider.h"

//True if collides
bool CollisionCalculator::PointToCircle(Vector2 point, Collider& colliderA, bool needsData, CollisionData& data)
{
	Transform circleA = colliderA.GetGO().GetTransform();
	Vector2 posA = circleA.GetPosition();

	Vector2 dir;
	Vector2::SubstractVectors(dir, posA, point);

	float distance = dir.GetMagnitude();

	float radiusA = circleA.GetScale().GetX();

	bool result = distance <= radiusA;
	
	return result;
}

//True if collides
bool CollisionCalculator::PointToRectangle(Vector2 point, Collider& colliderA, bool needsData, CollisionData& data)
{
	Transform rectangleA = colliderA.GetGO().GetTransform();
	Vector2 position = rectangleA.GetPosition();
	Vector2 scale = rectangleA.GetScale();

	float xMinA = position.GetX() - scale.GetX();
	float xMaxA = position.GetX() + scale.GetX();
	float yMinA = position.GetY() - scale.GetY();
	float yMaxA = position.GetY() + scale.GetY();

	float x = point.GetX();
	float y = point.GetY();
	
	bool result = x >= xMinA && x <= xMaxA && y >= yMinA && y <= yMaxA;
	return result;
}

//True if collides
bool CollisionCalculator::CircleToCircle(Collider& colliderA, Collider& colliderB, bool needsData, CollisionData& data)
{
	Transform circleA = colliderA.GetGO().GetTransform();
	Transform circleB = colliderB.GetGO().GetTransform();

	Vector2 posA = circleA.GetPosition();
	Vector2 posB = circleB.GetPosition();

	Vector2 dir;
	Vector2::SubstractVectors(dir, posA, posB);

	float distance = dir.GetMagnitude();

	float radiusA = circleA.GetScale().GetX();
	float radiusB = circleB.GetScale().GetX();

	bool result = distance < radiusA + radiusB;

	return result;
}

//True if collides
bool CollisionCalculator::CircleToRectangle(Collider& colliderA, Collider& colliderB, bool needsData, CollisionData& data)
{
	Transform circleA = colliderA.GetGO().GetTransform(); 
	Vector2 positionA = circleA.GetPosition();
	Vector2 scaleA = circleA.GetScale();

	Transform rectangleB = colliderB.GetGO().GetTransform();
	Vector2 positionB = rectangleB.GetPosition();
	Vector2 scaleB = rectangleB.GetScale();

	Vector2 direction;
	Vector2::SubstractVectors(direction, positionA, positionB);
	
	float halfWidth = scaleB.GetX();
	float halfHeight = scaleB.GetY();
	
	float xMinB = positionB.GetX() - halfWidth;
	float xMaxB = positionB.GetX() + halfWidth;
	float yMinB = positionB.GetY() - halfHeight;
	float yMaxB = positionB.GetY() + halfHeight;

	Vector2 pos;
	Vector2::AddVectors(pos, positionB, direction);
	
	float clampedX = Math::Clamp(pos.GetX(), xMinB, xMaxB);
	float clampedY = Math::Clamp(pos.GetY(), yMinB, yMaxB);

	Vector2 clampedPoint(clampedX, clampedY);
	bool result = PointToCircle(clampedPoint, colliderA, needsData, data);

	if (result && (!colliderA.isTrigger && !colliderB.isTrigger))
	{
		data.collisionPoint = clampedPoint;
	}
	return result;
}

//True if collides
bool CollisionCalculator::RectangleToRectangle(Collider& colliderA, Collider& colliderB, bool needsData, CollisionData& data)
{
	Transform rectangleA = colliderA.GetGO().GetTransform();
	Transform rectangleB = colliderB.GetGO().GetTransform();

	Vector2 positionA = rectangleA.GetPosition();
	Vector2 scaleA = rectangleA.GetScale();

	float xMinA = positionA.GetX() - scaleA.GetX();
	float xMaxA = positionA.GetX() + scaleA.GetX();
	float yMinA = positionA.GetY() - scaleA.GetY();
	float yMaxA = positionA.GetY() + scaleA.GetY();

	Vector2 positionB = rectangleB.GetPosition();
	Vector2 scaleB = rectangleB.GetScale();

	float xMinB = positionB.GetX() - scaleB.GetX();
	float xMaxB = positionB.GetX() + scaleB.GetX();
	float yMinB = positionB.GetY() - scaleB.GetY();
	float yMaxB = positionB.GetY() + scaleB.GetY();

	bool result = PointToRectangle(Vector2(xMinB, yMinB), colliderA, needsData, data) 
		|| PointToRectangle(Vector2(xMinB, yMaxB), colliderA, needsData, data)
		|| PointToRectangle(Vector2(xMaxB, yMinB), colliderA, needsData, data) 
		|| PointToRectangle(Vector2(xMaxB, yMaxB), colliderA, needsData, data)
		|| PointToRectangle(Vector2(xMinA, yMinA), colliderB, needsData, data)
		|| PointToRectangle(Vector2(xMinA, yMaxA), colliderB, needsData, data)
		|| PointToRectangle(Vector2(xMaxA, yMinA), colliderB, needsData, data)
		|| PointToRectangle(Vector2(xMaxA, yMaxA), colliderB, needsData, data);

	return result;
}