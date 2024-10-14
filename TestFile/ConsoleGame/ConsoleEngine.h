#pragma once
#include "ConsoleWindow.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ActorVector.h"

class ConsoleEngine
{
	// void Update(); // 움직인다.
	// void Move(); // 움직인다.
public:
	static void Start();

	static FIntPoint GetWindowSize()
	{
		return WindowSize;
	}

	static UConsoleWindow& GetWindow()
	{
		return Window;
	}

	static ConsoleEngine& GetEngine()
	{
		return *MainEngine;
	}

	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();
		AllActorVector.push_back(NewActor);
		// 비긴플레이도 여기서 실행시켜준다.
		NewActor->BeginPlay();
		return NewActor;
	}

	//AActor* SpawnBullet()
	//{
	//	Bullet* NewActor = new Bullet();

	//	AllActorVector.push_back(NewActor);
	//	return NewActor;
	//}

	//AActor* SpawnMonster()
	//{
	//	Monster* NewActor = new Monster();

	//	AllActorVector.push_back(NewActor);
	//	return NewActor;
	//}

	// 이게 예제에서 나온 싱글톤이다.
	// 이놈의 싱글톤은 면접에서도 많이 물어봐서
	// 싱글톤의 핵심 => 프로그램에서 단 1개의 객체만 만든다.
	//                 어떠한 중점도 없다.
	//                 프로그램내에서 어떠한 클래스의 어떠한 
	//                 객체를 딱 1개만 만들게 제한하는 방법.
	
	//static ConsoleEngine* Inst;
	//ConsoleEngine* GetInst()
	//{
	//	if (nullptr == Inst)
	//	{
	//		Inst = new ConsoleEngine();
	//	}
	//	return Inst;
	//}

private:
	// 생성자를 막았어.
	ConsoleEngine();

	// 선언만 있고 실체는 존재하지 않기 때문에
	// 외부기호 오류가 뜬다.
	// 프로그램이 종료될때까지 파괴되지 않습니다.
	static FIntPoint WindowSize;
	static UConsoleWindow Window;

	static ConsoleEngine* MainEngine;

	// 화면에 존재할 모든 Actor을 담아서 관리한 단1개의 자료구조만 존재한다.
	ActorVector AllActorVector;

	void BeginPlay(); // 움직인다.
	void Tick(); // 움직인다.
	void Render(); // 그린다.
};

