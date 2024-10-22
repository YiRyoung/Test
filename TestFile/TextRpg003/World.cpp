#include "World.h"
#include "Town.h"
#include "HuntZone.h"
#include "Player.h"
#include <RpgBaseSystem/EngineDebug.h>
#include <RpgBaseSystem/EngineFile.h>
#include <conio.h>

// 지역 준비 시키는 함수
void UWorld::ZoneInit()
{
	// 각 지역들의 이름 설정
	BasicTown.SetName("초보마을");
	MiddleTown.SetName("중급마을");
	BasicHunt.SetName("초보사냥터");

	// 초보마을과 초보사냥터는 서로 연결되어 있다.
	BasicTown.InterConnecting(&BasicHunt);
}

// 플레이어의 이름 생성 함수
void UWorld::PlayerNameSelect(APlayer& _Player)
{
	char InputName[NAMELEN] = { 0, };
	bool IsInput = true;
	bool IsEnd = false;

	while (!IsEnd)
	{
		if (IsInput)
		{
			system("cls");
			std::cout << "이름을 적어주세요.\n";
			std::cin >> InputName;
			IsInput = true;
		}

		system("cls");
		printf_s("당신의 이름은 %s입니다. 결정하시겠습니까?\n", InputName);
		printf_s("a. 결정\n");
		printf_s("b. 재입력\n");

		char Select = _getch();
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			continue;
		default:
			printf_s("잘못된 선택입니다. 다시 선택해주세요\n");
			Select = _getch();
			break;
		}
	}

	_Player.SetName(InputName);
}

// 플레이어 생성/준비 시키는 함수
void UWorld::PlayerInit(APlayer& _Player)
{
	UEngineFile File;
	File.SetPath("SaveFile.Dat");

	// 파일이 존재하지 않는다면
	if (false == File.IsExits())
	{
		// 쓰기 모드로 파일을 열고
		File.FileOpen("wb");

		// 플레이어의 이름 결정
		PlayerNameSelect(_Player);
		// 이름이 제대로 설정됐는지 확인
		const char* Name = _Player.GetName();

		// 결정된 이름을 파일에 저장
		File.Write(Name, NAMELEN);
	}
	else   // 파일이 존재한다면
	{
		// 읽기 모드로 파일을 열고
		File.FileOpen("rb");

		// 파일에 입력되어있는 이름을 불러온다.
		char Arr[NAMELEN] = { 0, };
		File.Read(Arr, NAMELEN);

		// 불러온 이름을 플레이어의 이름으로 설정한다.
		_Player.SetName(Arr);
	}
}



void UWorld::PlayerZonePlay(APlayer& _Player)
{
}


// 게임 접속 시
void  UWorld::InPlayer(class APlayer& _Player)
{

}