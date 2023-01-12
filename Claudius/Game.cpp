#include <algorithm>
#include <cstdlib>

#include "Game.h"

bool is_colliding(Position pos1_, Position pos2_) noexcept {
	if (pos1_.x == pos2_.x && pos1_.y == pos2_.y) { return true; }
	else return false;
}

bool is_colliding_with_self(Position player_, std::vector<Position> body_parts_) noexcept {
	auto collidedPart = std::find_if(body_parts_.begin() + 1, body_parts_.end(), [&](Position part) noexcept {
		return is_colliding(player_, part); });
	return (collidedPart != body_parts_.end() ? true : false);
}

bool is_out_of_bounds(Position position_, Position bounds_) noexcept {
	if (position_.x > bounds_.x || position_.x < 0) { return true; }
	else if (position_.y > bounds_.y || position_.y < 0) { return true; }
	else return false;
}

inline Position get_randomized_position() noexcept {
	Position randomizedPosition{};
	randomizedPosition.x = std::rand() % (Config::WINDOW_WIDTH / TILE_SIZE) * TILE_SIZE;
	randomizedPosition.y = std::rand() % (Config::WINDOW_HEIGHT / TILE_SIZE) * TILE_SIZE;
	return randomizedPosition;
}

void Game::run() noexcept {
	while (is_running) {
		poll_events();
		update();
		render();

		SDL_Delay(50);
	}
}

void Game::poll_events() noexcept {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT: is_running = false; break;
		case SDL_KEYDOWN: on_key_down(e.key.keysym.sym); break;
		default: break;
		}
	}
}

void Game::update() noexcept {
	player.update();

	collision_check();
}

void Game::collision_check() noexcept
{
	if (is_out_of_bounds(player.get_position(), WINDOW_SIZE) ||
		is_colliding_with_self(player.get_position(), player.get_body_parts())) {
		player.reset(get_randomized_position());
	}
	else if (is_colliding(player.get_position(), apple.get_position())) {
		player.grow();
		apple.set_position(get_randomized_position());
	}
}

void Game::render() const noexcept {
	player.render(renderer);
	apple.render(renderer);

	renderer.present();
}

void Game::on_key_down(SDL_Keycode key_) noexcept {
	player.on_key_down(key_);
}