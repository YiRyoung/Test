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
	// ȭ���� ���� ��� (���� - ���� ��ġ�� ����)
	FVector2D LeftTop = Location - Scale.Half();
	FVector2D RightBot = Location + Scale.Half();

	// ���� ������ ��������
	UEngineWindow& MainWindow = UEngineAPICore::GetCore()->GetMainWindow();
	// ���� �������� �׸��� ���� �ڵ� ��������
	HDC BackHDC = MainWindow.GetBackBuffer();

	// �簢�� �׸��� (HDC, �� 4���� ��ǥ)
	Rectangle(BackHDC, LeftTop.iX(), LeftTop.iY(), RightBot.iX(), RightBot.iY());
}

