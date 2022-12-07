#pragma once

struct Vector2Int
{
	int x {}; 
	int y {};

	Vector2Int operator+(const Vector2Int& rhs) const noexcept { return Vector2Int(x + rhs.x, y + rhs.y); }
	Vector2Int operator-(const Vector2Int& rhs) const noexcept { return Vector2Int(x - rhs.x, y - rhs.y); };
	Vector2Int operator*(const Vector2Int& rhs) const noexcept { return Vector2Int(x * rhs.x, y * rhs.y); };
	Vector2Int operator/(const Vector2Int& rhs) const noexcept { return Vector2Int(x / rhs.x, y / rhs.y); };
	Vector2Int operator*(const int rhs) const noexcept { return Vector2Int(x * rhs, y * rhs); };
	Vector2Int operator/(const int rhs) const noexcept { return Vector2Int(x / rhs, y / rhs); };

	bool operator==(const Vector2Int& rhs) const noexcept { return (this->x == rhs.x && this->y == rhs.y); };

};