#pragma once
#include <BaseSystem/EngineMath.h>
#include "ConsoleWindow.h"

class GlobalValue
{
public:
	// Window 몇개입니까?

	static FIntPoint WindowSize;

	static UConsoleWindow* WindowPtr;

	static ConsoleImage* BackBuffer;

};

// extern UConsoleWindow* WindowPtr;
