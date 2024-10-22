#include "BlackSmith.h"
#include "Player.h"
#include <RpgBaseSystem/EngineDebug.h>
#include <conio.h>

void BlackSmith::InPlayer(class APlayer& _Player)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("부모 존이 세팅되지 않았습니다.");
		return;
	}
}

void BlackSmith::PrintBS(class APlayer& _Player)
{
	// 15강 이상이면 강화 불가
	// 1~5까지는 실패 확률이 존재하지만 다운되지는 않음
	// 6~10까지는 실패하면 EquipAtt가 1씩 다운됨
	// 10~15는 강화 실패 시 EquipAtt가 0으로 초기화됨.
	// 강화 비용은 현재 강화단계 * 100

	// UpgradeRender()
	while (true)
	{
		system("cls");
		_Player.StatusRender();
		printf_s("1. 무기 강화\n");
		printf_s("2. 마을로 돌아가기\n");

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

	// 1. 현재 indicate의 RightChild가 nullptr이 아닌지 확인
	// 2. indicate가 nullptr이 아니라면 LeftChild가 nullptr일때 까지 내려간다
	// 3.

	int CurrentEquipAtt = _Player.GetEquipAtt();
	int UpgradeCost = CurrentEquipAtt * 100;

	// 무기 강화치가 최대인 경우
	if (15 >= CurrentEquipAtt)
	{
		printf_s("현재 최대 강화 상태입니다!\n");
		return;
	}

	std::cout << "현재 강화 수치 : " << CurrentEquipAtt << std::endl;
	std::cout << "강화 비용 : " << UpgradeCost << std::endl;

	// 가진 보유 골드가 강화 비용보다 적은 경우
	if (UpgradeCost < _Player.GetGold())
	{
		printf_s("보유하신 골드가 부족합니다!\n");
	}
}