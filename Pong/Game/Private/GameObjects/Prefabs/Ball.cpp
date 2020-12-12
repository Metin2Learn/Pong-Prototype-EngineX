//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Prefabs/Ball.h"
#include "Game/Private/GameObjects/Components/Renderers/Renderer.h"
#include "Game/Private/GameObjects/Components/Behaviours/Ball/BallMovement.h"
#include "Game/Private/GameObjects/Components/Renderers/Shapes/Circle.h"
#include "Game/Private/GameObjects/Components/Collision/CircleCollider.h"

Ball::Ball()
{
	Renderer* renderer = new Renderer(this);
	BallMovement* ballMovement = new BallMovement(this);
	CircleCollider* circleCollider = new CircleCollider(this);
	circleCollider->isTrigger = false;

	transform->SetScale(Vector2(25, 25));

	exColor color;
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
	color.mColor[3] = 255;

	renderer->SetColor(color);
	renderer->SetRenderable(new Circle());

	AddComponent(renderer);
	AddComponent(ballMovement);
	AddComponent(circleCollider);

	tag = "Ball";
}

Ball::~Ball()
{

}