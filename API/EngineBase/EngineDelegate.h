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

	// Functions 리스트 안에 값이 존재하는지 확인
	inline bool IsBind()
	{
		return false == Functions.empty();
	}

	// EngineDelegate Func += Attack
	// std::list<std::function<void()>> Functions에 해당 함수의 포인터를 인덱스에 추가함
	void operator+=(std::function<void()> _Function)
	{
		Functions.push_back(_Function);
	}

	// deleFunc();
	void operator()()
	{
		// 리스트에 저장된 함수 포인터의 첫번째 인덱스와 끝의 인덱스
		std::list<std::function<void()>>::iterator StartIter = Functions.begin();
		std::list<std::function<void()>>::iterator EndIter = Functions.end();

		// 리스트의 마지막이 아니라면
		for (; StartIter != EndIter; ++StartIter)
		{
			// 현재 인덱스의 값(펑셔널된 함수)를 레퍼런스로(메모리 최적화) 가져온다.
			std::function<void()>& Function = *StartIter;
			Function();	// 해당 함수 실행
		}
	}
protected:

private:
	// void형 함수들을 펑셔널을 사용하여 외부에서도 호출 가능하도록 한다.
	// 전역 함수를 지양하는 객체 지향 코드를 위해 사용
	// list를 사용하여 함수들을 관리하기 쉽도록 목록으로 구성
	std::list<std::function<void()>> Functions;
};

