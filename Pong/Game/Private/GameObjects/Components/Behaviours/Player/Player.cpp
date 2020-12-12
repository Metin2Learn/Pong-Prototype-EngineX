//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Behaviours/Player/Player.h"
#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/GameObjects/Components/Collision/CollisionData.h"
#include "Game/Private/GameObjects/Components/Collision/Collider.h"
#include "Game/Private/GameObjects/Components/Behaviours/Ball/BallMovement.h"

Player::Player(GameObject* gameObject)
	: BehaviourScript(gameObject)
{
	speed = 400;
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	ReadInput();
	Move(deltaTime);
}

void Player::Move(float deltaTime)
{
	Transform& transform = gameObject->GetTransform();
	Vector2 currentPosition = transform.GetPosition();
	lastPosition = currentPosition;

	Vector2 offset(0, vertical * speed * deltaTime);

	Vector2 position;

	Vector2::AddVectors(position, currentPosition, offset);

	transform.SetPosition(position);
}

void Player::OnCollision(CollisionData& data)
{
	GameObject& otherGO = data.GetOther().GetGO();

	//Prevents the paddles from overlapping the walls
	if (otherGO.tag == "Wall")
	{
		Transform& transform = gameObject->GetTransform();

		transform.SetPosition(lastPosition);
	}
	//Adds velocity to the ball based on the direction that the player is moving
	else if (otherGO.tag == "Ball")
	{
		BallMovement* ballMovement = otherGO.GetComponent<BallMovement>();
		ballMovement->ModifyDirection(Vector2(0, vertical * 0.4f));
	}
}