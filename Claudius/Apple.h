#pragma once

#include "Entity.h"
#include "RenderManager.h"

class Apple : public Entity {
public:
	void Render(RenderManager& renderManager);
	Vector2Int get_position() const noexcept { return position; }
	void set_position(int x, int y) noexcept { position.x = x; position.y = y; }

private:
	bool new_apple = false;
};