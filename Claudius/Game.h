#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"
#include "SDL_keycode.h"

struct RenderManager;
struct ResourceManager;

class Game
{
	Player player;
	Apple apple;

	ResourceManager& m_resourceManager;

public:
	int width { 0 };
	int height { 0 };
	int score { 0 };

	Game(ResourceManager& resourceManager);
	~Game();
	bool Enter(int& w, int& h, std::string& title);
	void Update();
	void Render(RenderManager& rendererManager);
	void OnKeyDown(SDL_Keycode key);
};