#pragma once

struct Rectangle
{
	int x{}; 
	int y{};
	int w{}; 
	int h{};

	Rectangle() noexcept;
	Rectangle(const Rectangle& rhs) noexcept;
	Rectangle(int x, int y, int w, int h) noexcept;

	//void SetBounds(int x, int y, int w, int h);
};