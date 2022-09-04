#include <iostream>
#include "Colors.h"
#include "Entity.h"
#include "Player.h"
#include "spells_potions.h"

bool running = true;

void choose_action(Player& entity_1, Entity& entity_2);

int choose_magic_spell(Player player) {
	int chosen_spell, chosen_spell_index;
	if (player.get_cheapest_spell_cost() > player.get_mp()) {
		//std::cout << YELLOW << "You don't have enough magic points to cast any spells right now" << RESET << std::endl;
		return -1;
	}
	while (true) {
		std::cout << YELLOW << "Choose your spell: " << RESET << std::endl;
		std::cin >> chosen_spell;
		chosen_spell_index = chosen_spell - 1;

		if (chosen_spell_index < 0 || chosen_spell_index >= player.get_number_of_spells()) {
			std::cout << YELLOW << "Invalid choice" << RESET << std::endl;
		}
		else if (player.get_spell_at_index(chosen_spell_index).get_spell_cost() > player.get_mp()) {
			std::cout << YELLOW << "You don't have enough magic points to cast: " << BLUE 
				<< player.get_spell_at_index(chosen_spell_index).get_spell_name() << RESET << std::endl;
		}
		else {
			std::cout << YELLOW << "Chosen spell: " << RESET << BLUE << player.get_spell_at_index(chosen_spell_index).get_spell_name() 
				<< RESET << std::endl;
			break;
		}
	}

	return chosen_spell_index;
}

void choose_action(Player &entity_1, Entity &entity_2) {
	std::cout << YELLOW << "Choose your action:" << RESET << std::endl;
	std::cout << "1. Attack" << std::endl << "2. Magic" << std::endl << "3. Heal (50 HP)" << std::endl;
	int choice, chosen_spell_index;
	std::cin >> choice;
	switch (choice) {
		case 1:
			entity_1.generate_damage();
			std::cout << YELLOW << "Player hit enemy for " << MAGENTA << entity_1.generate_damage() << RESET << YELLOW << " points of damage!" << RESET << std::endl;
			entity_2.take_damage(entity_1.generate_damage());
			break;
		case 2:
			std::cout << BLUE << "Magic Spells: " << RESET << std::endl;
			entity_1.display_spells();
			std::cout << BLUE << "MP: " << entity_1.get_mp() << "/" << entity_1.get_max_mp() << RESET << std::endl;
			chosen_spell_index = choose_magic_spell(entity_1);
			if (chosen_spell_index == -1) {
				std::cout << YELLOW << "You don't have enough magic points to cast any spells right now." << RESET << std::endl;
				return choose_action(entity_1, entity_2);
			}
			entity_1.use_spell(chosen_spell_index, entity_2);
			std::cout << YELLOW << "Player hit enemy for " << MAGENTA << entity_1.get_spell_at_index(chosen_spell_index).get_spell_damage() << YELLOW
				<< " points of magic damage!" << RESET << std::endl;
			break;
		case 3:
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
	Player player(400, 50, 200);
	player.add_spell({ firebolt, fireball, thunderbolt, blizzard });
	Entity enemy(750, 35);

	while (running) {
		std::cout << RED << "AN  ENEMY  ATTACKS!" << RESET << std::endl << std::endl;
		choose_action(player, enemy);
		display_current_hp(player, enemy);

		if (enemy.get_hp() == 0) {
			std::cout << BLUE << "You have slain your enemy!" << RESET << std::endl;
			running = false;
		}

		player.take_damage(enemy.generate_damage());
		std::cout << YELLOW << "You have been hit for " << MAGENTA <<enemy.generate_damage() << RESET << YELLOW << " points of damage!" << RESET << std::endl;
		display_current_hp(player, enemy);

		if (player.get_hp() == 0) {
			std::cout << RED << "You have been slain!" << RESET << std::endl;
			running = false;
		}
	}
}