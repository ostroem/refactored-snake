#pragma once

#include "Vector2Int.h"

struct Transform
{
	Transform(const Transform& rhs);
	Transform(float x, float y, float rotation);
	
	void SetPosition(const float x, const float y);
	void ChangePosition(const float x, const float y);
	void SetRotation(const float rotation);
	void ChangeRotation(const float rotation);

	Vector2Int GetPosition();
	float GetX();
	float GetY();
	float GetRotation();

	Vector2Int position;
	float rotation;
};