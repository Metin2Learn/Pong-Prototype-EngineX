//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Behaviours/Ball/BallMovement.h"
#include "Game/Private/GameObjects/Components/Collision/CollisionData.h"
#include "Game/Private/GameObjects/Components/Collision/Collider.h"

BallMovement::BallMovement(GameObject* _gameObject)
	: BehaviourScript(_gameObject)
{

}

BallMovement::~BallMovement()
{

}

ComponentType BallMovement::GetType() const
{
	return ComponentType::BallMovement;
}

void BallMovement::Awake()
{
	Transform& transform = gameObject->GetTransform();;
	transform.SetPosition(Vector2(400, 300));


	direction = Vector2(-1, 0);
	speed = 250;
}

void BallMovement::Update(float deltaTime)
{
	Move(deltaTime);
}

void BallMovement::Move(float deltaTime)
{
	Transform transform = gameObject->GetTransform();
	Vector2 currentPosition = transform.GetPosition();

	Vector2 offset;

	offset.SetX(direction.GetX() * speed * deltaTime);
	offset.SetY(direction.GetY() * speed * deltaTime);

	Vector2 position;

	Vector2::AddVectors(position, currentPosition, offset);
	transform.SetPosition(position);
}

void BallMovement::OnCollision(CollisionData& data)
{
	std::string otherTag = data.GetOther().GetGO().tag;

	if (otherTag == "Paddle" || otherTag == "Wall")
	{
		//Setting up the reflection 
		Vector2 normal;
		Vector2::SubstractVectors(normal, gameObject->GetTransform().GetPosition(), data.collisionPoint);
		normal.Normalize();

		//direction = normal;
	
		normal.SetY(normal.GetY() * -1);
	
		float dot = Vector2::Dot(normal, direction);
		Vector2 scaledVector;
		Vector2::MultiplyScalar(scaledVector, normal, 2 * dot);

		Vector2 reflection;
		Vector2::SubstractVectors(reflection, direction, scaledVector);

		direction = reflection;
		speed += 10;	//Each time the ball collides with something, add speed
	}
}

void BallMovement::ModifyDirection(Vector2 amount)
{
	Vector2::AddVectors(direction, direction, amount);
	direction.Normalize();
}