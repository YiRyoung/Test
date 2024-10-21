#pragma once
#include "StatusUnit.h"
#include "ContentsConst.h"

// �������� ���� Ŭ����
class UZone : public UObject
{
public:
	inline void InMsgPrint()
	{
		system("cls");
		std::cout << GetName() << "�� �����߽��ϴ�.\n";
	}

	inline void ZonePrint()
	{
		std::cout << GetName() << "�� ü�� ��.\n";
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
	// ����� �������� �迭
	UZone* LinkZone[LINKZONEMAX] = { nullptr, };

	int SelectMax = 0;
};

