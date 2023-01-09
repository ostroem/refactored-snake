#include "Player.h"
#include "Renderer.h"
#include <algorithm>
#include "Config.h"

Player::Player() noexcept {
	parts.push_back({ 100, 300 });
}
void Player::render(Renderer& renderer) {
	for(auto& p : parts) {
		renderer.render(p, snake_color);
	}
}

void Player::update() {
	update_parts_position();
	update_head_position();
}

void Player::on_key_down(SDL_Keycode key) noexcept {
	switch (key) {
	case SDLK_LEFT:
		if (direction != directions::right)
			direction = directions::left;
		break;
	case SDLK_RIGHT:
		if(direction != directions::left)
			direction = directions::right; 
		break;
	case SDLK_UP:
		if(direction != directions::down)
			direction = directions::up; 
		break;
	case SDLK_DOWN:
		if(direction != directions::up)
			direction = directions::down;
		break;
	default: break;
	}
}

void Player::reset() noexcept {
	parts.clear();
	push_part();
}

void Player::grow() {
	parts.push_back(head());
}

void Player::update_parts_position() {
	std::shift_right(parts.begin(), parts.end(), 1);
}

void Player::push_part() {
	parts.push_back(get_position());
}

void Player::update_head_position() {
	constexpr int movement_speed = 10;

	switch (direction) {
	case directions::up:
		head().y -= movement_speed;
	case directions::down:
		head().y += movement_speed; break;
	case directions::left:
		head().x -= movement_speed; break;
	case directions::right:
		head().x += movement_speed; break;
	default: break;
	}

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

Position Player::get_position() const {
	return parts.at(0);
}

Position& Player::head() {
	return parts.at(0);
}

