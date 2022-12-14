#pragma once

#include "Apple.h"
#include "RenderManager.h"

void Apple::Render(RenderManager& renderManager)
{
	renderManager.pushback_entries(position, rect, color);
}