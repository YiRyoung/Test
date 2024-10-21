#include "Zone.h"
#include <conio.h>
#include <RpgBaseSystem/EngineDebug.h>


// �ش� ������ �̹� ����Ǿ��ִ��� Ȯ���ϴ� �Լ�
bool UZone::IsConnecting(UZone* _LinkZone)
{
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (_LinkZone == LinkZone[i])
		{
			return true;
		}
	}
	return false;
}

// ���� ���� �Լ� (�ܹ���)
bool UZone::Connecting(UZone* _LinkZone)
{
	// ���� ó��
	if (this == _LinkZone)
	{
		MSGASSERT("�ڽ��� �����Ϸ��� �߽��ϴ�.");
		return false;
	}

	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("�̹� ����� ������ �����Ϸ��� �߽��ϴ�.");
		return false;
	}

	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		// ���� �� ���� �ִٸ�
		if (nullptr == LinkZone[i])
		{
			// �ش� ������ ���� ������ ����
			LinkZone[i] = _LinkZone;
			// ���� ���� ���� �� ����
			SelectMax += 1;
			return true;
		}
	}

	MSGASSERT("�̹� ��� ������ ����Ǿ� ���ῡ �����߽��ϴ�.");
	return false;
}

// ���� ���� �Լ� (�ֹ���)
bool UZone::InterConnecting(UZone* _LinkZone)
{
	_LinkZone->Connecting(this);
	this->Connecting(_LinkZone);
	return true;
}

// �̵��� �� �ִ� ���� ���� �Լ�
void UZone::ConnectingPrint()
{
	system("cls");
	
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (nullptr != LinkZone[i])
		{
			const char* NamePtr = LinkZone[i]->GetName();
			printf_s("%d. %s�� �̵�\n", (i + 1), NamePtr);
		}
	}
}

// ���� �̵� �Լ�
UZone* UZone::ConnectingProgress()
{
	while (true)
	{
		ConnectingPrint();

		int Select = _getch();
		Select -= '0';

		if (Select > 0 && Select <= SelectMax)
		{
			return LinkZone[Select - 1];
		}
	}
	return nullptr;
}