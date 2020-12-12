//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/DesignPatterns/Observer/EventData.h"

#include <string>

//Object created each time a goal triggers collision
class GoalEvent : public EventData
{
public:
	GoalEvent(std::string id);
	~GoalEvent();

	std::string GetID() const;

private:
	std::string id;
};