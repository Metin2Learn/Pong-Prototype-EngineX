//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Collision/Collider.h"
#include "Game/Private/GameObjects/Components/Behaviours/BehaviourScript.h"

Collider::Collider(GameObject* gameObject) 
	: Component(gameObject)
{
}

Collider::~Collider() 
{
	for (Collider* collider : colliders)
	{
		delete collider;
	}

	colliders.clear();
}

ComponentType Collider::GetType() const 
{
	return ComponentType::Collider;
}

void Collider::Initialize()
{
	AddToComponentVector(colliders);
}

void Collider::Destroy()
{
	RemoveFromComponentVector(colliders);
}

//Calling OnCollision on all the BehaviourScripts in this gameObject
void Collider::OnCollision(CollisionData& data)
{
	std::vector<BehaviourScript*>* behaviours = gameObject->GetComponents<BehaviourScript>();

	for (BehaviourScript* behaviour : *behaviours)
	{
		behaviour->OnCollision(data);
	}
	
	behaviours->clear();
	delete behaviours;
}

//Calling OnCollision on all the BehaviourScripts in this gameObject
void Collider::OnTrigger(Collider& other)
{
	GameObject& otherGO = other.GetGO();

	std::vector<BehaviourScript*>* behaviours = gameObject->GetComponents<BehaviourScript>();

	for (BehaviourScript* behaviour : *behaviours)
	{
		behaviour->OnTrigger(other);
	}

	behaviours->clear();
	delete behaviours;
}

std::vector<Collider*> Collider::colliders;