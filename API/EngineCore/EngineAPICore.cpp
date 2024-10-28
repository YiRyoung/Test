#include "PreCompile.h"
#include "EngineAPICore.h"

#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineDelegate.h>
#include <EngineBase/EngineDebug.h>

// staic 초기화
UEngineAPICore* UEngineAPICore::MainCore = nullptr;
UContentsCore* UEngineAPICore::UserCore = nullptr;

UEngineAPICore::UEngineAPICore()
{
}

UEngineAPICore::~UEngineAPICore()
{
	std::map<std::string, class ULevel*>::iterator StartIter = Levels.begin();
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
			StartIter->second = nullptr;
		}
	}

	Levels.clear();
}

int UEngineAPICore::EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore)
{
	// 릭 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UserCore = _UserCore;
	
	// 그저 윈도우 창을 생성하는 과정을 객체지향으로 포장한 것
	UEngineWindow::EngineWindowInit(_Inst);
	UEngineAPICore Core = UEngineAPICore();
	Core.EngineMainWindow.Open();
	MainCore = &Core;

	// 엔진 전체 흐름을 제어하는 EngineBeginPlay 및 EngineTick 실행
	EngineDelegate Start = EngineDelegate(std::bind(EngineBeginPlay));
	EngineDelegate FrameLoop = EngineDelegate(std::bind(EngineTick));
	return UEngineWindow::WindowMessageLoop(Start, FrameLoop);
}



void UEngineAPICore::EngineBeginPlay()
{
	UserCore->BeginPlay();
}

void UEngineAPICore::EngineTick()
{
	UserCore->Tick();	// 아직 사용처 X
	MainCore->Tick();
}

void UEngineAPICore::Tick()
{
	// 프레임 구하는 함수
	DeltaTimer.TimeCheck();
	float DeltaTime = DeltaTimer.GetDeltaTime();

	if (nullptr == CurLevel)
	{
		MSGASSERT("엔진에 현재 레벨이 지정되지 않았습니다.");
		return;
	}

	CurLevel->Tick(DeltaTime);
	CurLevel->Render();
}

void UEngineAPICore::OpenLevel(std::string_view _LevelName)
{
	// 레벨의 이름을 string으로 변환
	std::string ChangeName = _LevelName.data();

	std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(ChangeName);
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();

	// 찾으려는 레벨이 존재하지 않을 경우
	if (EndIter == FindIter)
	{
		MSGASSERT(ChangeName + "라는 이름의 레벨이 존재하지 않습니다.");
		return;
	}

	// 찾은 레벨을 현재 레벨로 설정
	CurLevel = FindIter->second;
}