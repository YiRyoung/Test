#include "PreCompile.h"
#include "Player.h"

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

}

void APlayer::Tick(float _DeltaTime)
{
	// ��ǻ���� ���ɰ� ������� ���� �ӷ����� ���������� �÷��̾ �̵�
	AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
}



