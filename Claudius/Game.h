#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"
#include "SDL_keycode.h"

class Game {
public:
	Game() = default;
	void run();
public:
	void update();
	void render(Renderer& renderer);
	void on_key_down(SDL_Keycode key);

private:
	std::string name;
	int score { };

private:
	Player player;
	Apple apple;
};