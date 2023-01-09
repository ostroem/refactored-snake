#include "Player.h"
#include "Renderer.h"
#include <algorithm>
#include "Config.h"

Player::Player() noexcept {
	Position pos = { 300, 300 };
	parts.push_back(pos);
}
void Player::render(Renderer& renderer) const noexcept {
	for(const auto& part : parts) {
		renderer.render(part, SNAKE_COLOR);
	}
}

void Player::update() noexcept {
	if (parts.size() > 1) {
		update_parts_position();
	}
	update_head_position();
}

void Player::grow() noexcept {
	parts.push_back(head());
}

bool Player::is_head_colliding_with_part()
{
	for (int i = 1; i < parts.size() - 1; i++) {
		if (parts.at(i).x == head().x &&
			parts.at(i).y == head().y)
			return true;
	}
	return false;
}

bool Player::is_head_out_of_bounds()
{
	if (head().x > Config::WINDOW_WIDTH || head().x < 0)
		return true;
	if (head().y > Config::WINDOW_HEIGHT || head().y < 0)
		return true;
	return false;
}

void Player::reset() noexcept {
	head() = { 300, 300 };
	parts.resize(1);
	direction = Directions::NONE;
}

void Player::on_key_down(SDL_Keycode key) noexcept {
	switch (key) {
	case SDLK_LEFT:
		if (direction != Directions::RIGHT)
			direction = Directions::LEFT;
		break;
	case SDLK_RIGHT:
		if (direction != Directions::LEFT)
			direction = Directions::RIGHT;
		break;
	case SDLK_UP:
		if (direction != Directions::DOWN)
			direction = Directions::UP;
		break;
	case SDLK_DOWN:
		if (direction != Directions::UP)
			direction = Directions::DOWN;
		break;
	default: break;
	}
}

Position Player::get_position() const {
	return parts.at(0);
}

void Player::update_head_position() noexcept {
	constexpr int movement_speed = 10;

	switch (direction) {
	case Directions::NONE: break;
	case Directions::UP: head().y -= movement_speed; break;
	case Directions::DOWN: head().y += movement_speed; break;
	case Directions::LEFT: head().x -= movement_speed; break;
	case Directions::RIGHT: head().x += movement_speed; break;
	default: break;
	}

}

void Player::update_parts_position() noexcept {
	std::shift_right(parts.begin(), parts.end(), 1);
}

Position& Player::head() noexcept {
	return parts[0];
}

