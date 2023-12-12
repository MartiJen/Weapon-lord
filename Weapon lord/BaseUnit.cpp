#include "BaseUnit.h"
#include <iostream>
using namespace std;

BaseUnit::BaseUnit(int health, int damage) : health(health), damage(damage){}

void BaseUnit::TakeDamage(int amout) {
	health -= amout;
	if (health < 0) health = 0;
}

void BaseUnit::DisplayStatus() const {
	cout << "HP : " << health << endl;
}

bool BaseUnit::IsAlive() const {
	return health > 0;
}