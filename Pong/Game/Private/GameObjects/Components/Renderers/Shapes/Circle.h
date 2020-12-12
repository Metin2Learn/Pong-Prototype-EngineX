//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Renderers/Shapes/Shape.h"

//Includes the logic fro rendering a Circle
class Circle : public Shape {

public:
	Circle();
	~Circle();

	virtual void Render(exEngineInterface& engine, Transform transform, exColor color) override;
};