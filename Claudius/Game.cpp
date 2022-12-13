// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include "Window.h"
#include "Renderer.h"
#include "SDL_System.h"

void RenderManager::Render(const Vector2Int& pos, const SDL_Rect& rect, const Color& color)
{
	rectEntries.push_back({ pos, rect, color });
}

void RenderManager::Clear()
{
	rectEntries.clear();
}

void Game::run()
{
	SDL_System system{};
	Window window{ "Snake", 1250, 700 };
	Renderer renderer{ window };
	bool running = true;

	RenderManager renderManager;

	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: running = false;
				break;
			case SDL_KEYDOWN: OnKeyDown(e.key.keysym.sym);
				break;
			default: 
				break;
			}
		}

		Update();
		Render(renderManager);

		renderer.set_draw_color(0, 0, 0, 0);
		renderer.clear();
		for (auto& entry : renderManager.rectEntries)
		{
			renderer.set_draw_color(entry.color.r,
									entry.color.g,
									entry.color.b,
									entry.color.a);

			renderer.render_fillrect(entry.rect);
		}
		renderer.present();
		renderManager.Clear();
		SDL_Delay(1000 / 20);
	}

}

bool Game::Enter()
{
	return true;
}

void Game::Update()
{
	player.Update();

	// Player colliding on theirself.
	for (int i = 0; i < score; i++)
	{
		if (player.get_position() == player.parts[i].position)
		{
			player.ResetPlayer();
		}
	}

	// Player going out of X bounds.
	if (player.get_position().x > width || player.get_position().x < 0)
	{
		player.ResetPlayer();
	}

	// Player going out of Y bounds.
	if (player.get_position().y > height || player.get_position().y < 0)
	{
		player.ResetPlayer();
	}

	// Player collide on apple.
	if (player.get_position() == apple.get_position())
	{
		score++;
		apple.set_position((rand() % 125) * 10, (rand() % 70) * 10);
	}
}

void Game::Render(RenderManager& renderManager)
{
	player.Render(renderManager);
	apple.Render(renderManager);
}

void Game::OnKeyDown(SDL_Keycode key)
{
	player.OnKeyDown(key);
}