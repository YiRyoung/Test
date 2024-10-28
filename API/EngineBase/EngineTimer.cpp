#include "PreCompile.h"
#include "EngineTimer.h"

UEngineTimer::UEngineTimer()
{
    // 1�ʿ� �󸶸� �� �� �ִ��� 
    QueryPerformanceFrequency(&Count);
    TimeCounter = static_cast<double>(Count.QuadPart);

    // ���� ���� �ʱ�ȭ�� ���� ���� ī���Ͱ� ����
    QueryPerformanceCounter(&PrevTime);
    QueryPerformanceCounter(&CurTime);
}

UEngineTimer::~UEngineTimer()
{
}

void UEngineTimer::TimeCheck()
{
    // ���� �ð� ����
    QueryPerformanceCounter(&CurTime);

    // ���� �ð��� ���� �ð��� ���̸� ���ؼ� �� ������ ��ȯ
    double Tick = static_cast<double>(CurTime.QuadPart - PrevTime.QuadPart);
    DeltaTime = Tick / TimeCounter;
    fDeltaTime = static_cast<float>(DeltaTime);

    // ���� �ð��� PrevTime�� �����Ͽ� ���� ȣ�� �� ���� �ð����� ���
    PrevTime.QuadPart = CurTime.QuadPart;
}

void UEngineTimer::TimeStart()
{
    // ���ο� ���� �ð��� �����ϱ� ���� ���� �ð��� PrevTime�� ����
    QueryPerformanceCounter(&PrevTime);
}

float UEngineTimer::End()
{
    TimeCheck();
    return GetDeltaTime();
}

double UEngineTimer::DEnd()
{
    TimeCheck();
    return GetDoubleDeltaTime();
}
