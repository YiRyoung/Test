#include "HuntZone.h"
#include "Monster.h"
#include "Player.h"
#include <conio.h>

UZone* UHuntZone::InPlayer(class APlayer& _Player)
{
	InMsgPrint();
	char Ch = _getch();

	UMonster NewMonster;

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		NewMonster.StatusRender();
		Ch = _getch();
	}
}