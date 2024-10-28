#include "PreCompile.h"
#include "EngineTimer.h"

UEngineTimer::UEngineTimer()
{
    // 1초에 얼마를 셀 수 있는지 
    QueryPerformanceFrequency(&Count);
    TimeCounter = static_cast<double>(Count.QuadPart);

    // 시작 지점 초기화를 위한 현재 카운터값 저장
    QueryPerformanceCounter(&PrevTime);
    QueryPerformanceCounter(&CurTime);
}

UEngineTimer::~UEngineTimer()
{
}

void UEngineTimer::TimeCheck()
{
    // 현재 시각 저장
    QueryPerformanceCounter(&CurTime);

    // 현재 시간과 이전 시간의 차이를 구해서 초 단위로 변환
    double Tick = static_cast<double>(CurTime.QuadPart - PrevTime.QuadPart);
    DeltaTime = Tick / TimeCounter;
    fDeltaTime = static_cast<float>(DeltaTime);

    // 현재 시각을 PrevTime에 저장하여 다음 호출 시 이전 시각으로 사용
    PrevTime.QuadPart = CurTime.QuadPart;
}

void UEngineTimer::TimeStart()
{
    // 새로운 시작 시각을 설정하기 위해 현재 시간을 PrevTime에 저장
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
