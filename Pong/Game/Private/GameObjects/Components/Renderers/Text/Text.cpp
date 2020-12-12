#include "Game/Private/GameObjects/Components/Renderers/Text/Text.h"
#include "Game/Private/GameObjects/Components/Transforms/Transform.h"
#include "Engine/Public/EngineInterface.h"
#include <algorithm>

Text::Text()
{
	text = "New Text";
	texts.push_back(this);
}

Text::~Text()
{
	texts.erase(std::remove(texts.begin(), texts.end(), this), texts.end());
}

void Text::Render(exEngineInterface& engine, Transform transform, exColor color)
{
	engine.DrawText(textID, transform.GetPosition().ConvertToEngineType(), text.c_str(), color, layer);
}


std::vector<Text*> Text::texts;