#include "Zone.h"
#include <conio.h>
#include <RpgBaseSystem/EngineDebug.h>

bool UZone::Connecting(UZone* _LinkZone)
{
	// ���� ó��
	if (this == _LinkZone)
	{
		MSGASSERT("�ڽ��� �����Ϸ��� �߽��ϴ�.");
		return false;
	}

	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("�̹� ����� ������ �����Ϸ��� �߽��ϴ�.");
		return false;
	}

	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		// ���� �� ���� �ִٸ�
		if (nullptr == LinkZone[i])
		{
			// �ش� ������ ���� ������ ����
			LinkZone[i] = _LinkZone;
			// ���� ���� ���� �� ����
			SelectMax += 1;
			return true;
		}
	}

}
