#pragma once
#include <string_view>

struct Config {
	constexpr static int WINDOW_WIDTH = 1280;
	constexpr static int WINDOW_HEIGHT = 720;

	constexpr static std::string_view TITLE = "Snake";
};
