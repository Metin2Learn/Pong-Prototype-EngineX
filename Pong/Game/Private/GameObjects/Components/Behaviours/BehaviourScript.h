//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include "Game/Private/GameObjects/Components/Component.h"
#include "Game/Private/GameObjects/Components/Transforms/Transform.h"
#include "Game/Private/GameObjects/GameObject.h"

#include <vector>

class Collider;
class CollisionData;

//Component that allows to create behavior on a specific GO
class BehaviourScript : public Component
{
public:

	static std::vector<BehaviourScript*> behaviours;

	virtual void Initialize() override;
	virtual void Destroy() override;

	virtual ComponentType GetType() const override = 0;

	virtual void Awake();	//Called at the begining of the game
	virtual void Start();	//Called just after Awake
	virtual void Update(float deltaTime);	//Called all frames

	virtual void OnTrigger(Collider& other);	//Called if the GO has a collider trigger and it is overlapping something
	virtual void OnCollision(CollisionData& collisionData);		//Called if the GO has a collider not trigger and it is overlapping something

protected:
	BehaviourScript(GameObject* gameObject);
	virtual ~BehaviourScript();
};