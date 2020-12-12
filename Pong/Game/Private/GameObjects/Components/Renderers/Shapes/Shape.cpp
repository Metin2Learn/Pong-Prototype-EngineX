//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Renderers/Shapes/Shape.h"


Shape::Shape()
{}

Shape::~Shape()
{

}

void Shape::SetLayer(int layer)
{
	this->layer = layer;
}