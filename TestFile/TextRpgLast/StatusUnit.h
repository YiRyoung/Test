#pragma once

class UStatusUnit
{
public:
	inline int GetCurHp() const
	{
		return CurHp;
	}

	inline int GetMaxHp() const
	{
		return MaxHp;
	}

	inline int GetMinAtt() const
	{
		return MinAtt;
	}

	inline int GetMaxAtt() const
	{
		return MaxAtt;
	}

	inline int GetSpeed() const
	{
		return Speed;
	}

	inline int GetGold() const
	{
		return Gold;
	}

	void Hurt(int _Damage)
	{
		CurHp -= _Damage;
	}

	void Heal()
	{
		CurHp = MaxHp;
	}

	void SetGold(int _Value)
	{
		Gold = _Value;
	}

protected:
	int CurHp = 100;
	int MaxHp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 10;
	int Gold = 0;

private:

};

