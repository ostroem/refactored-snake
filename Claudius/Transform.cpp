#include "Transform.h"

Transform::Transform(const Transform& rhs) : position(rhs.position)
{
}

Transform::Transform(int x, int y, int rotation) : position(x,y)
{
}

void Transform::SetPosition(const int x, const int y)
{
	position.x = x;
	position.y = y;
}

void Transform::ChangePosition(const int x, const int y)
{
	position.x += x;
	position.y += y;
}

Vector2Int Transform::GetPosition()
{
	return position;
}

int Transform::GetX()
{
	return position.x;
}

int Transform::GetY()
{
	return position.y;
}
