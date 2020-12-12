//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Behaviours/Player/Player.h"

//Determines the input of the first player
class Player1 : public Player
{
public:
	Player1(GameObject* gameObject);
	virtual ~Player1();

	virtual void Awake() override;

	virtual ComponentType GetType() const override;

protected:
	virtual void ReadInput() override;
};