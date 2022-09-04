#ifndef Spell_HEADER
#define Spell_HEADER

#include <iostream>
#include <string>

class Spell {
private:
	std::string name;
	int cost;
	int damage;
public:
	Spell(std::string name, int damage, int cost) {
		this->name = name;
		this->damage = damage;
		this->cost = cost;
	}

	friend std::ostream& operator << (std::ostream& out, const Spell& s);

	// getters
	std::string get_spell_name() {
		return this->name;
	}

	int get_spell_cost() {
		return this->cost;
	}

	int get_spell_damage() {
		return this->damage;
	}

};

std::ostream& operator << (std::ostream& out, const Spell& s)
{
	out << s.name << "\t Damage: " << s.damage << "\t (Cost: " << s.cost << ")";
	return out;
}

#endif