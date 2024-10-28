#pragma once
#include <Windows.h>

// �ð��� üũ�� �� �ִ� Ŭ����
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
	// LARGE_INTEGER : ������ �ð��� �����ϱ� ���� �����쿡�� �����ϴ� ũ�Ⱑ ū ������ �ڷ���
	// ���� �ð��� ���� �ð��� ���� �ð��� ���. 
	LARGE_INTEGER Count = LARGE_INTEGER();		// 1�ʿ� �� ���� �� �� �ִ���
	LARGE_INTEGER PrevTime = LARGE_INTEGER();
	LARGE_INTEGER CurTime = LARGE_INTEGER();
	
	double TimeCounter = 0.0f;
	double DeltaTime = 0.0;
	float fDeltaTime = 0.0f;
};

