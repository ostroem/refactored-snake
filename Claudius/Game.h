#pragma once
#include "SDL_keycode.h"

#include "Apple.h"
#include "Player.h"

class Game {
public:
	Game() = default;
	void run();
	void poll_events(bool& running) noexcept;
public:
	void update() noexcept;
	void render(const Renderer& renderer) const noexcept;
	void on_key_down(SDL_Keycode key) noexcept;
	bool is_head_colliding_with_part() noexcept;
private:
	Player player;
	Apple apple;
};