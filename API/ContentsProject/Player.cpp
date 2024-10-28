#include "PreCompile.h"
#include "Player.h"

APlayer::APlayer()
{
	// 해당 게임 모드 가져오기
	// UEngineAPICore::GetCore()->CreateLevel("Title");

	// 해당 플레이어의 위치 및 크기 정보 설정
	SetActorLocation({ 100, 100 });
	SetActorScale({ 100, 100 });
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{

}

void APlayer::Tick(float _DeltaTime)
{
	// 컴퓨터의 성능과 상관없이 같은 속력으로 오른쪽으로 플레이어를 이동
	AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
}



