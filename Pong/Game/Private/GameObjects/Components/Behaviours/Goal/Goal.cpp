//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Behaviours/Goal/Goal.h"
#include "Game/Private/GameObjects/Components/Collision/Collider.h"
#include "Game/Private/GameObjects/Components/Behaviours/Goal/GoalEvent.h"

Goal::Goal(GameObject* gameObject, std::string _id)
	: BehaviourScript(gameObject),
		id(_id)
{

}

Goal::~Goal()
{

}

ComponentType Goal::GetType() const
{
	return ComponentType::Goal;
}

void Goal::OnTrigger(Collider& other)
{
	//Notifies to the GameController that the ball has reached a goal
	if (other.GetGO().tag == "Ball")
	{
		GoalEvent* goalEvent = new GoalEvent(id);
		Notify(goalEvent);
	}
}