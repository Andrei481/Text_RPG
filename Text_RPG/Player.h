#include <iostream>
#include <vector>
#include <initializer_list>
#include "Entity.h"
#include "Spell.h"

class Player : public Entity {
private:
	int max_magic_points;
	int magic_points;
	std::vector<Spell> spells;
public:
	Player(int max_hp, int atk, int max_magic_points) : Entity(max_hp, atk) {
		this->max_magic_points = max_magic_points;
		this->magic_points = max_magic_points;
	}

	Player(int max_hp, int atk, int max_magic_points, std::vector<Spell> spells) : Entity(max_hp, atk) {
		this->max_magic_points = max_magic_points;
		this->magic_points = max_magic_points;
		this->spells = spells;
	}

	//getters
	int get_mp() {
		return this->magic_points;
	}

	int get_max_mp() {
		return this->max_magic_points;
	}

	int get_number_of_spells() {
		return spells.size();
	}

	Spell get_spell_at_index(int spell_index) {
		return spells[spell_index];
	}

	int get_cheapest_spell_cost() {
		int min;
		if (spells.size() > 0) min = 9999;
		else min = 0;

		for (int i = 0; i < spells.size(); i++) {
			if (spells[i].get_spell_cost() < min) min = spells[i].get_spell_cost();
		}
		return min;
	}

	// setters
	void decrease_mp(int decreased_amount) {
		this->magic_points -= decreased_amount;
	}

	// utils
	void display_spells() {
		for (int i = 0; i < spells.size(); i++) {
			std::cout << (i+1) << ". " << spells[i] << std::endl;
		}
		std::cout << "0. Back" << std::endl;
	}

	void add_spell(std::initializer_list<Spell> spell_list) {
		for (auto new_spell : spell_list) {
			spells.push_back(new_spell);
		}
	}

	void add_spell(std::vector<Spell> additional_spells) {
		spells.insert(std::end(spells), std::begin(additional_spells), std::end(additional_spells));
	}

	void use_spell(int spell_index, Entity &enemy) {
		enemy.take_damage(spells[spell_index].get_spell_damage());
		this->decrease_mp(spells[spell_index].get_spell_cost());
	}

	void restore_mp() {
		this->magic_points += 40;
		if (this->magic_points > this->max_magic_points) 
			this->magic_points = max_magic_points;
	}
};