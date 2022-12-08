// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include <iostream>

Game::Game(ResourceManager& resourceManager) : m_resourceManager(resourceManager), width(1250), height(700)
{
	player.Initialize();
}

Game::~Game()
{
}

bool Game::Enter(int& w, int& h, std::string& title)
{
	w = this->width;	//1250
	h = this->height;	// 700
	title = "Snake";
	return true;
}

void Game::Update()
{
	// dt means delta time.
	// timer += dt; <- check Game.h
	// if (timer > updateInterval)
	//{
	// update snake movement
	// timer = 0.0f; or timer -= updateInterval;
	//}

	player.Update();

	// Player colliding on theirself.
	for (int i = 0; i < player.player_score; i++)
	{
		if (player.position == player.parts[i].position)
		{
			player.ResetPlayer();
		}
	}

	// Player going out of X bounds.
	if (player.position.x > width || player.position.x < 0)
	{
		player.ResetPlayer();
	}

	// Player going out of Y bounds.
	if (player.position.y > height || player.position.y < 0)
	{
		player.ResetPlayer();
	}

	// Player collide on apple.
	if (player.position == apple.get_position())
	{
		player.player_score++;
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