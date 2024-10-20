#include "Actor.h"
#include <iostream>

void AActor::StatusRender()
{
	TopLine();

	StatusTextRender();

	LinePrint(static_cast<int>(Enums::MAXS::LINECOUNT));
}

void AActor::BeginPlay()
{
	UFightUnit::Init(this);
}

void AActor::StatusTextRender()
{
	printf_s("공격력 : %d ~ %d\n", MinAtt, MaxAtt);
	printf_s("체력 : %d\n", CurHp);
	printf_s("골드 : %d\n", Gold);
}