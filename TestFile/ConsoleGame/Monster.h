#pragma once
#include "Actor.h"

class Monster : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;
};

