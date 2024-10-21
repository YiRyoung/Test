#pragma once
#include "ContentsConst.h"
#include "Object.h"

class UStatusUnit : public UObject
{
public:
	inline int GetMaxHp() const
	{
		return MaxHp;
	}

	inline int GetCurHp() const
	{
		return CurHp;
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

	inline void SetCurHp(int _Value)
	{
		CurHp = _Value;
	}

	inline void SetGold(int _Value)
	{
		Gold = _Value;
	}

	void PrintLine(int _Count);
	void TopLine();
	void StatusRender();

protected:
	int MaxHp = 100;
	int CurHp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 10;
	int Gold = 0;

	virtual void StatusTextPrint() {}

private:

};

