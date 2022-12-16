#pragma once

#include "Apple.h"
#include "RenderManager.h"
#include "Config.h"

Apple::Apple() noexcept {
	randomize_position();
	constexpr int rectSize = 10;
	color = Color(255, 0, 0, 255);
	rect = { position.x, position.y, rectSize, rectSize };
}

void Apple::render(RenderManager& renderManager) {
	renderManager.pushback_entries(position, rect, color);
}

void Apple::randomize_position() noexcept{
	constexpr int denom = 10;
	position.x = rand() % (Config::window_width / denom) * denom;
	position.y = rand() % (Config::window_height / denom) * denom;
	rect.x = position.x;
	rect.y = position.y;

}

