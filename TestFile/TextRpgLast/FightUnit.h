#pragma once
class UFightUnit
{
public:
	inline void Init(class UStatusUnit* _ThisUnit)
	{
		ThisUnit = _ThisUnit;
	}

	bool IsDeath() const;

	virtual int GetDamage() const;

	void DamageLogic(class UFightUnit& _Unit);

private:
	class UStatusUnit* ThisUnit = nullptr;
	class UFightUnit* AttUnit = nullptr;
	int CurDamage = 0;
};

