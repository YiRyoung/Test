#include "PreCompile.h"
#include "KirbyContentsCore.h"
#include <EngineCore/EngineAPICore.h>

#include "PlayGameMode.h"
#include "Player.h"

KirbyContentsCore::KirbyContentsCore()
{
}

KirbyContentsCore::~KirbyContentsCore()
{

}

void KirbyContentsCore::BeginPlay()
{
	// Ÿ��Ʋ �̸� ����
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Kirby's Adventure");

	// ���� ����
	UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Play");

	// �ش� ���� ����
	UEngineAPICore::GetCore()->OpenLevel("Play");
}

void KirbyContentsCore::Tick()
{
}

