//Copyright (C) 2020, Nicolas Morales Escobar. All rights reserved.

#pragma once

#include <cmath>

struct exVector2;

//Vector class that let me customize its logic.
//A Vector2 can be translated to a exVector2
class Vector2
{
public:
	Vector2();
	Vector2(float _x, float _y);
	~Vector2();

	static void AddVectors(Vector2& out, const Vector2 vectorA, const Vector2 vectorB);
	static void SubstractVectors(Vector2& out, const Vector2 vectorA, const Vector2 vectorB);
	static void MultiplyScalar(Vector2& out, const Vector2 vector, const float scalar);
	static void Lerp(Vector2& out, const Vector2 A, const Vector2 B, float value);
	static float Dot(const Vector2 vectorA, const Vector2 vectorB);

	float GetX() const;
	void SetX(float value);

	float GetY() const;
	void SetY(float value);

	void Normalize();
	float GetMagnitude() const;
	
	exVector2 ConvertToEngineType();

private:
	float x;
	float y;
};