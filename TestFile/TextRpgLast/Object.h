#pragma once
#include "Enums.h"

class UObject
{
public:
	UObject();
	 
	virtual ~UObject();

	inline const char* GetName() const
	{
		return Name;
	}

	void SetName(const char* const _Name);

	void LinePrint(int _Count);
	void TopLine();

private:
	char Name[static_cast<int>(Enums::MAXS::NAMEMAX)] = { 0, };
};

