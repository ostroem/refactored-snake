#include "SDL.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "Game.h"
#include "Image.h"
#include "Window.h"

#undef main

// ResourceManager 

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

	Window window {};

	SDL_Renderer* renderer = SDL_CreateRenderer(window.window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		const char* error = SDL_GetError();
		return 0;
	}
	bool running = true;
	
	RenderManager renderManager;
	ResourceImpl resourceImpl(renderer);
	ResourceManager resourceManager(resourceImpl);
	Game game(resourceManager);

	int width = 500;
	int height = 500;
	std::string title = "";
	game.Enter(width, height, title);
	SDL_SetWindowSize(window.window, width, height);
	SDL_SetWindowTitle(window.window, title.c_str());
	SDL_SetWindowPosition(window.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	
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

		SDL_SetRenderDrawColor(renderer,0,0,0,0);
		SDL_RenderClear(renderer);
		for (auto& entry : renderManager.rectEntries)
		{
			SDL_SetRenderDrawColor(renderer, entry.color.r, entry.color.g, entry.color.b, entry.color.a);
			SDL_Rect rect{ entry.position.x,
						   entry.position.y,
						   entry.rect.w,
						   entry.rect.h };
			//SDL_RenderDrawRect(renderer, &rect);	// <- If you want to draw the "outline" of the rectangle.
			SDL_RenderFillRect(renderer, &rect);  // <- If you want to draw a "filled" rectangle. 
		}
		SDL_RenderPresent(renderer);
		renderManager.Clear();
		SDL_Delay(1000 / 20); //<- "Framerate".
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window.window);

	return 0;
}
