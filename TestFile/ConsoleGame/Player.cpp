#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "GlobalValue.h"
#include "ConsoleEngine.h"

void Player::BeginPlay()
{
	Super::BeginPlay();

	RenderImage.Create({1, 1}, '@');
	FIntPoint MaxSpot = ConsoleEngine::GetWindowSize();
	FIntPoint StartSpot = { (MaxSpot.X / 2), ((MaxSpot.Y / 2) + 2) };
	SetActorLocation(StartSpot);
}

void Player::Tick()
{
	Super::Tick();
	// ConsoleEngine::MainPlayer

	// Ÿ���� ���� �ҷ��� ���.
	// ConsoleEngine::GetEngine().GetPlayer()

	// ConsoleImage& BackBuffer = *_BackBuffer;

	// static�� �����̴ϱ� ��ü�� �ʿ����.
	ConsoleEngine::GetWindow();
	ConsoleEngine::GetWindowSize();

	// ���� �ڵ� �Ȱǵ帮�� 
	GlobalValue::WindowPtr;
	GlobalValue::WindowSize;

	int Value = _kbhit();
	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			Dir = Enums::GAMEDIR::LEFT;
			break;
		case 'D':
		case 'd':
			Dir = Enums::GAMEDIR::RIGHT;
			break;
		case 'W':
		case 'w':
			Dir = Enums::GAMEDIR::UP;
			break;
		case 'S':
		case 's':
			Dir = Enums::GAMEDIR::DOWN;
			break;
		case 'Z':
		case 'z':
		{
			Bullet* NewBullet = ConsoleEngine::GetEngine().SpawnActor<Bullet>();

			// �Ѿ��� ���� �ö󰡰Ե� ���弼��.
			NewBullet->SetActorLocation(GetActorLocation());
			break;
		}
		default:
			break;
		}

	}

	switch (Dir)
	{
	case Enums::GAMEDIR::LEFT:
		AddActorLocation(FIntPoint::LEFT);
		break;
	case Enums::GAMEDIR::RIGHT:
		AddActorLocation(FIntPoint::RIGHT);
		break;
	case Enums::GAMEDIR::UP:
		AddActorLocation(FIntPoint::UP);
		break;
	case Enums::GAMEDIR::DOWN:
		AddActorLocation(FIntPoint::DOWN);
		break;
	default:
		break;
	}

	// Pos += FIntPoint::RIGHT;
}

