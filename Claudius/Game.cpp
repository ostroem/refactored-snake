// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "Window.h"
#include "Renderer.h"
#include "SDL_System.h"
#include "Config.h"

void Game::run()
{
	SDL_System system{};
	Window window{};
	Renderer renderer{ window };
	bool running = true;

	while (running) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT: running = false;
				break;
			case SDL_KEYDOWN: on_key_down(e.key.keysym.sym);
				break;
			default: 
				break;
			}
		}

		update();
		render(renderer);

		SDL_Delay(50);
	}
}


void Game::update()
{
	player.update();
	if (player.is_head_colliding_with_part()) {
		player.reset();
		score = 0;
	}
	if (player.is_head_out_of_bounds()) {
		player.reset();
		score = 0;
	}

	if (player.get_position().x == apple.get_position().x &&
		player.get_position().y == apple.get_position().y) {
		score++;
		apple.randomize_position();
		player.grow();
	}
}

void Game::render(Renderer& renderer)
{
	player.render(renderer);
	apple.render(renderer);
	renderer.present();
}

void Game::on_key_down(SDL_Keycode key)
{
	player.on_key_down(key);
}