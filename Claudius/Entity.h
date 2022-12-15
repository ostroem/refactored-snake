#pragma once
#include "Vector2Int.h"
#include "Color.h"
#include "SDL_rect.h"

struct Entity {
	Vector2Int position{};
	Color color{};
	SDL_Rect rect{};
};
