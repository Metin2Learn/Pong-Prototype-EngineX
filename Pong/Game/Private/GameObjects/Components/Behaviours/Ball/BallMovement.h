//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Behaviours/BehaviourScript.h"

class GameObject;

//Determines the behaviour of the ball
class BallMovement : public BehaviourScript
{
public:
	BallMovement(GameObject* gameObject);
	~BallMovement();

	virtual void Awake() override;
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(CollisionData& data) override;

	virtual ComponentType GetType() const override;

	void ModifyDirection(Vector2 amount);

	float speed;
private:
	void Move(float deltaTime);

	Vector2 direction;
};