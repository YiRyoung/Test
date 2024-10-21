#pragma once
#include "StatusUnit.h"
#include "ContentsConst.h"

// 지역들의 상위 클래스
class UZone : public UObject
{
public:
	inline void InMsgPrint()
	{
		system("cls");
		std::cout << GetName() << "에 입장했습니다.\n";
	}

	inline void ZonePrint()
	{
		std::cout << GetName() << "에 체류 중.\n";
	}

	bool IsConnecting(UZone* _LinkZone);

	bool Connecting(UZone* _LinkZone);

	bool InterConnecting(UZone* _LinkZone);

	void ConnectingPrint();

	UZone* ConnectingProgress();

	virtual UZone* InPlayer(class APlayer& _Player)
	{
		return nullptr;
	}

private:
	// 연결된 지역들의 배열
	UZone* LinkZone[LINKZONEMAX] = { nullptr, };

	int SelectMax = 0;
};

