#pragma once
#include "Object.h"
#include "StatusUnit.h"
#include "FightUnit.h"

class AActor : public UObject, public UStatusUnit, public UFightUnit
{
public:
	virtual void BeginPlay();

	void StatusRender();

	virtual void StatusTextRender();
};

