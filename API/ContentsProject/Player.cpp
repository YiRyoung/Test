#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineInput.h>
#include "Bullet.h"

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
	// 이벤트 방식으로 처리
	UEngineInput::GetInst().BindAction('A', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::LEFT));
	UEngineInput::GetInst().BindAction('D', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::RIGHT));
	UEngineInput::GetInst().BindAction('S', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::DOWN));
	UEngineInput::GetInst().BindAction('W', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::UP));
}

void APlayer::MoveFunction(FVector2D _Dir/*, AMonster* Monster*/)
{
	// 몬스터를 찾아오는 함수가 존재할것이다.
	// 액터 전체르 관리하기 때문에.
	// 찾아오는 함수가 존재합니다.

	float DeltaTime = UEngineAPICore::GetCore()->GetDeltaTime();

	AddActorLocation(_Dir * DeltaTime * Speed);
}

void APlayer::Tick(float _DeltaTime)
{
	// 컴퓨터의 성능과 상관없이 같은 속력으로 오른쪽으로 플레이어를 이동
	//AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
	if (3.0f < UEngineInput::GetInst().IsPreeTime(VK_LBUTTON))
	{
		ABullet* Ptr = GetWorld()->SpawnActor<ABullet>();
		Ptr->SetActorLocation(GetActorLocation());
	}
}


