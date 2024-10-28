#include "PreCompile.h"
#include "EngineAPICore.h"

#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineWindow.h>
#include <EngineBase/EngineDelegate.h>
#include <EngineBase/EngineDebug.h>

// staic �ʱ�ȭ
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
	// �� üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UserCore = _UserCore;
	
	// ���� ������ â�� �����ϴ� ������ ��ü�������� ������ ��
	UEngineWindow::EngineWindowInit(_Inst);
	UEngineAPICore Core = UEngineAPICore();
	Core.EngineMainWindow.Open();
	MainCore = &Core;

	// ���� ��ü �帧�� �����ϴ� EngineBeginPlay �� EngineTick ����
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
	UserCore->Tick();	// ���� ���ó X
	MainCore->Tick();
}

void UEngineAPICore::Tick()
{
	// ������ ���ϴ� �Լ�
	DeltaTimer.TimeCheck();
	float DeltaTime = DeltaTimer.GetDeltaTime();

	// Űüũ
	// �̱��� ����� ����Ͽ� UEngineInput�� �ν��Ͻ��� �� ���� ����
	UEngineInput::GetInst().KeyCheck(DeltaTime);

	if (nullptr == CurLevel)
	{
		MSGASSERT("���� �ھ ���� ������ �������� �ʾҽ��ϴ�");
		return;
	}

	// �̺�Ʈ �߻� üũ
	UEngineInput::GetInst().EventCheck(DeltaTime);
	CurLevel->Tick(DeltaTime);
	CurLevel->Render();
}

void UEngineAPICore::OpenLevel(std::string_view _LevelName)
{
	// ������ �̸��� string���� ��ȯ
	std::string ChangeName = _LevelName.data();

	std::map<std::string, class ULevel*>::iterator FindIter = Levels.find(ChangeName);
	std::map<std::string, class ULevel*>::iterator EndIter = Levels.end();

	// ã������ ������ �������� ���� ���
	if (EndIter == FindIter)
	{
		MSGASSERT(ChangeName + "��� �̸��� ������ �������� �ʽ��ϴ�.");
		return;
	}

	// ã�� ������ ���� ������ ����
	CurLevel = FindIter->second;
}