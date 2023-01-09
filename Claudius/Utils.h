#pragma once
#include "Color.h"

struct EntityPart {
	int x{};
	int y{};
};

static constexpr Color snake_color = Color(0, 255, 0, 255);
static constexpr Color apple_color = Color(255, 0, 0, 255);