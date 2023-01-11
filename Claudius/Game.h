#pragma once
#include "SDL_keycode.h"
#include "Window.h"
#include "Renderer.h"
#include "SDL_System.h"
#include "Apple.h"
#include "Player.h"

class Game {
public:
	void run();
	void poll_events(bool& running) noexcept;
public:
	void update() noexcept;
	void render() const noexcept;
	void on_key_down(SDL_Keycode key) noexcept;
	bool is_player_self_colliding() noexcept;
private:
	Player player;
	Apple apple;

	SDL_System system{ SDL_INIT_EVERYTHING };
	Window window{ Config::TITLE.data(), Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT };
	Renderer renderer{ window };
};