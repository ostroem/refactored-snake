#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"
#include "SDL_keycode.h"
#include "RenderManager.h"

class Game
{
public:
	Game() = default;
	void run();
private:
	bool Enter();
	void Update();
	void Render(RenderManager& rendererManager);
	void OnKeyDown(SDL_Keycode key);

public:
	std::string name;
	int width { 0 };
	int height { 0 };
	int score { 0 };

private:
	Player player;
	Apple apple;
};