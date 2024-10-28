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
	// 타이틀 이름 변경
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Kirby's Adventure");

	// 레벨 생성
	UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Play");

	// 해당 레벨 설정
	UEngineAPICore::GetCore()->OpenLevel("Play");
}

void KirbyContentsCore::Tick()
{
}

