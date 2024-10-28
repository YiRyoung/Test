#pragma once
#include "GameMode.h"

class ULevel
{
public:
	// friend class : friend한 클래스의 멤버 정보를 일방적으로 public 접근 가능
	friend class UEngineAPICore;

	// constrcuter destructer
	ULevel();
	~ULevel();

	// delete Function
	ULevel(const ULevel& _Other) = delete;
	ULevel(ULevel&& _Other) noexcept = delete;
	ULevel& operator=(const ULevel& _Other) = delete;
	ULevel& operator=(ULevel&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);
	void Render();

	// 액터를 HDC 위에 그리는 함수
	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();
		// dynamic_cast : 상속 관계에서의 형 변환으로, 업캐스팅일 경우에는 암시적으로 형 변환된다.
		AActor* ActorPtr = dynamic_cast<AActor*>(NewActor);
		ActorPtr->World = this;	// 해당 액터의 레벨을 현재 레벨로 설정

		NewActor->BeginPlay();	// 액터의 BeginPlay 실행
		AllActors.push_back(NewActor);	// 현재 레벨에 위치한 모든 액터 리스트에 추가
		return NewActor;
	}

protected:

private:
	// 게임 준비 함수
	template<typename GameModeType, typename MainPawnType>
	void CreateGameMode()
	{
		GameMode = new GameModeType();
		MainPawn = new MainPawnType();

		// 각 객체의 World 포인터에 현태 클래스를 가리키도록 설정
		MainPawn->World = this;
		GameMode->World = this;

		// 각 객체의 BeginPlay 함수 호출
		GameMode->BeginPlay();
		MainPawn->BeginPlay();

		// AllActors 리스트에 해당 객체들을 추가 등록
		AllActors.push_back(GameMode);
		AllActors.push_back(MainPawn);
	}

	// 컴포넌트 구조
	AGameMode* GameMode = nullptr;	// 현재 게임모드
	AActor* MainPawn = nullptr;		// 현재 주인공
	std::list<AActor*> AllActors;	// 모든 액터 리스트
};

