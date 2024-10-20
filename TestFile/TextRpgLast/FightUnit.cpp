#include "FightUnit.h"
#include "StatusUnit.h"
#include <iostream>

bool UFightUnit::IsDeath() const
{
	return (0 >= ThisUnit->GetCurHp());
}

int UFightUnit::GetDamage() const
{
	int Damage = ThisUnit->GetMinAtt() + (rand() % (ThisUnit->GetMaxAtt() - ThisUnit->GetMinAtt()) + 1);
	return Damage;
}

void UFightUnit::DamageLogic(class UFightUnit& _Unit)
{
	UStatusUnit* Att = _Unit.ThisUnit;
	UStatusUnit* Def = this->ThisUnit;
	CurDamage = _Unit.GetDamage();
	int CurHp = Def->GetCurHp() - CurDamage;
	Def->Hurt(CurHp);
}