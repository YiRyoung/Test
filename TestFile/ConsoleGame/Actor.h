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
			// true라면 삭제하는 함수를 만들어서 이어 붙이기?
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
	// 동적할당 할거냐 말거냐?
};

typedef AActor Super;