#pragma once
#include "SDL_keycode.h"

#include "Apple.h"
#include "Player.h"

class Game {
public:
	Game() = default;
	void run();
public:
	void update();
	void render(Renderer& renderer) const noexcept;
	void on_key_down(SDL_Keycode key) noexcept;

private:
	Player player;
	Apple apple;
};