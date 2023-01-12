#include <algorithm>

#include "Game.h"
#include "Config.h"
#include "Utils.h"

bool is_colliding(Position pos1_, Position pos2_) noexcept {
	if (pos1_.x == pos2_.x && pos1_.y == pos2_.y) {
		return true;
	}
	return false;
}

bool is_out_of_bounds(Position position_, Position bounds_) noexcept {
	if (position_.x > bounds_.x || position_.x < 0) {
		return true;
	}
	else if (position_.y > bounds_.y || position_.y < 0) {
		return true;
	}
	return false;
}

void Game::run() noexcept {
	bool running = true;

	while (running) {
		poll_events(running);
		update();
		render();

		SDL_Delay(50);
	}
}

void Game::poll_events(bool& running_) noexcept {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT: running_ = false; break;
		case SDL_KEYDOWN: on_key_down(e.key.keysym.sym); break;
		default: break;
		}
	}
}

void Game::update() noexcept {
	player.update();

	collision_check();
}

void Game::collision_check()
{
	if (is_out_of_bounds(player.get_position(), WINDOW_SIZE) ||
		is_player_self_colliding(player.get_position(), player.get_bodyparts())) {
		player.reset();
	}
	else if (is_colliding(player.get_position(), apple.get_position())) {
		apple.randomize_position();
		player.grow();
	}
}

bool Game::is_player_self_colliding(Position player_, std::vector<Position> bodyparts_) noexcept {
	auto collidedPart = std::find_if(bodyparts_.begin() + 1, bodyparts_.end(), [&](Position part) noexcept {
		return is_colliding(player_, part); });
	return (collidedPart != bodyparts_.end() ? true : false);
}

void Game::render() const noexcept {
	player.render(renderer);
	apple.render(renderer);

	renderer.present();
}

void Game::on_key_down(SDL_Keycode key_) noexcept {
	player.on_key_down(key_);
}