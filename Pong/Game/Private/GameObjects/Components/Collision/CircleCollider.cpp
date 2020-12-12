//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Collision/CircleCollider.h"

CircleCollider::CircleCollider(GameObject* gameObject) :
	Collider(gameObject)
{
}

CircleCollider::~CircleCollider() 
{
}

ComponentType CircleCollider::GetType() const
{
	return ComponentType::CircleCollider;
}

//Same functionality than the AABB but this one applies other ecuations en diferent situations
void CircleCollider::CalculateCollision() 
{
	for (unsigned int i = 0; i < colliders.size(); i++)
	{
		Collider* currentCollider = colliders.at(i);

		if (currentCollider == nullptr || currentCollider == this) continue;
		
		bool isColliding = false;
		bool otherIsTigger = currentCollider->isTrigger;

		CollisionData* data = new CollisionData();

		ComponentType otherType = currentCollider->GetType();
		
		switch (otherType)
		{
		case ComponentType::AABBCollider:
			
			isColliding = CollisionCalculator::CircleToRectangle(*this, *currentCollider, !isTrigger, *data);
			
			break;

		case ComponentType::CircleCollider:

			isColliding = CollisionCalculator::CircleToCircle(*this, *currentCollider, !isTrigger, *data);
			
			break;

		default:
			break;
		}

		if (isColliding)
		{
			data->SetOther(currentCollider);

			if (isTrigger && !otherIsTigger)
			{
				OnTrigger(*currentCollider);
			}
			else if (!isTrigger && !otherIsTigger)
			{
				OnCollision(*data);
			}
		}
	}
}

void CircleCollider::RemoveCollisionWith(Collider& other, CollisionData data)
{
	Vector2 collisionPoint = data.collisionPoint;

	Vector2 gap;

	if (other.GetType() == ComponentType::AABBCollider)
	{

	}
	else if (other.GetType() == ComponentType::CircleCollider)
	{

	}
}