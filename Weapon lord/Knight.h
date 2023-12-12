#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H

#include "BaseUnit.h"
#include <random>

class Knight : public BaseUnit {
public:
	Knight();
	void PerformAttack(BaseUnit& target) override;
	void UseSpecialAbility(BaseUnit& target) override;
	void Stun();
	void EndTurn();
	bool IsStunned() const;
	bool TrySpecialAttack(BaseUnit& target);
	void DisplayStatus() const;

private:
	int shield;
	int specialAttackCoolDown;
	bool isStunned;

	static constexpr int SPECIAL_ATTACK_MULTILIER = 2;
	static constexpr double SPECIAL_ATTACK_SUCCESS_RATE = 0.6;
	static constexpr int SPECIAL_ATTACK_COOLDOWN = 3;
};


#endif // !KNIGHT_H
