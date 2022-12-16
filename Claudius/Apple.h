#pragma once

#include "Entity.h"
#include "RenderManager.h"

class Apple : public Entity {
public:
	Apple() noexcept;
	void render(RenderManager& renderManager);
	Vector2Int get_position() const noexcept { return position; }
	void randomize_position() noexcept;
};