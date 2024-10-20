#include <iostream>
#include <conio.h>

// 한 줄 글자 수 제한
const int LINECOUNT = 50;

// 이름 글자 수 제한
const int NAMELEN = 10;

class AActor
{
public:
	// 생성자와 멤버 이니셜라이저를 통해 객체를 만들면서 변수들을 초기화한다.
	// 이름의 경우 배열은 인덱스마다 초기화해주어야하므로 멤버 이니셜라이저를 사용하지 못한다.
	AActor(const char* const _Ptr, int _Att, int _Hp, int _Speed)
		: Att(_Att), Hp(_Hp), Speed(_Speed)
	{
		StrCopy(Name, NAMELEN, _Ptr);
	}

	// 이름 복사 함수
	void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
	{
		// _Arr 초기화
		for (int i = 0; i < _BufferSize; i++)
		{
			_Arr[i] = 0;
		}

		//_Name의 글자 수 세기
		int Size = static_cast<int>(strlen(_Name));
		// _Name의 글자 수만큼 _Name의 값을 _Arr에 대입
		// 배열의 경우 각 index에 값을 일일히 넣어주어야 함.
		for (int i = 0; i < Size; i++)
		{
			_Arr[i] = _Name[i];
		}
	}

	// 스테이터스 출력 함수
	void StatusRender()
	{
		printf_s("%s Staus ", Name);
		int NameLen = static_cast<int>(strlen(Name));
		int ExLen = static_cast<int>(strlen(" Status "));
		int NameLineCount = LINECOUNT - (NameLen + ExLen - 1);

		PrintLine(NameLineCount);
		printf_s("\n");
		printf_s("공격력 : %d\n", Att);
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
	inline const char* GetName() const
	{
		return Name;
	}

	// 공격력 가져오는 함수
	inline int GetAtt() const
	{
		return Att;
	}

	// 체력 가져오는 함수
	inline int GetHp() const
	{
		return Hp;
	}

	// 현재 속력 가져오는 함수
	inline int GetCurSpeed() const
	{
		return CurSpeed;
	}

	// 속력 정하는 함수 (매 회차마다 설정)
	void SetCurSpeed()
	{
		CurSpeed = rand() % Speed;
	}

	// 체력 깎이는 함수
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
	// 플레이어는 상위 클래스인 AActor의 변수들을 기반으로 객체가 만들어진다.
	Player(const char* const _Ptr, int _Att, int _Hp, int _Speed)
		: AActor(_Ptr, _Att, _Hp, _Speed)
	{

	}
private:
	// 플레이어 고유 변수
	int PlayerAttMin = 0;
};

class Monster : public AActor
{
public:
	// 몬스터는 상위 클래스인 AActor의 변수들을 기반으로 객체가 만들어진다.
	Monster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
		: AActor(_Ptr, _Att, _Hp, _Speed)
	{

	}
};

// 전투필드 클래스
// 전투 관련
class FightField
{
public:
	void DamageLogic(AActor& _Att, AActor& _Def)
	{
		_Def.SetHp(_Att.GetAtt());
	}

	void DamageRender(AActor& _Att, AActor& _Def)
	{
		printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n",
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
		printf_s("%s의 선공입니다.\n",
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