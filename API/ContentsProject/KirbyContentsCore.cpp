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
	// 레벨 생성
	UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Play");

	// 해당 레벨 설정
	UEngineAPICore::GetCore()->OpenLevel("Play");
}

void KirbyContentsCore::Tick()
{
}

