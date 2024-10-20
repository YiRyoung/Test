#include "Object.h"
#include "Enums.h"
#include <iostream>
#include <RpgBaseSystem/EngineDebug.h>

UObject::UObject()
{

}

UObject::~UObject()
{

}

void UObject::SetName(const char* const _Name)
{
	if (static_cast<int>(Enums::MAXS::NAMEMAX) <= strlen(_Name))
	{
		MSGASSERT("이름이 너무 깁니다.");
		return;
	}

	strcpy_s(Name, _Name);
}

void UObject::LinePrint(int _Count)
{
	for (int i = 0; i < _Count; i++)
	{
		printf_s("-");
	}
	printf_s("\n");
}

void UObject::TopLine()
{
	printf_s("%s Status ", Name);
	int NameLen = static_cast<int>(strlen(Name));
	int StrLen = static_cast<int>(strlen(" Status "));
	int LineCount = static_cast<int>(Enums::MAXS::LINECOUNT) - (NameLen + StrLen - 1);
	LinePrint(LineCount);
}