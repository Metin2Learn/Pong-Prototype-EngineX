//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Game/Private/Libraries/Math.h"

float Math::Clamp(float currentValue, float minValue, float maxValue) {
	if (currentValue < minValue) currentValue = minValue;
	if (currentValue > maxValue) currentValue = maxValue;

	return currentValue;
}