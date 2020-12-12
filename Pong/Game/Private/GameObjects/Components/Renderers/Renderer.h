//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Component.h"
#include "Engine/Public/EngineInterface.h"

#include <vector>

class IRenderable;
class Shape;

//Renders a shape on the screen
class Renderer : public Component
{
public:
	Renderer(GameObject* gameObject);
	virtual ~Renderer();

	static std::vector<Renderer*> renderers;

	void Render(exEngineInterface& engine);

	void SetRenderable(IRenderable* shape);
	void SetColor(exColor shape);

	virtual ComponentType GetType() const override;

	virtual void Initialize() override;
	virtual void Destroy() override;

private:

	exColor color;
	IRenderable* renderable;
};