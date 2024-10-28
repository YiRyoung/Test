#pragma once
#include "GameMode.h"

class ULevel
{
public:
	// friend class : friend�� Ŭ������ ��� ������ �Ϲ������� public ���� ����
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

	// ���͸� HDC ���� �׸��� �Լ�
	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();
		// dynamic_cast : ��� ���迡���� �� ��ȯ����, ��ĳ������ ��쿡�� �Ͻ������� �� ��ȯ�ȴ�.
		AActor* ActorPtr = dynamic_cast<AActor*>(NewActor);
		ActorPtr->World = this;	// �ش� ������ ������ ���� ������ ����

		NewActor->BeginePlay();	// ������ BeginPlay ����
		AllActors.push_back(NewActor);	// ���� ������ ��ġ�� ��� ���� ����Ʈ�� �߰�
		return NewActor;
	}

protected:

private:
	// ���� �غ� �Լ�
	template<typename GameModeType, typename MainPawnType>
	void CreateGameMode()
	{
		GameMode = new GameModeType();
		MainPawn = new MainPawnType();

		// �� ��ü�� World �����Ϳ� ���� Ŭ������ ����Ű���� ����
		MainPawn->World = this;
		GameMode->World = this;

		// �� ��ü�� BeginPlay �Լ� ȣ��
		GameMode->BeginPlay();
		MainPawn->BeginPlay();

		// AllActors ����Ʈ�� �ش� ��ü���� �߰� ���
		AllActors.push_back(GameMode);
		AllActors.push_back(MainPawn);
	}

	// ������Ʈ ����
	AGameMode* GameMode = nullptr;	// ���� ���Ӹ��
	AActor* MainPawn = nullptr;		// ���� ���ΰ�
	std::list<AActor*> AllActors;	// ��� ���� ����Ʈ
};

