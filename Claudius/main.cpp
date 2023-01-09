#include "Game.h"
#include <exception>
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
	try {
		Game{}.run();
	}
	catch (const std::exception error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	return 0;
}
