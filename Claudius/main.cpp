#include "SDL.h"
#include "RenderManager.h"
#include "Game.h"

#undef main

int main()
{
	Game{}.run();
	return 0;
}
