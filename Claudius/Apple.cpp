#pragma once

#include "Apple.h"
#include "RenderManager.h"

Apple::Apple() noexcept {
	randomize_position();

	color = Color(255, 0, 0, 0);
	rect = { position.x, position.y, 10, 10 };
}

void Apple::render(RenderManager& renderManager) {
	renderManager.pushback_entries(position, rect, color);
}

void Apple::randomize_position() noexcept{
	position.x = rand() % 128 * 10;
	position.y = rand() % 72 * 10;
	rect.x = position.x;
	rect.y = position.y;

}

