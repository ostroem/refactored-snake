#include <algorithm>

#include "Player.h"
#include "Config.h"

Player::Player(Position position_) noexcept {
	body_parts.push_back(position_);
}

void Player::update() noexcept {
	if (body_parts.size() > 1) {
		update_parts_position();
	}
	update_head_position();
}

void Player::update_parts_position() noexcept {
	std::shift_right(body_parts.begin(), body_parts.end(), 1);
}

void Player::update_head_position() noexcept {
	head().x += velocity.x;
	head().y += velocity.y;
}

Position& Player::head() noexcept {
	return body_parts.front();
}

void Player::on_key_down(SDL_Keycode key_) noexcept {
	switch (key_) {
	case SDLK_LEFT:
		velocity = {-TILE_SIZE, 0}; break;
	case SDLK_RIGHT:
		velocity = { TILE_SIZE, 0}; break;
	case SDLK_UP:
		velocity = {0, -TILE_SIZE }; break;
	case SDLK_DOWN:
		velocity = {0, TILE_SIZE }; break;
	default: break;
	}
}

void Player::grow() noexcept {
	body_parts.push_back(body_parts.back());
}

void Player::render(const Renderer& renderer_) const noexcept {
	std::ranges::for_each(body_parts, [&](Position bodypart) noexcept {
		renderer_.render(bodypart, SNAKE_COLOR); });
}

void Player::reset(Position position_) noexcept {
	head() = position_;
	body_parts.resize(1);
}

std::vector<Position> Player::get_body_parts() noexcept {
	return body_parts;
}

Position Player::get_position() const noexcept {
	return body_parts.front();
}