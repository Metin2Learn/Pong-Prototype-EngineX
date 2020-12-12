//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Prefabs/Paddle.h"
#include "Game/Private/GameObjects/Components/Renderers/Renderer.h"
#include "Game/Private/GameObjects/Components/Renderers/Shapes/Rectangle.h"
#include "Game/Private/GameObjects/Components/Collision/AABBCollider.h"

//Setting up paddle
Paddle::Paddle()
{
	Renderer* renderer = new Renderer(this);
	AABBCollider* collider = new AABBCollider(this);
	
	exColor color;
	color.mColor[0] = 200;
	color.mColor[1] = 0;
	color.mColor[2] = 0;
	color.mColor[3] = 255;

	renderer->SetColor(color);
	renderer->SetRenderable(new Rectangle());

	transform->SetScale(Vector2(25, 70));

	AddComponent(renderer);
	AddComponent(collider);

	tag = "Paddle";
}

Paddle::~Paddle()
{

}