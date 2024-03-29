#pragma once
#include "SDL_keycode.h"
#include "Window.h"
#include "Renderer.h"
#include "SDL_System.h"
#include "Apple.h"
#include "Player.h"
#include "Utils.h"
#include "Config.h"

bool is_out_of_bounds(Position position_, Position bounds_) noexcept;
bool is_colliding(Position pos1_, Position pos2_) noexcept;
Position get_randomized_position() noexcept;

class Game {
public:
	void run() noexcept;
private:
	void poll_events() noexcept;
	void update() noexcept;
	void collision_check() noexcept;
	void render() const noexcept;
	void on_key_down(SDL_Keycode key_) noexcept;
private:
	bool is_running = true;
	Player player{ get_randomized_position() };
	Apple apple{ get_randomized_position() };

	SDL_System system{ SDL_INIT_EVERYTHING };
	Window window{ Config::TITLE.data(), Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT };
	Renderer renderer{ window };
};