//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/GameObjects/Components/Transforms/Transform.h"
#include "Game/Private/DataStructures/Vector2.h"
#include "Game/Private/GameObjects/Components/Renderers/Renderer.h"
#include "Game/Private/GameObjects/Components/Renderers/IRenderable.h"

//Base class that handles polymorphic calls.
//Shapes are renderable and acts as a component of a GO
class Shape : public IRenderable
{

public:
	virtual void Render(exEngineInterface& engine, Transform transform, exColor color) override = 0;

	void SetLayer(int layer);

protected:
	Shape();

	virtual ~Shape();

	int layer;
};