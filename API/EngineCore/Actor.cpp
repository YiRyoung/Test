#include "PreCompile.h"
#include "Actor.h"
#include <EngineCore/EngineAPICore.h>

AActor::AActor()
{
}

AActor::~AActor()
{
}

void AActor::Render()
{
	// 화면의 좌측 상단 (원점 - 현재 위치의 절반)
	FVector2D LeftTop = Location - Scale.Half();
	FVector2D RightBot = Location + Scale.Half();

	// 메인 윈도우 가져오기
	UEngineWindow& MainWindow = UEngineAPICore::GetCore()->GetMainWindow();
	// 메인 윈도우의 그리기 도구 핸들 가져오기
	HDC BackHDC = MainWindow.GetBackBuffer();

	// 사각형 그리기 (HDC, 점 4개의 좌표)
	Rectangle(BackHDC, LeftTop.iX(), LeftTop.iY(), RightBot.iX(), RightBot.iY());
}

