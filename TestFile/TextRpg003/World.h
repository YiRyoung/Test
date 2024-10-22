#pragma once
#include "Town.h"
#include "HuntZone.h"

class UWorld
{
public:
	void InPlayer(class APlayer& _Player);

private:

	void ZoneInit();
	void PlayerInit(class APlayer& _Player);
	void PlayerNameSelect(class APlayer& _Player);
	void PlayerZonePlay(class APlayer& _Player);

	UTown BasicTown;
	UTown MiddleTown;
	UHuntZone BasicHunt;
};

