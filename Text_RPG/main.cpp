#include <iostream>
#include "Colors.h"
#include "Entity.h"

bool running = true;

void choose_action(Entity &entity_1, Entity &entity_2) {
	std::cout << "Choose your action:" << std::endl;
	std::cout << "1. Attack" << std::endl << "2. Heal (50 HP)" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice) {
		case 1:
			entity_1.generate_damage();
			std::cout << YELLOW << "Player hit enemy for " << entity_1.generate_damage() << " points of damage!" << RESET << std::endl;
			entity_2.take_damage(entity_1.generate_damage());
			break;
		case 2:
			entity_1.heal(50);
			std::cout << GREEN << "Player healed for 50 HP!" << RESET << std::endl;
			break;
		default:
			std::cout << "Invalid choice";
			break;
	}
}

void display_current_hp(Entity entity_1, Entity entity_2) {
	std::cout << std::endl;
	std::cout << RED << "Player HP: " << entity_1.get_hp() << "/" << entity_1.get_max_hp() << RESET << std::endl;
	std::cout << RED << "Enemy HP: " << entity_2.get_hp() << "/" << entity_2.get_max_hp() << RESET << std::endl;
	std::cout << std::endl;
}

int main() {
	Entity player(300, 50);
	Entity enemy(750, 50);

	while (running) {
		std::cout << RED << "AN  ENEMY  ATTACKS!" << RESET << std::endl << std::endl;
		choose_action(player, enemy);
		display_current_hp(player, enemy);

		if (enemy.get_hp() == 0) {
			std::cout << BLUE << "You have slain your enemy!" << RESET << std::endl;
			running = false;
		}

		player.take_damage(enemy.generate_damage());
		std::cout << YELLOW << "You have been hit for " << enemy.generate_damage() << "points of damage!" << RESET << std::endl;
		display_current_hp(player, enemy);

		if (player.get_hp() == 0) {
			std::cout << RED << "You have been slain!" << RESET << std::endl;
			running = false;
		}
	}
}