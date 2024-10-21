#include "Zone.h"
#include <conio.h>
#include <RpgBaseSystem/EngineDebug.h>


// 해당 지역이 이미 연결되어있는지 확인하는 함수
bool UZone::IsConnecting(UZone* _LinkZone)
{
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (_LinkZone == LinkZone[i])
		{
			return true;
		}
	}
	return false;
}

// 지역 연결 함수 (단방향)
bool UZone::Connecting(UZone* _LinkZone)
{
	// 예외 처리
	if (this == _LinkZone)
	{
		MSGASSERT("자신을 연결하려고 했습니다.");
		return false;
	}

	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("이미 연결된 지역을 연결하려고 했습니다.");
		return false;
	}

	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		// 만약 빈 곳이 있다면
		if (nullptr == LinkZone[i])
		{
			// 해당 지역과 현재 지역을 연결
			LinkZone[i] = _LinkZone;
			// 현재 연결 지역 수 증가
			SelectMax += 1;
			return true;
		}
	}

	MSGASSERT("이미 모든 지역에 연결되어 연결에 실패했습니다.");
	return false;
}

// 지역 연결 함수 (쌍방향)
bool UZone::InterConnecting(UZone* _LinkZone)
{
	_LinkZone->Connecting(this);
	this->Connecting(_LinkZone);
	return true;
}

// 이동할 수 있는 지역 랜더 함수
void UZone::ConnectingPrint()
{
	system("cls");
	
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (nullptr != LinkZone[i])
		{
			const char* NamePtr = LinkZone[i]->GetName();
			printf_s("%d. %s로 이동\n", (i + 1), NamePtr);
		}
	}
}

// 지역 이동 함수
UZone* UZone::ConnectingProgress()
{
	while (true)
	{
		ConnectingPrint();

		int Select = _getch();
		Select -= '0';

		if (Select > 0 && Select <= SelectMax)
		{
			return LinkZone[Select - 1];
		}
	}
	return nullptr;
}