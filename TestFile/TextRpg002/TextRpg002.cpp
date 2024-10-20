#include <iostream>
#include <conio.h>

#include <Windows.h>
#include <assert.h>

// 예외 처리
// 메세지 박스를 띄움
#define MSGASSERT(VALUE) MessageBoxA(nullptr, VALUE, "치명적 에러", MB_OK); assert(false);

const int LINECOUNT = 50;
const int NAMELEN = 20;

class StatusUnit
{
public:
	// 스테이터스 출력 함수
	void StatusRender()
	{
		printf_s("%s Staus ", Name);
		int NameLen = static_cast<int>(strlen(Name));
		int ExLen = static_cast<int>(strlen(" Status "));
		int NameLineCount = LINECOUNT - (NameLen + ExLen - 1);

		PrintLine(NameLineCount);
		printf_s("\n");
		printf_s("공격력 : %d ~ %d\n", MinAtt, MaxAtt);
		printf_s("체력 : %d\n", Hp);
		PrintLine(LINECOUNT);
		printf_s("\n");
	}

	// 라인 그리는 함수
	void PrintLine(int _Count)
	{
		for (int i = 0; i < _Count; i++)
		{
			printf_s("-");
		}
	}

	// 이름 가져오는 함수
	const char* GetName()
	{
		return Name;
	}

	// 이름 설정 함수
	void SetName(const char* const _Name)
	{
		if (NAMELEN <= strlen(_Name))
		{
			MSGASSERT("이름이 너무 깁니다.");
			return;
		}

		strcpy_s(Name, _Name);
	}

	// 현재 턴의 공격력을 가져오는 함수
	inline int GetCurAtt() const
	{
		return CurAtt;
	}

	// 현재 턴의 공격력 저장 함수
	void SetCurAtt(int _CurAtt)
	{
		CurAtt = _CurAtt;
	}

protected:
	char Name[NAMELEN] = "NONE";
	int Hp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int CurAtt = 0;
	int Speed = 10;

private:
};

class FightUnit : public StatusUnit
{
public:
	// MinAtt ~ MaxAtt 사이 데미지를 리턴하는 함수
	const int GetDamage()
	{
		return MinAtt + (rand() % (MaxAtt - MinAtt + 1));
	}

	// 데미지를 입히는 로직 함수
	void DamageLogic(FightUnit& _DefUnit)
	{
		int Att = this->GetDamage();
		this->SetCurAtt(Att);
		_DefUnit.Hp -= this->GetCurAtt();
	}

	// 데미지를 출력하는 렌더 함수
	void DamageRender(FightUnit& _DefUnit)
	{
		printf_s("%s가 %s를 공격해서 %d의 데미지를 입혔습니다.\n",
			this->GetName(), _DefUnit.GetName(), this->GetCurAtt());
	}
protected:

private:
};

class Player : public FightUnit
{

};

class Monster : public FightUnit
{

};

class FightZone
{
public:
	void PrintStatus(FightUnit& _Left, FightUnit& _Right)
	{
		_Left.StatusRender();
		_Right.StatusRender();
	}

	void Fight(FightUnit& _Left, FightUnit& _Right)
	{
		system("cls");
		char input = ' ';

		PrintStatus(_Left, _Right);
		input = _getch();

		system("cls");
		_Left.DamageLogic(_Right);
		PrintStatus(_Left, _Right);
		_Left.DamageRender(_Right);
		input = _getch();

		system("cls");
		_Right.DamageLogic(_Left);
		PrintStatus(_Left, _Right);
		_Left.DamageRender(_Right);
		_Right.DamageRender(_Left);
		input = _getch();

	}
};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Player NewPlayer;
	Monster NewMonster;

	NewPlayer.SetName("Player");
	NewMonster.SetName("Monster");

	FightZone BattleZone;

	while (true)
	{
		BattleZone.Fight(NewPlayer, NewMonster);
	}
}