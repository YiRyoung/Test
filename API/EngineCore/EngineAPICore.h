#pragma once
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineTimer.h>

#pragma comment (lib, "EngineBase.lib")
#pragma comment (lib, "EnginePlatform.lib")

#include "Level.h"

class UContentsCore
{
public:
	// �ٸ� ��ü���� �������̽� �Լ�
	// ������ �� ȣ���� ���� ���� �Լ�
	virtual void BeginPlay() = 0;
	// �� �����Ӹ��� ȣ���� ���� ���� �Լ�
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
	// EngineStart : ������ ���� ������
	// int ������ main �Լ����� ���α׷� ������ ���
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
		// ���� ����
		ULevel* NewLevel = new ULevel();

		// �������� ���ο� ���� ��� ����
		NewLevel->CreateGameMode<GameModeType, MainPawnType>();

		// �������� �����ϴ� �ʿ� ���� ���� ���� ���
		Levels.insert({ _LevelName.data() , NewLevel });

		return NewLevel;
	}

	// �ش� ���� ����
	void OpenLevel(std::string_view _LevelName);
	
protected:

private:
	// static ����
	// ���� ��ü�� �帧 ����
	static void EngineBeginPlay();
	static void EngineTick();
	static UEngineAPICore* MainCore;
	static UContentsCore* UserCore;

	// ���� ���� ������
	UEngineWindow EngineMainWindow = UEngineWindow();
	UEngineTimer DeltaTimer = UEngineTimer();

	// ������� ��� �������� �����ϴ� ��
	std::map<std::string, class ULevel*> Levels;

	// ���� ���� ���� (������ ü���� ������� ����)
	class ULevel* CurLevel = nullptr;

	void Tick();
};

