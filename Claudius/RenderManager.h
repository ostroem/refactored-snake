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

	void pushback_entries(const Vector2Int& pos, const SDL_Rect& rect, const Color& color);
	void clear();

	std::vector<RectEntry> rectEntries;
};
