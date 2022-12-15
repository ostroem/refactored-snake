#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"
#include "SDL_keycode.h"
#include "RenderManager.h"

class Game {
public:
	Game() = default;
	void run();
public:
	bool enter();
	void update();
	void render(RenderManager& rendererManager);
	void on_key_down(SDL_Keycode key);

private:
	std::string name;
	int width { 1280 };
	int height { 720 };
	int score { };

private:
	Player player;
	Apple apple;
};