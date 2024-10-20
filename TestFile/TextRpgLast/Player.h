#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();

	inline int GetEquipAtt() const
	{
		return EquipAtt;
	}

	inline void SetEquipAtt(int _Value)
	{
		EquipAtt = _Value;
	}

	inline int GetDamage() const override
	{
		return UFightUnit::GetDamage() + EquipAtt;
	}

	void StatusTextRender() override;

private:
	int EquipAtt = 0;
};

