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

	// ���� static ���� �̱���
	// ���α׷��� ��Ʋ�� �� ���� ��ü�� �����Բ� �ϴ� ���� �̱����̶�� �Ѵ�.
	// �������� �����߱� ������ �ܺο� �����ϱ� ��ٷ�����,
	// ����Ⱑ ���� �ڵ尡 ª������ ��ȣ�ϴ� ���.
	// static�� Ư�� ������ ������ ������ �� �� �Ҵ� �Ŀ��� �ش� ��ü�� ��ȯ�Ѵ�.
	static UEngineInput& GetInst()
	{
		static UEngineInput Inst = UEngineInput();
		return Inst;
	}

protected:

private:
	// �Է� Ű ���� Ŭ����
	class UEngineKey
	{
	public:
		int Key = -1;

		// Ű�� ������ ��
		bool IsDown = false;
		// Ű�� ��� �����ִ� ������ ��
		bool IsPress = false;
		// Ű�� ���� ��
		bool IsUp = false;
		// Ű�� �� ������ ���� ��
		bool IsFree = true;

		// Ű�� ���� �ð� ����
		float PressTime = 0.0f;

		// �Է� �̺�Ʈ
		std::vector<std::function<void()>> PressEvents;
		std::vector<std::function<void()>> DownEvents;
		std::vector<std::function<void()>> UpEvents;
		std::vector<std::function<void()>> FreeEvents;

		// �⺻ ������
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
			MSGASSERT("������ ��ϵ��� ���� Ű�� �����մϴ�.");
			return false;
		}

		return Keys[_KeyIndex].IsDown;
	}

	bool IsUp(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("������ ��ϵ��� ���� Ű�� �����մϴ�.");
			return false;
		}

		return Keys[_KeyIndex].IsUp;
	}

	bool IsPress(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("������ ��ϵ��� ���� Ű�� �����մϴ�.");
			return false;
		}

		return Keys[_KeyIndex].IsPress;
	}

	float IsPreeTime(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("������ ��ϵ��� ���� Ű�� �����մϴ�.");
			return false;
		}

		return Keys[_KeyIndex].PressTime;
	}


	bool IsFree(int _KeyIndex)
	{
		if (false == Keys.contains(_KeyIndex))
		{
			MSGASSERT("������ ��ϵ��� ���� Ű�� �����մϴ�.");
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

