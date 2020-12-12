//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Renderers/Shapes/Circle.h"

Circle::Circle() {

}

Circle::~Circle() {

}

void Circle::Render(exEngineInterface& engine, Transform transform, exColor color) {

	Vector2 currentPosition = transform.GetPosition();
	exVector2 position = currentPosition.ConvertToEngineType();

	float radius = transform.GetScale().GetX();

	engine.DrawCircle(position, radius, color, layer);
}