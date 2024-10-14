#include "Monster.h"
#include "ConsoleEngine.h"

void Monster::BeginPlay()
{
	Super::BeginPlay();
	RenderImage.Create({ 1, 1 }, '#');
	FIntPoint MaxSpot = ConsoleEngine::GetWindowSize();
	FIntPoint StartSpot = { (MaxSpot.X / 2), 1 };
	SetActorLocation(StartSpot);
}

void Monster::Tick()
{
	Super::Tick();
}