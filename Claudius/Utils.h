#pragma once
#include "Color.h"

struct Position {
	int x{};
	int y{};
};

static constexpr Position WINDOW_SIZE { Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT };

static constexpr int TILE_SIZE = 10;
static constexpr Color SNAKE_COLOR = Color(0, 255, 0, 255);
static constexpr Color APPLE_COLOR = Color(255, 0, 0, 255);