#pragma once
#include <BaseSystem/EngineMath.h>
#include "ConsoleImage.h"


class AActor
{
public:
	virtual void BeginPlay();
	virtual void Tick();

	void Render(ConsoleImage* _BackBuffer);

	void SetActorLocation(FIntPoint _Pos);

	void AddActorLocation(FIntPoint _Pos);

	inline bool IsCollision(AActor& _Def)
	{
		FIntPoint PosA = GetActorLocation();
		FIntPoint PosB = _Def.GetActorLocation();
		if (PosA.X == PosB.X && PosA.Y == PosB.Y) 
		{ 
			return true;
			// true��� �����ϴ� �Լ��� ���� �̾� ���̱�?
		}
		else
		{
			return false;
		}
	}

	inline FIntPoint GetActorLocation()
	{
		return	this->Pos;
	}

protected:
	ConsoleImage RenderImage;

private:
	FIntPoint Pos;
	// �����Ҵ� �Ұų� ���ų�?
};

typedef AActor Super;