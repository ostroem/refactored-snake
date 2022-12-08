#pragma once

#include <vector>
#include "Vector2Int.h"
#include "Rectangle.h"
#include "Color.h"

struct RenderManager
{
	struct RectEntry
	{
		Vector2Int position{};
		Rectangle rect{};
		Color color{};
	};

	void Render(const Vector2Int& pos, const Rectangle& rect, const Color& color);
	void Clear();

	std::vector<RectEntry> rectEntries;
};
