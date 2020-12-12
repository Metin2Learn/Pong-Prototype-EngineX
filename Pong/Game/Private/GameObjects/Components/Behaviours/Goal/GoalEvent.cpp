//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Behaviours/Goal/GoalEvent.h"

GoalEvent::GoalEvent(std::string _id)
	: id(_id)
{

}

GoalEvent::~GoalEvent()
{

}

std::string GoalEvent::GetID() const
{
	return id;
}