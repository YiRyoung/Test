#include "PreCompile.h"
#include "Level.h"

ULevel::ULevel()
{
}

ULevel::~ULevel()
{
	// 맹글링 포인터 방지를 위한 메모리 해제
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;

		if (nullptr != CurActor)
		{
			delete* StartIter;
		}
	}
}

void ULevel::Tick(float _DeltaTime)
{
	// 현재 레벨에 배치된 모든 액터들을 순회
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		// 현재 가리키는 액터를 시작 반복자로 하여 호출
		AActor* CurActor = *StartIter;

		// 해당 액터의 Tick함수 호출
		CurActor->Tick(_DeltaTime);
	}
}

void ULevel::Render()
{
	// 해당 구문은 임시 코드입니다.
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;
		CurActor->Render();
	}
}

