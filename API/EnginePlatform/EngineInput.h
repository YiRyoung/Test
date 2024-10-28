#pragma once

#include <EngineBase/EngineDelegate.h>
#include <EngineBase/EngineDebug.h>

enum class KeyEvent
{
	Down,
	Press,
	Free,
	Up,
};

class UEngineInput
{
public:
	// constrcuter destructer
	~UEngineInput();

	// delete Function
	UEngineInput(const UEngineInput& _Other) = delete;
	UEngineInput(UEngineInput&& _Other) noexcept = delete;
	UEngineInput& operator=(const UEngineInput& _Other) = delete;
	UEngineInput& operator=(UEngineInput&& _Other) noexcept = delete;

	// 지역 static 값형 싱글톤
	// 프로그램을 통틀어 한 개의 객체를 가지게끔 하는 것을 싱글톤이라고 한다.
	// 지역으로 선언했기 때문에 외부에 공개하기 까다롭지만,
	// 만들기가 쉽고 코드가 짧아져서 선호하는 방법.
	// static의 특성 때문에 데이터 영역에 한 번 할당 후에는 해당 객체를 반환한다.
	static UEngineInput& GetInst()
	{
		static UEngineInput Inst = UEngineInput();
		return Inst;
	}

protected:

private:
	// 입력 키 관련 클래스
	class UEngineKey
	{
	public:
		int Key = -1;

		// 키가 눌렸을 때
		bool IsDown = false;
		// 키가 계속 눌려있는 상태일 때
		bool IsPress = false;
		// 키를 뗐을 때
		bool IsUp = false;
		// 키를 안 누르고 있을 때
		bool IsFree = true;

		// 키를 누른 시간 측정
		float PressTime = 0.0f;

		// 입력 이벤트
		std::vector<std::function<void()>> PressEvents;
		std::vector<std::function<void()>> DownEvents;
		std::vector<std::function<void()>> UpEvents;
		std::vector<std::function<void()>> FreeEvents;

		// 기본 생성자
		UEngineKey()
		{

		}

		UEngineKey(int _Key) : Key(_Key)
		{

		}

		void EventCheck();

		void KeyCheck(float _DeltaTime);
	};

public:
	void EventCheck(float _DeltaTime);
	void KeyCheck(float _DeltaTime);

	bool IsDown(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}

		return Keys[_KeyIndex].IsDown;
	}

	bool IsUp(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}

		return Keys[_KeyIndex].IsUp;
	}

	bool IsPress(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}

		return Keys[_KeyIndex].IsPress;
	}

	float IsPreeTime(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}

		return Keys[_KeyIndex].PressTime;
	}


	bool IsFree(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("아직도 등록되지 않은 키가 존재합니다.");
			return false;
		}

		return Keys[_KeyIndex].IsFree;
	}

	void BindAction(int _KeyIndex, KeyEvent _EventType, std::function<void()> _Function);

protected:

private:
	std::map<int, UEngineKey> Keys;

	UEngineInput();

};

