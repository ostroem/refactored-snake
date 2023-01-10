#pragma once
#include "SDL_keycode.h"

#include "Apple.h"
#include "Player.h"

class Game {
public:
	Game() = default;
	void run();
	void poll_events(bool& running);
public:
	void update();
	void render(Renderer& renderer) const noexcept;
	void on_key_down(SDL_Keycode key) noexcept;
	bool is_head_colliding_with_part();
	bool is_player_out_of_bounds();
private:
	Player player;
	Apple apple;
};