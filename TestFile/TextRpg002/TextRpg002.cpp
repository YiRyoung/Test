#include <iostream>
#include <conio.h>

#include <Windows.h>
#include <assert.h>

// ���� ó��
// �޼��� �ڽ��� ���
#define MSGASSERT(VALUE) MessageBoxA(nullptr, VALUE, "ġ���� ����", MB_OK); assert(false);

const int LINECOUNT = 50;
const int NAMELEN = 20;

class StatusUnit
{
public:
	// �������ͽ� ��� �Լ�
	void StatusRender()
	{
		printf_s("%s Staus ", Name);
		int NameLen = static_cast<int>(strlen(Name));
		int ExLen = static_cast<int>(strlen(" Status "));
		int NameLineCount = LINECOUNT - (NameLen + ExLen - 1);

		PrintLine(NameLineCount);
		printf_s("\n");
		printf_s("���ݷ� : %d ~ %d\n", MinAtt, MaxAtt);
		printf_s("ü�� : %d\n", Hp);
		PrintLine(LINECOUNT);
		printf_s("\n");
	}

	// ���� �׸��� �Լ�
	void PrintLine(int _Count)
	{
		for (int i = 0; i < _Count; i++)
		{
			printf_s("-");
		}
	}

	// �̸� �������� �Լ�
	const char* GetName()
	{
		return Name;
	}

	// �̸� ���� �Լ�
	void SetName(const char* const _Name)
	{
		if (NAMELEN <= strlen(_Name))
		{
			MSGASSERT("�̸��� �ʹ� ��ϴ�.");
			return;
		}

		strcpy_s(Name, _Name);
	}

	// ���� ���� ���ݷ��� �������� �Լ�
	inline int GetCurAtt() const
	{
		return CurAtt;
	}

	// ���� ���� ���ݷ� ���� �Լ�
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
	// MinAtt ~ MaxAtt ���� �������� �����ϴ� �Լ�
	const int GetDamage()
	{
		return MinAtt + (rand() % (MaxAtt - MinAtt + 1));
	}

	// �������� ������ ���� �Լ�
	void DamageLogic(FightUnit& _DefUnit)
	{
		int Att = this->GetDamage();
		this->SetCurAtt(Att);
		_DefUnit.Hp -= this->GetCurAtt();
	}

	// �������� ����ϴ� ���� �Լ�
	void DamageRender(FightUnit& _DefUnit)
	{
		printf_s("%s�� %s�� �����ؼ� %d�� �������� �������ϴ�.\n",
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