#pragma once
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineTimer.h>

#pragma comment (lib, "EngineBase.lib")
#pragma comment (lib, "EnginePlatform.lib")

#include "Level.h"

class UContentsCore
{
public:
	// 다른 객체들의 인터페이스 함수
	// 시작할 때 호출할 순수 가상 함수
	virtual void BeginPlay() = 0;
	// 매 프레임마다 호출할 순수 가상 함수
	virtual void Tick() = 0;
};

class UEngineAPICore
{
public:
	// constrcuter destructer
	UEngineAPICore();
	~UEngineAPICore();

	// delete Function
	UEngineAPICore(const UEngineAPICore& _Other) = delete;
	UEngineAPICore(UEngineAPICore&& _Other) noexcept = delete;
	UEngineAPICore& operator=(const UEngineAPICore& _Other) = delete;
	UEngineAPICore& operator=(UEngineAPICore&& _Other) noexcept = delete;

	// static Function
	// EngineStart : 엔진의 메인 진입점
	// int 형으로 main 함수에서 프로그램 시작을 담당
	static int EngineStart(HINSTANCE _Inst, UContentsCore* _UserCore);

	static class UEngineAPICore* GetCore()
	{
		return MainCore;
	}

	UEngineWindow& GetMainWindow()
	{
		return EngineMainWindow;
	}

	template<typename GameModeType, typename MainPawnType>
	ULevel* CreateLevel(std::string_view _LevelName)
	{
		// 레벨 생성
		ULevel* NewLevel = new ULevel();

		// 레벨에서 새로운 게임 모드 생성
		NewLevel->CreateGameMode<GameModeType, MainPawnType>();

		// 레벨들을 저장하는 맵에 새로 만든 맵을 등록
		Levels.insert({ _LevelName.data() , NewLevel });

		return NewLevel;
	}

	// 해당 레벨 열기
	void OpenLevel(std::string_view _LevelName);
	
protected:

private:
	// static 변수
	// 엔진 전체의 흐름 제어
	static void EngineBeginPlay();
	static void EngineTick();
	static UEngineAPICore* MainCore;
	static UContentsCore* UserCore;

	// 엔진 메인 윈도우
	UEngineWindow EngineMainWindow = UEngineWindow();
	UEngineTimer DeltaTimer = UEngineTimer();

	// 만들어진 모든 레벨들을 저장하는 맵
	std::map<std::string, class ULevel*> Levels;

	// 현재 레벨 변수 (포인터 체인지 방식으로 변경)
	class ULevel* CurLevel = nullptr;

	void Tick();
};

