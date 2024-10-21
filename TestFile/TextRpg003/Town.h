#pragma once
#include "Zone.h"
// #include "BlackSmith.h"

class UTown : public UZone
{
public:
	UTown();

	UZone* InPlayer(class APlayer& _Player);
private:
	// BlackSmith BS;
};

