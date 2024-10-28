#pragma once
#include <functional>
#include <list>

class EngineDelegate
{
public:
	// constrcuter destructer
	EngineDelegate();

	// EngineDelegate deleFunc(Attack);
	EngineDelegate(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

	~EngineDelegate();

	// Functions ����Ʈ �ȿ� ���� �����ϴ��� Ȯ��
	inline bool IsBind()
	{
		return false == Functions.empty();
	}

	// EngineDelegate Func += Attack
	// std::list<std::function<void()>> Functions�� �ش� �Լ��� �����͸� �ε����� �߰���
	void operator+=(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

	// deleFunc();
	void operator()()
	{
		// ����Ʈ�� ����� �Լ� �������� ù��° �ε����� ���� �ε���
		std::list<std::function<void()>>::iterator StartIter = Functions.begin();
		std::list<std::function<void()>>::iterator EndIter = Functions.end();

		// ����Ʈ�� �������� �ƴ϶��
		for (; StartIter != EndIter; ++StartIter)
		{
			// ���� �ε����� ��(��ųε� �Լ�)�� ���۷�����(�޸� ����ȭ) �����´�.
			std::function<void()>& Function = *StartIter;
			Function();	// �ش� �Լ� ����
		}
	}
protected:

private:
	// void�� �Լ����� ��ų��� ����Ͽ� �ܺο����� ȣ�� �����ϵ��� �Ѵ�.
	// ���� �Լ��� �����ϴ� ��ü ���� �ڵ带 ���� ���
	// list�� ����Ͽ� �Լ����� �����ϱ� ������ ������� ����
	std::list<std::function<void()>> Functions;
};

