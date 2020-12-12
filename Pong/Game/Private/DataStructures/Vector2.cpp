//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#include "Vector2.h"
#include "Engine/Public/EngineTypes.h"

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float _x, float _y) :
	x(_x), 
	y(_y) {}

Vector2::~Vector2() {

}

float Vector2::GetX() const {

	return x;
}

void Vector2::SetX(float value) {

	x = value;
}

float Vector2::GetY() const {

	return y;
}

void Vector2::SetY(float value) {

	y = value;
}

float Vector2::GetMagnitude() const {

	return sqrt((x * x) + (y * y));
}

void Vector2::Normalize() {
	
	float magnitude = GetMagnitude();

	x /= magnitude;
	y /= magnitude;
}

exVector2 Vector2::ConvertToEngineType() {
	
	exVector2 vector;
	vector.x = x;
	vector.y = y;

	return vector;
}

void Vector2::AddVectors(Vector2& out, const Vector2 vectorA, const Vector2 vectorB) {

	out.SetX(vectorA.GetX() + vectorB.GetX());
	out.SetY(vectorA.GetY() + vectorB.GetY());
}

void Vector2::SubstractVectors(Vector2& out, const Vector2 vectorA, const Vector2 vectorB) {

	out.SetX(vectorA.GetX() - vectorB.GetX());
	out.SetY(vectorA.GetY() - vectorB.GetY());
}

void Vector2::MultiplyScalar(Vector2& out, const Vector2 vector, const float scalar) {

	out.SetX(vector.GetX() * scalar);
	out.SetY(vector.GetY() * scalar);
}

float Vector2::Dot(const Vector2 vectorA, const Vector2 vectorB) {

	return ((vectorA.GetX() * vectorB.GetX()) + (vectorA.GetY() * vectorB.GetY()));
}

//VALUE MUST BE WITHIN 0 AND 1
void Vector2::Lerp(Vector2& out, const Vector2 A, const Vector2 B, float value) {

	float AValue = 1 - value;
	float BValue = 1 - AValue;

	Vector2 AMultiplier;
	Vector2::MultiplyScalar(AMultiplier, A, AValue);

	Vector2 BMultiplier;
	Vector2::MultiplyScalar(BMultiplier, B, BValue);

	Vector2 result;
	Vector2::AddVectors(result, AMultiplier, BMultiplier);

	out.SetX(result.GetX());
	out.SetY(result.GetY());
}