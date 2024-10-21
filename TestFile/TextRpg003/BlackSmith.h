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

	void TryUpgrade(class APlayer& _Player);

private:
	class UZone* ParentZone = nullptr;
};

