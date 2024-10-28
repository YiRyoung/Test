#include "PreCompile.h"
#include "Level.h"

ULevel::ULevel()
{
}

ULevel::~ULevel()
{
	// �ͱ۸� ������ ������ ���� �޸� ����
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
	// ���� ������ ��ġ�� ��� ���͵��� ��ȸ
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		// ���� ����Ű�� ���͸� ���� �ݺ��ڷ� �Ͽ� ȣ��
		AActor* CurActor = *StartIter;

		// �ش� ������ Tick�Լ� ȣ��
		CurActor->Tick(_DeltaTime);
	}
}

void ULevel::Render()
{
	// �ش� ������ �ӽ� �ڵ��Դϴ�.
	std::list<AActor*>::iterator StartIter = AllActors.begin();
	std::list<AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;
		CurActor->Render();
	}
}

