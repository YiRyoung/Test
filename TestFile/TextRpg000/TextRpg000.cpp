#include <iostream>
#include <conio.h>

// �� �� ���� �� ����
const int LINECOUNT = 50;

// �̸� ���� �� ����
const int NAMELEN = 10;

class AActor
{
public:
	// �����ڿ� ��� �̴ϼȶ������� ���� ��ü�� ����鼭 �������� �ʱ�ȭ�Ѵ�.
	// �̸��� ��� �迭�� �ε������� �ʱ�ȭ���־���ϹǷ� ��� �̴ϼȶ������� ������� ���Ѵ�.
	AActor(const char* const _Ptr, int _Att, int _Hp, int _Speed)
		: Att(_Att), Hp(_Hp), Speed(_Speed)
	{
		StrCopy(Name, NAMELEN, _Ptr);
	}

	// �̸� ���� �Լ�
	void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
	{
		// _Arr �ʱ�ȭ
		for (int i = 0; i < _BufferSize; i++)
		{
			_Arr[i] = 0;
		}

		//_Name�� ���� �� ����
		int Size = static_cast<int>(strlen(_Name));
		// _Name�� ���� ����ŭ _Name�� ���� _Arr�� ����
		// �迭�� ��� �� index�� ���� ������ �־��־�� ��.
		for (int i = 0; i < Size; i++)
		{
			_Arr[i] = _Name[i];
		}
	}

	// �������ͽ� ��� �Լ�
	void StatusRender()
	{
		printf_s("%s Staus ", Name);
		int NameLen = static_cast<int>(strlen(Name));
		int ExLen = static_cast<int>(strlen(" Status "));
		int NameLineCount = LINECOUNT - (NameLen + ExLen - 1);

		PrintLine(NameLineCount);
		printf_s("\n");
		printf_s("���ݷ� : %d\n", Att);
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
	inline const char* GetName() const
	{
		return Name;
	}

	// ���ݷ� �������� �Լ�
	inline int GetAtt() const
	{
		return Att;
	}

	// ü�� �������� �Լ�
	inline int GetHp() const
	{
		return Hp;
	}

	// ���� �ӷ� �������� �Լ�
	inline int GetCurSpeed() const
	{
		return CurSpeed;
	}

	// �ӷ� ���ϴ� �Լ� (�� ȸ������ ����)
	void SetCurSpeed()
	{
		CurSpeed = rand() % Speed;
	}

	// ü�� ���̴� �Լ�
	void SetHp(int _Att)
	{
		Hp -= _Att;
	}

protected:
	int Att = 0;
	int Hp = 0;
	int Speed = 10;
	int CurSpeed = 0;
	char Name[NAMELEN] = "";
};

class Player : public AActor
{
public:
	// �÷��̾�� ���� Ŭ������ AActor�� �������� ������� ��ü�� ���������.
	Player(const char* const _Ptr, int _Att, int _Hp, int _Speed)
		: AActor(_Ptr, _Att, _Hp, _Speed)
	{

	}
private:
	// �÷��̾� ���� ����
	int PlayerAttMin = 0;
};

class Monster : public AActor
{
public:
	// ���ʹ� ���� Ŭ������ AActor�� �������� ������� ��ü�� ���������.
	Monster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
		: AActor(_Ptr, _Att, _Hp, _Speed)
	{

	}
};

// �����ʵ� Ŭ����
// ���� ����
class FightField
{
public:
	void DamageLogic(AActor& _Att, AActor& _Def)
	{
		_Def.SetHp(_Att.GetAtt());
	}

	void DamageRender(AActor& _Att, AActor& _Def)
	{
		printf_s("%s �� %s�� �����ؼ� %d�� �������� �������ϴ�.\n",
			_Att.GetName(), _Def.GetName(), _Att.GetAtt());
	}

	bool IsPlayerFirst(AActor& _Player, AActor& _Monster)
	{
		if (_Player.GetCurSpeed() > _Monster.GetCurSpeed())
		{
			return true;
		}
		return false;
	}

	void SpeedRender(AActor& _Player, AActor& _Monster)
	{
		printf_s("%s�� �����Դϴ�.\n",
			IsPlayerFirst(_Player, _Monster) == true ? _Player.GetName() : _Monster.GetName());
	}

	void PrintStatus(AActor& _Player, AActor& _Monster)
	{
		_Player.StatusRender();
		_Monster.StatusRender();
	}

	void Battle(AActor& _Player, AActor& _Monster)
	{
		while (true)
		{
			system("cls");
			PrintStatus(_Player, _Monster);
			_Player.SetCurSpeed(); _Monster.SetCurSpeed();
			_getch();
			if (IsPlayerFirst(_Player, _Monster))
			{
				DamageLogic(_Player, _Monster);
				system("cls");
				PrintStatus(_Player, _Monster);
				SpeedRender(_Player, _Monster);
				DamageRender(_Player, _Monster);
				_getch();

				DamageLogic(_Monster, _Player);
				system("cls");
				PrintStatus(_Player, _Monster);
				SpeedRender(_Player, _Monster);
				DamageRender(_Player, _Monster);
				DamageRender(_Monster, _Player);
			}
			else
			{
				DamageLogic(_Monster, _Player);

				system("cls");
				PrintStatus(_Player, _Monster);
				SpeedRender(_Player, _Monster);
				DamageRender(_Monster, _Player);
				_getch();

				DamageLogic(_Player, _Monster);
				system("cls");
				PrintStatus(_Player, _Monster);
				SpeedRender(_Player, _Monster);
				DamageRender(_Monster, _Player);
				DamageRender(_Player, _Monster);
			}
			_getch();
		}
	}
private:
};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Player NewPlayer = Player("Player", 10, 100, 10);
	Monster NewMonster = Monster("Orc", 10, 50, 10);
	FightField BattleField = FightField();

	BattleField.Battle(NewPlayer, NewMonster);
}