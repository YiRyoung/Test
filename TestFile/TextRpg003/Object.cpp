#include "Object.h"

void UObject::SetName(const char* const _Name)
{
	if (NAMELEN <= strlen(_Name))
	{
		MSGASSERT("이름이 너무 깁니다.");
		return;
	}

	strcpy_s(Name, _Name);
}