#include "World.h"
#include "Town.h"
#include "HuntZone.h"
#include "Player.h"
#include <RpgBaseSystem/EngineDebug.h>
#include <RpgBaseSystem/EngineFile.h>
#include <conio.h>

// ���� �غ� ��Ű�� �Լ�
void UWorld::ZoneInit()
{
	// �� �������� �̸� ����
	BasicTown.SetName("�ʺ�����");
	MiddleTown.SetName("�߱޸���");
	BasicHunt.SetName("�ʺ������");

	// �ʺ������� �ʺ�����ʹ� ���� ����Ǿ� �ִ�.
	BasicTown.InterConnecting(&BasicHunt);
}

// �÷��̾��� �̸� ���� �Լ�
void UWorld::PlayerNameSelect(APlayer& _Player)
{
	char InputName[NAMELEN] = { 0, };
	bool IsInput = true;
	bool IsEnd = false;

	while (!IsEnd)
	{
		if (IsInput)
		{
			system("cls");
			std::cout << "�̸��� �����ּ���.\n";
			std::cin >> InputName;
			IsInput = true;
		}

		system("cls");
		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");

		char Select = _getch();
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			continue;
		default:
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
			Select = _getch();
			break;
		}
	}

	_Player.SetName(InputName);
}

// �÷��̾� ����/�غ� ��Ű�� �Լ�
void UWorld::PlayerInit(APlayer& _Player)
{
	UEngineFile File;
	File.SetPath("SaveFile.Dat");

	// ������ �������� �ʴ´ٸ�
	if (false == File.IsExits())
	{
		// ���� ���� ������ ����
		File.FileOpen("wb");

		// �÷��̾��� �̸� ����
		PlayerNameSelect(_Player);
		// �̸��� ����� �����ƴ��� Ȯ��
		const char* Name = _Player.GetName();

		// ������ �̸��� ���Ͽ� ����
		File.Write(Name, NAMELEN);
	}
	else   // ������ �����Ѵٸ�
	{
		// �б� ���� ������ ����
		File.FileOpen("rb");

		// ���Ͽ� �ԷµǾ��ִ� �̸��� �ҷ��´�.
		char Arr[NAMELEN] = { 0, };
		File.Read(Arr, NAMELEN);

		// �ҷ��� �̸��� �÷��̾��� �̸����� �����Ѵ�.
		_Player.SetName(Arr);
	}
}



void UWorld::PlayerZonePlay(APlayer& _Player)
{
}


// ���� ���� ��
void  UWorld::InPlayer(class APlayer& _Player)
{

}