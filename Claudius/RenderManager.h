#pragma once

#include <vector>
#include "Vector2Int.h"
#include "SDL_rect.h"
#include "Color.h"

struct RenderManager
{
	struct RectEntry
	{
		Vector2Int position{};
		SDL_Rect rect{};
		Color color{};
	};

	void Render(const Vector2Int& pos, const SDL_Rect& rect, const Color& color);
	void Clear();

	std::vector<RectEntry> rectEntries;
};
