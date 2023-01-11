#include <algorithm>

#include "Player.h"
#include "Renderer.h"
#include "Config.h"

Player::Player() noexcept {
	constexpr Position pos = { 300, 300 };
	parts.push_back(pos);
}

void Player::update() noexcept {
	if (parts.size() > 1) {
		update_parts_position();
	}
	update_head_position();
}

void Player::update_parts_position() noexcept {
	std::shift_right(parts.begin(), parts.end(), 1);
}

void Player::update_head_position() noexcept {
	head().x += velocity.x;
	head().y += velocity.y;
}

Position& Player::head() noexcept {
	return parts[0];
}

void Player::on_key_down(SDL_Keycode key) noexcept {
	switch (key) {
	case SDLK_LEFT:
		velocity = {-10, 0}; break;
	case SDLK_RIGHT:
		velocity = {10, 0}; break;
	case SDLK_UP:
		velocity = {0, -10}; break;
	case SDLK_DOWN:
		velocity = {0, 10}; break;
	default: break;
	}
}

void Player::grow() noexcept {
	parts.push_back(parts.back());
}

void Player::render(const Renderer& renderer) const noexcept {
	for(const auto& part : parts) {
		renderer.render(part, SNAKE_COLOR);
	}
}

void Player::reset() noexcept {
	parts[0] = { 300, 300 };
	parts.resize(1);
}

Position Player::get_position() const noexcept {
	return parts[0];
}

std::vector<Position>::iterator Player::get_parts_begin() noexcept {
	return parts.begin();
}

std::vector<Position>::iterator Player::get_parts_end() noexcept {
	return parts.end();
}

int Player::get_head_x() const noexcept {
	return parts[0].x;
}

int Player::get_head_y() const noexcept {
	return parts[0].y;
}