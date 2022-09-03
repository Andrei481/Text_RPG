#include <iostream>
#include <random>

class Entity {
private:
	int max_health_points;
	int health_points;
	int attack_damage;
	int max_attack_damage;
	int min_attack_damage;
public:
	Entity(int hp, int atk) {
		this->health_points = hp;
		this->attack_damage = atk;
		this->max_attack_damage = atk + 10;
		this->min_attack_damage = atk - 10;
	}

	// getters
	int get_hp() {
		return this->health_points;
	}

	int get_ad() {
		return this->attack_damage;
	}

	// setters
	void set_hp(int new_health_points) {
		this->health_points = new_health_points;
	}

	void set_atk(int new_attack_damage) {
		this->attack_damage = new_attack_damage;
	}

	// utils
	/*int generate_damage() {
		std::uniform_int_distribution<int, int> random_attack_damage(this->max_attack_damage, this->min_attack_damage);
		return random_attack_damage;
	}*/

	void take_damage(int taken_damage) {
		this->health_points -= taken_damage;
	}

	void heal(int healed_amount) {
		this->health_points += healed_amount;
	}

	void increase_ad(int increase_amount) {
		this->attack_damage += increase_amount;
	}

};