#pragma once
#include "ConsoleImage.h"
#include "Actor.h"

//class AActor
//{
//	FIntPoint Location;
//};
//
//class Monster
//{
//	
//};

// 화면어딘가에 이녀석이 랜더링
// 일반적인 게임엔진
class Player : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

private:
};

