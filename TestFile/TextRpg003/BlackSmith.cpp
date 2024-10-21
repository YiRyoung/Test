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