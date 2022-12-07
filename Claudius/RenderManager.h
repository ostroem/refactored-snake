#pragma once

#include <vector>
#include "Vector2Int.h"

struct Sprite;
struct Rectangle;
struct Color;

struct RenderManager
{
	struct RectEntry
	{
		Vector2Int position;
		Rectangle rect;
		Color color;
	};

	void Render(const Vector2Int& pos, const Rectangle& rect, const Color& color);
	void Clear();

	std::vector<RectEntry> rectEntries;
};
