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
	void poll_events(bool& running_) noexcept;
public:
	void update() noexcept;
	void collision_check() noexcept;
	void render() const noexcept;
	void on_key_down(SDL_Keycode key_) noexcept;
private:
	Player player{ };
	Apple apple{};

	SDL_System system{ SDL_INIT_EVERYTHING };
	Window window{ Config::TITLE.data(), Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT };
	Renderer renderer{ window };
};