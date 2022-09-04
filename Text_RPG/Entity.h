#ifndef Entity_HEADER
#define Entity_HEADER

#include <iostream>
#include <chrono>
#include <random>

class Entity {
private:
	int max_health_points;
	int health_points;
	int attack_damage;
	int max_attack_damage;
	int min_attack_damage;
public:
	Entity(int max_hp, int atk) {
		this->max_health_points = max_hp;
		this->health_points = max_hp;
		this->attack_damage = atk;
		this->max_attack_damage = atk + 10;
		this->min_attack_damage = atk - 10;
	}

	// getters
	int get_hp() {
		return this->health_points;
	}

	int get_max_hp() {
		return this->max_health_points;
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
	int generate_damage() {
		auto now = std::chrono::system_clock::now();
		auto time = std::chrono::system_clock::to_time_t(now);
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) - 
			std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());

		std::srand(ms.count());
		int dmg = this->min_attack_damage + (std::rand() % (this->max_attack_damage - this->min_attack_damage + 1));
		return dmg;
	}

	void take_damage(int taken_damage) {
		this->health_points -= taken_damage;

		if (this->health_points < 0) {
			this->health_points = 0;
		}
	}

	void heal(int healed_amount) {
		this->health_points += healed_amount;

		if (this->health_points > this->max_health_points) {
			this->health_points = this->max_health_points;
		}
	}

	void increase_ad(int increase_amount) {
		this->attack_damage += increase_amount;
	}
};

#endif