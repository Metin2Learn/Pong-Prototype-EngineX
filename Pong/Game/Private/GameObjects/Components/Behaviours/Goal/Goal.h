//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Behaviours/BehaviourScript.h"
#include "Game/Private/DesignPatterns/Observer/Notifier.h"

class Goal : public BehaviourScript, public Notifier
{
public:
	Goal(GameObject* gameObject, std::string id);
	~Goal();

	virtual void OnTrigger(Collider& other) override;
	virtual ComponentType GetType() const override;

private:
	std::string id;
};