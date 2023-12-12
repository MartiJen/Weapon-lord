#include "Knight.h"
#include <iostream>
using namespace std;

Knight::Knight() : BaseUnit(20, 5), shield(50), specialAttackCoolDown(0), isStunned(false) {}

void Knight::PerformAttack(BaseUnit& target) {
	if (TrySpecialAttack(target)) {
		UseSpecialAbility(target);
	}
	else {
		BaseUnit::PerformAttack(target);
	}

	if (specialAttackCoolDown > 0) {
		--specialAttackCoolDown;
	}
}

bool Knight::TrySpecialAttack(BaseUnit& target) {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0, 1);

	return specialAttackCoolDown == 0 && dis(gen) < SPECIAL_ATTACK_SUCCESS_RATE;
}

void Knight::DisplayStatus() const{
	BaseUnit::DisplayStatus();
	cout << "Chield: " << shield << endl;
}

void Knight::UseSpecialAbility(BaseUnit& target) {
	target.TakeDamage(GetDamage() * SPECIAL_ATTACK_MULTILIER);
	specialAttackCoolDown = SPECIAL_ATTACK_COOLDOWN;
}

void Knight::Stun() {
	isStunned = true;
}

void Knight::EndTurn() {
	if (isStunned) {
		isStunned = false;
	}
}

bool Knight::IsStunned() const {
	return isStunned;
}