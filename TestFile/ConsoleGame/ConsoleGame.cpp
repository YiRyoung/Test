// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "ConsoleEngine.h"
#include <Windows.h>

// API 랜더링 구조의 예비 
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 프레임 구조가 기반이 됩니다.
	// 프레임 구조가 뭐냐?

	// 프레임이란 화면의 갱신률을 의미하는데.
	// 

	// 게임 내용

	// 오브젝트 구조
	// 랜더링구조
	// 충돌구조
	// 릴리즈 구조

	// 엔진들은 대부분 틀을 만듭니다.
	// virtual 함수를 N개 만들어요.
	// 각 함수마다 목적을 줍니다.
	
	// 유저가 움직이라고 한다. => 유저들은 착각한다. 
	// void Tick()
	// 
	// 유저가 움직이라고 한 명령을 기억해놨다가 진짜 로직이 돌아서 움직인다.
	// ?????????????

	// 명령을 다 지운다.

	ConsoleEngine::Start();

}
