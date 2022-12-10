#pragma once

struct Vector2Int
{
	int x {}; 
	int y {};

	Vector2Int operator+(const Vector2Int& rhs) noexcept { return Vector2Int(x + rhs.x, y + rhs.y); };
	Vector2Int operator-(const Vector2Int& rhs) noexcept { return Vector2Int(x - rhs.x, y - rhs.y); };
	Vector2Int operator*(const Vector2Int& rhs) noexcept { return Vector2Int(x * rhs.x, y * rhs.y); };
	Vector2Int operator/(const Vector2Int& rhs) noexcept { return Vector2Int(x / rhs.x, y / rhs.y); };
	Vector2Int& operator+=(const Vector2Int& rhs) noexcept { x += rhs.x; y += rhs.y; return *this; };
	Vector2Int& operator-=(const Vector2Int& rhs) noexcept { x -= rhs.x; y -= rhs.y; return *this; };

	bool operator==(const Vector2Int& rhs) const noexcept { return (this->x == rhs.x && this->y == rhs.y); };

};