#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineInput.h>

APlayer::APlayer()
{
	// �ش� ���� ��� ��������
	// UEngineAPICore::GetCore()->CreateLevel("Title");

	// �ش� �÷��̾��� ��ġ �� ũ�� ���� ����
	SetActorLocation({ 100, 100 });
	SetActorScale({ 100, 100 });
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	// �̺�Ʈ ������� ó��
	UEngineInput::GetInst().BindAction('A', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::LEFT));
	UEngineInput::GetInst().BindAction('D', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::RIGHT));
	UEngineInput::GetInst().BindAction('S', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::DOWN));
	UEngineInput::GetInst().BindAction('W', KeyEvent::Press, std::bind(&APlayer::MoveFunction, this, FVector2D::UP));
}

void APlayer::Tick(float _DeltaTime)
{
	// ��ǻ���� ���ɰ� ������� ���� �ӷ����� ���������� �÷��̾ �̵�
	//AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
}

void APlayer::MoveFunction(FVector2D _Dir/*, AMonster* Monster*/)
{
	// ���͸� ã�ƿ��� �Լ��� �����Ұ��̴�.
	// ���� ��ü�� �����ϱ� ������.
	// ã�ƿ��� �Լ��� �����մϴ�.

	float DeltaTime = UEngineAPICore::GetCore()->GetDeltaTime();

	AddActorLocation(_Dir * DeltaTime * Speed);
}



