#include "SDL.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "Game.h"
#include "Image.h"
#include "Window.h"
#include "Renderer.h"

#undef main

struct ResourceImpl
{
	ResourceImpl(SDL_Renderer* renderer) : renderer(renderer) {};
	std::vector<std::pair<std::string, SDL_Texture*>> textures;
	SDL_Renderer* renderer;
	SDL_Texture* GetTexture(unsigned int id)
	{
		if (id < textures.size())
			return textures[id].second;
		else
			return nullptr;
	}
};

void RenderManager::Render(const Vector2Int& pos, const Rectangle& rect, const Color& color)
{
	rectEntries.push_back({ pos, rect, color });
}

void RenderManager::Clear()
{
	rectEntries.clear();
}


int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Window window { "Snake", 500, 500 };
	Renderer renderer { window };
	bool running = true;
	
	RenderManager renderManager;
	ResourceImpl resourceImpl(renderer.renderer);
	ResourceManager resourceManager(resourceImpl);
	Game game(resourceManager);

	//int width = 500;
	//int height = 500;
	//std::string title = "";
	//game.Enter(width, height, title);
	//SDL_SetWindowPosition(window.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	
	float dt = 1.0f / 60.0f;
	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN: game.OnKeyDown(e.key.keysym.sym); break;
			default:
				break;
			}
		}

		game.Update(dt);
		game.Render(renderManager);

		renderer.set_draw_color(0, 0, 0, 0);
		renderer.clear();
		for (auto& entry : renderManager.rectEntries)
		{
			renderer.set_draw_color(entry.color.r, entry.color.g, entry.color.b, entry.color.a);
			SDL_Rect rect{ entry.position.x,
						   entry.position.y,
						   entry.rect.w,
						   entry.rect.h };
			renderer.render_fillrect(rect);
		}
		renderer.present();
		renderManager.Clear();
		SDL_Delay(1000 / 20); //<- "Framerate".
	}

	return 0;
}
