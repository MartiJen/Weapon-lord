#pragma once
#ifndef ORC_H
#define ORC_H

#include "BaseUnit.h"
#include <random>
#include <typeinfo>

class Orc : public BaseUnit {
public:
	Orc();
	void PerformAttack(BaseUnit& target) override;
	void UseSpecialAbility(BaseUnit& target) override;
	bool TryStunAttack();
	void DisplayStatus() const;

private:
	int stunCoolDown;

	static constexpr double STUN_ATTACK_SUCCES_RATE = 0.2;
	static constexpr int STUN_ATTACK_COOLDOWN = 5;
};


#endif // !ORC_H
