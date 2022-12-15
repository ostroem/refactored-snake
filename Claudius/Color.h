#pragma once

class Color {
public:
	Color() = default;
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept: r(r), g(g), b(b), a(a)
	{
	}

	unsigned char r{ };
	unsigned char g{ };
	unsigned char b{ };
	unsigned char a{ };
};