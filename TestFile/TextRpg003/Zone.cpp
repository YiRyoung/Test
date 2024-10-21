#include "Zone.h"
#include <conio.h>
#include <RpgBaseSystem/EngineDebug.h>

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

}
