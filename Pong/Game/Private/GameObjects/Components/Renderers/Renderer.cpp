//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Renderers/Renderer.h"
#include "Game/Private/GameObjects/Components/Transforms/Transform.h"
#include "Game/Private/GameObjects/Components/Renderers/Shapes/Shape.h"
#include "Game/Private/GameObjects/GameObject.h"
#include "Game/Private/GameObjects/Components/Renderers/IRenderable.h"

Renderer::Renderer(GameObject* _gameObject)
	: Component(_gameObject)
{
}

Renderer::~Renderer()
{

}

ComponentType Renderer::GetType() const
{
	return ComponentType::Renderer;
}

void Renderer::SetRenderable(IRenderable* shape)
{
	this->renderable = shape;
}

void Renderer::SetColor(exColor color)
{
	this->color = color;
}

void Renderer::Render(exEngineInterface& engine)
{
	Transform& transform = gameObject->GetTransform();

	renderable->Render(engine, transform, color);
}

void Renderer::Initialize()
{
	AddToComponentVector(renderers);
}

void Renderer::Destroy()
{
	RemoveFromComponentVector(renderers);
}

std::vector<Renderer*> Renderer::renderers;