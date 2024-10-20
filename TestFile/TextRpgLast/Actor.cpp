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
	printf_s("���ݷ� : %d ~ %d\n", MinAtt, MaxAtt);
	printf_s("ü�� : %d\n", CurHp);
	printf_s("��� : %d\n", Gold);
}