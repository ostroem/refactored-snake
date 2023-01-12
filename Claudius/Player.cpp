#include <algorithm>

#include "Player.h"
#include "Config.h"

Player::Player() noexcept {
	bodyparts.push_back(get_randomized_position());
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
	return bodyparts.front();
}

void Player::on_key_down(SDL_Keycode key_) noexcept {
	switch (key_) {
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

void Player::render(const Renderer& renderer_) const noexcept {
	std::ranges::for_each(bodyparts, [&](Position bodypart) noexcept {
		renderer_.render(bodypart, SNAKE_COLOR); });
}

void Player::reset(Position position_) noexcept {
	head() = position_;
	bodyparts.resize(1);
}

std::vector<Position> Player::get_bodyparts() noexcept {
	return bodyparts;
}

Position Player::get_position() const noexcept {
	return bodyparts.front();
}