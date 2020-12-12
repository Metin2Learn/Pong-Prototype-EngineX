//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Renderers/Shapes/Rectangle.h"

Rectangle::Rectangle() 
{
}

Rectangle::~Rectangle() 
{
}

void Rectangle::Render(exEngineInterface& engine, Transform transform, exColor color) 
{
	Vector2 position = transform.GetPosition();
	Vector2 scale = transform.GetScale();

	exVector2 center = position.ConvertToEngineType();

	exVector2 point1 = center;

	point1.x += scale.GetX();
	point1.y += scale.GetY();

	exVector2 point2 = center;

	point2.x -= scale.GetX();
	point2.y -= scale.GetY();

	engine.DrawBox(point1, point2, color, layer);
}