#pragma once

#include "Vector2Int.h"

struct Transform
{
	Transform();
	Transform(const Transform& rhs);
	Transform(int x, int y, int rotation);
	
	void SetPosition(const int x, const int y);
	void ChangePosition(const int x, const int y);

	Vector2Int GetPosition();
	int GetX();
	int GetY();

	Vector2Int position;
};