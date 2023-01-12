#include <algorithm>

#include "Player.h"
#include "Renderer.h"
#include "Config.h"

Player::Player() noexcept {
	constexpr Position pos = { 300, 300 };
	bodyparts.push_back(pos);
}

void Player::update() noexcept {
	if (bodyparts.size() > 1) {
		update_parts_position();
	}
	update_head_position();
}

void Player::update_parts_position() noexcept {
	std::shift_right(bodyparts.begin(), bodyparts.end(), 1);
}

void Player::update_head_position() noexcept {
	head().x += velocity.x;
	head().y += velocity.y;
}

Position& Player::head() noexcept {
	return bodyparts[0];
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
	bodyparts.push_back(bodyparts.back());
}

void Player::render(const Renderer& renderer) const noexcept {
	std::ranges::for_each(bodyparts, [&](Position p) noexcept {
		renderer.render(p, SNAKE_COLOR); });
}

void Player::reset() noexcept {
	bodyparts[0] = { 300, 300 };
	bodyparts.resize(1);
}

std::vector<Position> Player::get_bodyparts() noexcept {
	return bodyparts;
}

Position Player::get_position() const noexcept {
	return bodyparts[0];
}


int Player::get_head_x() const noexcept {
	return bodyparts[0].x;
}

int Player::get_head_y() const noexcept {
	return bodyparts[0].y;
}