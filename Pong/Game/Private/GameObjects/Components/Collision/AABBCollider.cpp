//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Collision/AABBCollider.h"

AABBCollider::AABBCollider(GameObject* _gameObject) :
	Collider(_gameObject) {}

AABBCollider::~AABBCollider() {

}

ComponentType AABBCollider::GetType() const
{
	return ComponentType::AABBCollider;
}

void AABBCollider::CalculateCollision() 
{
	for (unsigned int i = 0; i < colliders.size(); i++)
	{
		Collider* currentCollider = colliders.at(i);

		//avoiding to check collision with itself or nullptr
		if (currentCollider == nullptr || currentCollider == this) continue;

		bool isColliding = false;
		bool otherIsTigger = currentCollider->isTrigger;

		CollisionData* data = new CollisionData();
		
		//Applying different collision ecuation depending on the types of the colliders
		switch (currentCollider->GetType())
		{
		case ComponentType::AABBCollider:

			isColliding = CollisionCalculator::RectangleToRectangle(*this, *currentCollider, !isTrigger, *data);

			break;

		case ComponentType::CircleCollider:

			isColliding = CollisionCalculator::CircleToRectangle(*currentCollider, *this, !isTrigger, *data);

			break;

		default:
			isColliding = false;
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

void AABBCollider::RemoveCollisionWith(Collider& other, CollisionData data)
{

}