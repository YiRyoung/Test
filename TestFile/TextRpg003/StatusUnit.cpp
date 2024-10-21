#include "StatusUnit.h"
#include <RpgBaseSystem/EngineDebug.h>
#include <iostream>

void UStatusUnit::PrintLine(int _Count)
{
	for (int i = 0; i < _Count; i++)
	{
		printf_s("-");
	}
	printf_s("\n");
}

void UStatusUnit::TopLine()
{
	const char* Name = GetName();
	printf_s("%s Status ", Name);
	int NameLen = static_cast<int>(strlen(Name));
	int StrLen = static_cast<int>(strlen(" Status "));
	int NameCount = LINECOUNT - (NameLen + StrLen - 1);
	PrintLine(NameCount);
}

void UStatusUnit::StatusRender()
{
	TopLine();
	StatusTextPrint();
	PrintLine(LINECOUNT);
}