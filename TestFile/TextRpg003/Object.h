#pragma once
#include "ContentsConst.h"
#include <iostream>
#include <RpgBaseSystem/EngineDebug.h>

// �̸��� ������ ��� ��ü���� �ֻ��� Ŭ����
class UObject
{
public:
	inline const char* GetName()
	{
		return Name;
	}

	void SetName(const char* const _Name);

private:
	char Name[NAMELEN] = "NONE";
};

