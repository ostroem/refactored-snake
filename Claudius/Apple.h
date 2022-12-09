#pragma once

#include "Rectangle.h"
#include "Color.h"
#include "Vector2Int.h"

struct RenderManager; //<- Kinda like #include "RenderManager.h", not exactly. Can't use functions. Google forward declaration.

class Apple
{
public:
	void Render(RenderManager& renderManager);
	Vector2Int get_position() const noexcept { return position; }
	void set_position(int x, int y) noexcept { position.x = x; position.y = y; }



private:
	Rectangle rect { 0, 0, 10, 10 };
	Color color { 255, 0, 0, 0 };
	Vector2Int position { 0, 0 };

	bool new_apple = false;
};