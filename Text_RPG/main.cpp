#include <iostream>
#include "Colors.h"
#include "Entity.h"

bool running = true;



int main() {
	Entity player(300, 50);

	while (running) {
		std::cout << RED << "AN  ENEMY  ATTACKS!" << RESET << std::endl << std::endl;
		running = false;

	}
}