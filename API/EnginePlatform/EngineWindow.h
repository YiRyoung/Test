#pragma once
#include <EngineBase/EngineDelegate.h>

// 윈도우 관련 클래스
class UEngineWindow
{
public:
	// static Function
	static void EngineWindowInit(HINSTANCE _Instance);	// 윈도우 클래스 등록
	static void CreateWindowClass(const WNDCLASSEXA& _Class);

	static int WindowMessageLoop(EngineDelegate _StartFunction, EngineDelegate _FrameFunction);

	// constrcuter destructer
	UEngineWindow();
	~UEngineWindow();

	// delete Function
	UEngineWindow(const UEngineWindow& _Other) = delete;
	UEngineWindow(UEngineWindow&& _Other) noexcept = delete;
	UEngineWindow& operator=(const UEngineWindow& _Other) = delete;
	UEngineWindow& operator=(UEngineWindow&& _Other) noexcept = delete;

	void Create(std::string_view _TitleName, std::string_view _ClassName = "Default");
	void Open(std::string_view _TitleName = "Kirby's Adventure");

	inline HDC GetBackBuffer()
	{
		return BackBuffer;
	}

protected:

private:
	static HINSTANCE hInstance;	// 현재 윈도우
	static std::map<std::string, WNDCLASSEXA> WindowClasses;	// 윈도우 클래스를 <키, 값>으로 정리

	HDC BackBuffer = nullptr;		// 윈도우의 그리기 창 핸들
	HWND WindowHandle = nullptr;	// 윈도우 창 핸들
};

