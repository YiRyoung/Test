#include "ConsoleEngine.h"
#include <Windows.h>
#include "GlobalValue.h"
#include "Actor.h"

// ConsoleEngine* Inst = new ConsoleEngine();
// ConsoleEngine* Inst = nullptr;

ConsoleEngine* ConsoleEngine::MainEngine = nullptr;

FIntPoint ConsoleEngine::WindowSize;
UConsoleWindow ConsoleEngine::Window;

ConsoleEngine::ConsoleEngine()
{

}

void ConsoleEngine::Start()
{
	// 디자인 패턴 갱
	// 그 디자인 패턴이 예제로 보여준 클래스 구성방식이 있다.


	// 단하나의 객체 만들고 더이상 만들지 않는 방식.
	// 핵심객체는 메모리 어디에 있는지 자신의 머릿속에 있어야 한다.
	// 값을 편하게 사용하기 위해서 나눠주는 객체들이 있다.
	// 랜더링을 위해서 Window가 핵심이다. Window를 어디서든 사용할수 있어야 한다.
	// 헤더만 추가하면 언제든지 그 객체에 접근할수 있게 한다.
	// 이때 꼭 싱글톤이 아닐수도 있다.
	// 생성자를 private으로 만들어서 딱 1개만 만들려고 하는 경우를 말한다.
	
	// unreal에서는 GEngine 같은 전역변수(extern)나 static으로 이루어져 있다.
	// 디자인 패턴이 애초에 강제성이 없다.

	// 이때 대부분 동적할당 할거냐 아니냐?
	// 왜 값으로 만들었냐? 포인터로 만들었다는건 언제든지 삭제할 가능성이 있다는 것.
	// 아니라면 리셋의 가능성이 있다.
	ConsoleEngine Engine;

	MainEngine = &Engine;

	Engine.BeginPlay();

	while (true)
	{
		Engine.Tick();
		Engine.Render();
		// 프로그램 250
		// 1000이 1초입니다.
		Sleep(250);

	}
	
}

void ConsoleEngine::BeginPlay()
{
	Window.BeginPlay();

	WindowSize.X = 20;
	WindowSize.Y = 10;

	GlobalValue::WindowPtr = &Window;

	Window.SetScreenSize(WindowSize);

	Player* NewPlayer = SpawnActor<Player>();
	Monster* NewMonster = SpawnActor<Monster>();
}

void ConsoleEngine::Tick()
{
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		AllActorVector[i]->Tick();
	}
}

void ConsoleEngine::Render()
{
	Window.Clear();

	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		AllActorVector[i]->Render(BackBufferPtr);
	}

	Window.ScreenRender();
}