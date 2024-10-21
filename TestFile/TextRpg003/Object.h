#pragma once
#include "ContentsConst.h"
#include <iostream>
#include <RpgBaseSystem/EngineDebug.h>

// 이름을 가지는 모든 객체들의 최상위 클래스
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

