//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Behaviours/Player/Player.h"

//Determines the input of the second player
class Player2 : public Player
{
public:
	Player2(GameObject* gameObject);
	virtual ~Player2();

	virtual void Awake() override;

	virtual ComponentType GetType() const override;

protected:
	virtual void ReadInput() override;
};