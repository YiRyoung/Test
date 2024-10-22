#include "BlackSmith.h"
#include "Player.h"
#include <RpgBaseSystem/EngineDebug.h>
#include <conio.h>

void BlackSmith::InPlayer(class APlayer& _Player)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ� ���� ���õ��� �ʾҽ��ϴ�.");
		return;
	}
}

void BlackSmith::PrintBS(class APlayer& _Player)
{
	// 15�� �̻��̸� ��ȭ �Ұ�
	// 1~5������ ���� Ȯ���� ���������� �ٿ������ ����
	// 6~10������ �����ϸ� EquipAtt�� 1�� �ٿ��
	// 10~15�� ��ȭ ���� �� EquipAtt�� 0���� �ʱ�ȭ��.
	// ��ȭ ����� ���� ��ȭ�ܰ� * 100

	// UpgradeRender()
	while (true)
	{
		system("cls");
		_Player.StatusRender();
		printf_s("1. ���� ��ȭ\n");
		printf_s("2. ������ ���ư���\n");

		int Select = _getch();

		switch (Select)
		{
		case 1:
			TryUpgrade(_Player);
			break;
		case 2:
			return;
		default:
			break;
		}
	}

}

void BlackSmith::TryUpgrade(class APlayer& _Player)
{

	// 1. ���� indicate�� RightChild�� nullptr�� �ƴ��� Ȯ��
	// 2. indicate�� nullptr�� �ƴ϶�� LeftChild�� nullptr�϶� ���� ��������
	// 3.

	int CurrentEquipAtt = _Player.GetEquipAtt();
	int UpgradeCost = CurrentEquipAtt * 100;

	// ���� ��ȭġ�� �ִ��� ���
	if (15 >= CurrentEquipAtt)
	{
		printf_s("���� �ִ� ��ȭ �����Դϴ�!\n");
		return;
	}

	std::cout << "���� ��ȭ ��ġ : " << CurrentEquipAtt << std::endl;
	std::cout << "��ȭ ��� : " << UpgradeCost << std::endl;

	// ���� ���� ��尡 ��ȭ ��뺸�� ���� ���
	if (UpgradeCost < _Player.GetGold())
	{
		printf_s("�����Ͻ� ��尡 �����մϴ�!\n");
	}
}