#pragma once
#include <EngineBase/EngineDelegate.h>

// ������ ���� Ŭ����
class UEngineWindow
{
public:
	// static Function
	static void EngineWindowInit(HINSTANCE _Instance);	// ������ Ŭ���� ���
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
	static HINSTANCE hInstance;	// ���� ������
	static std::map<std::string, WNDCLASSEXA> WindowClasses;	// ������ Ŭ������ <Ű, ��>���� ����

	HDC BackBuffer = nullptr;		// �������� �׸��� â �ڵ�
	HWND WindowHandle = nullptr;	// ������ â �ڵ�
};

