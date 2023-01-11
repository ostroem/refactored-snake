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
	constexpr int movement_speed = 10;
	Position head = get_head();
	switch (direction) {
	case Directions::NONE: break;
	case Directions::UP: head.y -= movement_speed; break;
	case Directions::DOWN: head.y += movement_speed; break;
	case Directions::LEFT: head.x -= movement_speed; break;
	case Directions::RIGHT: head.x += movement_speed; break;
	default: break;
	}
	set_head_position(head);
}

Position Player::get_head() const noexcept {
	return parts[0];
}

void Player::set_head_position(Position pos) noexcept
{
	parts[0].x = pos.x;
	parts[0].y = pos.y;
}

void Player::on_key_down(SDL_Keycode key) noexcept {
	switch (key) {
	case SDLK_LEFT:
		direction = (direction != Directions::RIGHT) ? Directions::LEFT : Directions::RIGHT;
		break;
	case SDLK_RIGHT:
		direction = (direction != Directions::LEFT) ? Directions::RIGHT : Directions::LEFT;
		break;
	case SDLK_UP:
		direction = (direction != Directions::DOWN) ? Directions::UP : Directions::DOWN;
		break;
	case SDLK_DOWN:
		direction = (direction != Directions::UP) ? Directions::DOWN : Directions::UP;
		break;
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
	direction = Directions::NONE;
}


Position Player::get_position() const noexcept {
	return parts[0];
}


