#include "Player.h"
#include <iostream>

APlayer::APlayer()
{

}

void APlayer::StatusTextPrint()
{
    printf_s("���ݷ� : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
    printf_s("ü�� : %d\n", CurHp);
    printf_s("��� : %d\n", Gold);
}