#include <algorithm>

#include "Game.h"
#include "Window.h"
#include "Renderer.h"
#include "SDL_System.h"
#include "Config.h"
#include "Utils.h"

bool is_colliding(Position pos1, Position pos2) noexcept {
	if (pos1.x == pos2.x && pos1.y == pos2.y) {
		return true;
	}
	return false;
}

void Game::run() {
	SDL_System system{ SDL_INIT_EVERYTHING };
	Window window{};
	Renderer renderer{ window };
	bool running = true;

	while (running) {
		poll_events(running);
		update();
		render(renderer);

		SDL_Delay(50);
	}
}

void Game::poll_events(bool& running) noexcept {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT: running = false; break;
		case SDL_KEYDOWN: on_key_down(e.key.keysym.sym); break;
		default: break;
		}
	}
}


void Game::update() noexcept {
	player.update();

	if (is_head_colliding_with_part()) {
		player.reset();
	}
	if (is_player_out_of_bounds()) {
		player.reset();
	}
	if (is_colliding(player.get_position(), apple.get_position())) {
		apple.randomize_position();
		player.grow();
	}
}

bool Game::is_head_colliding_with_part() noexcept {
	auto isColliding = [&](Position part) {
		return is_colliding(player.get_position(), part); 
	};
	auto collidingObject = std::find_if(player.get_parts_begin() + 1, player.get_parts_end(), isColliding);
	return (collidingObject != player.get_parts_end() ? true : false);
}

bool Game::is_player_out_of_bounds() noexcept {
	if (player.get_head_x() > Config::WINDOW_WIDTH || player.get_head_x() < 0)
		return true;
	else if (player.get_head_y() > Config::WINDOW_HEIGHT || player.get_head_y() < 0)
		return true;

	return false;
}

void Game::render(const Renderer& renderer) const noexcept {
	player.render(renderer);
	apple.render(renderer);
	renderer.present();
}

void Game::on_key_down(SDL_Keycode key) noexcept {
	player.on_key_down(key);
}