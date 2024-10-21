#pragma once
#include "FightUnit.h"

class APlayer : public UFightUnit
{
public:
	APlayer();

	void StatusTextPrint() override;

	inline int GetCurZone() const
	{
		return CurZoneIndex;
	}

	inline int GetEquipAtt() const
	{
		return EquipAtt;
	}

	inline void SetCurZone(int _index)
	{
		CurZoneIndex = _index;
	}

	inline void SetEquipAtt(int _Value)
	{
		EquipAtt = _Value;
	}

private:
	int CurZoneIndex = 0;
	int EquipAtt = 0;
};

