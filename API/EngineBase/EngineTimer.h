#pragma once
#include <Windows.h>

// 시간을 체크할 수 있는 클래스
class UEngineTimer
{
public:
	// constrcuter destructer
	UEngineTimer();
	~UEngineTimer();

	// delete Function
	UEngineTimer(const UEngineTimer& _Other) = delete;
	UEngineTimer(UEngineTimer&& _Other) noexcept = delete;
	UEngineTimer& operator=(const UEngineTimer& _Other) = delete;
	UEngineTimer& operator=(UEngineTimer&& _Other) noexcept = delete;

	inline float GetDeltaTime() const
	{
		return fDeltaTime;
	}

	inline double GetDoubleDeltaTime() const
	{
		return DeltaTime;
	}

	void TimeCheck();
	void TimeStart();
	float End();
	double DEnd();

protected:

private:
	// LARGE_INTEGER : 정밀한 시간을 저장하기 위해 윈도우에서 제공하는 크기가 큰 정수형 자료형
	// 현재 시각과 이전 시각을 빼서 시간을 잰다. 
	LARGE_INTEGER Count = LARGE_INTEGER();		// 1초에 몇 번을 셀 수 있는지
	LARGE_INTEGER PrevTime = LARGE_INTEGER();
	LARGE_INTEGER CurTime = LARGE_INTEGER();
	
	double TimeCounter = 0.0f;
	double DeltaTime = 0.0;
	float fDeltaTime = 0.0f;
};

