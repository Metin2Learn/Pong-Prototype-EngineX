//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/GameObjects/Components/Collision/CollisionData.h"

CollisionData::CollisionData() {

}

CollisionData::~CollisionData() {

}

void CollisionData::SetOther(Collider* collider) {

	other = collider;
}

Collider& CollisionData::GetOther() const {

	return *other;
}