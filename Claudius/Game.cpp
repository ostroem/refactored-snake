// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include "Window.h"
#include "Renderer.h"
#include "SDL_System.h"

void RenderManager::pushback_entries(const Vector2Int& pos, const SDL_Rect& rect, const Color& color)
{
	rectEntries.push_back({ pos, rect, color });
}

void RenderManager::clear()
{
	rectEntries.clear();
}

void Game::run()
{
	SDL_System system{};
	Window window{ "Snake", 1280, 720 };
	Renderer renderer{ window };
	RenderManager renderManager;
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
		render(renderManager);

		renderer.set_draw_color(0, 0, 0, 0);
		renderer.clear();
		for (auto& entry : renderManager.rectEntries) {
			renderer.set_draw_color(entry.color.r,
									entry.color.g,
									entry.color.b,
									entry.color.a);

			renderer.render_fillrect(entry.rect);
		}
		renderer.present();
		renderManager.clear();
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

	if (player.get_position() == apple.get_position()) {
		score++;
		apple.randomize_position();
		player.grow();
	}
}

void Game::render(RenderManager& renderManager)
{
	player.render(renderManager);
	apple.render(renderManager);
}

void Game::on_key_down(SDL_Keycode key)
{
	player.on_key_down(key);
}