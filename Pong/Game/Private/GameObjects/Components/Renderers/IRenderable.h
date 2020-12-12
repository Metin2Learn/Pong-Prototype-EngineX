//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

class exEngineInterface;
class Transform;
struct exColor;

//The thing that the renderer renders. Could be a shape or text.
class IRenderable
{
public:
	virtual void Render(exEngineInterface& engine, Transform transform, exColor color) = 0;

	int layer;

protected:
	IRenderable()
	{

	}
	virtual ~IRenderable()
	{

	}
};