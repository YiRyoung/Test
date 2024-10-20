#include "Player.h"
#include <iostream>

APlayer::APlayer()
{
	UObject* ObjectPtr = this;
	UStatusUnit* StatusUnitPtr = this;
	UFightUnit* FightUnitPtr = this;
}

void APlayer::StatusTextRender()
{
	printf_s("공격력 : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
	printf_s("체력 : %d\n", CurHp);
	printf_s("골드 : %d\n", Gold);
}