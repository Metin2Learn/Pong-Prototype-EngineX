//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Behaviours/BehaviourScript.h"

BehaviourScript::BehaviourScript(GameObject* gameObject)
	: Component(gameObject)
{
}

BehaviourScript::~BehaviourScript()
{

}

void BehaviourScript::Initialize()
{
	AddToComponentVector(behaviours);
}

void BehaviourScript::Destroy()
{
	RemoveFromComponentVector(behaviours);
}

void BehaviourScript::Awake()
{

}

void BehaviourScript::Start()
{

}

void BehaviourScript::Update(float deltaTime)
{

}

void BehaviourScript::OnTrigger(Collider& other)
{

}

void BehaviourScript::OnCollision(CollisionData& collisionData)
{

}

std::vector<BehaviourScript*> BehaviourScript::behaviours;