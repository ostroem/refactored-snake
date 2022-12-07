#pragma once

#include "Apple.h"
#include "RenderManager.h"

void Apple::Render(RenderManager& renderManager)
{
	renderManager.Render(position, rect, color);
}


