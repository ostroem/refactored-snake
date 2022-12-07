#pragma once

class Color {
public:
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept: r(r), g(g), b(b), a(a)
	{
	}

private:
	unsigned char r{ };
	unsigned char g{ };
	unsigned char b{ };
	unsigned char a{ };
};