#pragma once
#include "Zone.h"

class BlackSmith
{
public:
	void InPlayer(class APlayer& _Player);

	inline void SetParent(class UZone* _ParentZone)
	{
		ParentZone = _ParentZone;
	}

	inline bool IsSucees()
	{
		int Result = rand() % 2;
		return (Result > 0);
	}

	void PrintBS(class APlayer& _Player);

	void TryUpgrade(class APlayer& _Player);

private:
	class UZone* ParentZone = nullptr;
};

