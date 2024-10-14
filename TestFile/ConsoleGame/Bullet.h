#pragma once
#include "Actor.h"

class Bullet : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;
};

