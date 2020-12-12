//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Renderers/IRenderable.h"

#include <string>
#include <vector>

class Text : public IRenderable
{
public:
	Text();
	~Text();

	static std::vector<Text*> texts;	//All the texts in the game

	std::string text;
	int textID;

	virtual void Render(exEngineInterface& engine, Transform transform, exColor color) override;
};