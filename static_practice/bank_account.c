#include "bank_account.h"

unsigned int g_chequing = 0u;/*�Ϲ����� �ܰ�*/
unsigned int g_saving = 0u;/*�������� �ܰ�*/
static unsigned int s_fee = 20u;/*������(������� ���������� �ٲ� �� ������ �ٸ� ������ ���� ����!)*/

void deposit_into_chequing(const unsigned int amount)
{
	g_chequing += (amount - s_fee);
}

void deposit_into_saving(const unsigned int amount)
{
	g_saving += (amount - s_fee);
}

/* ������ ������ �� ���Ͽ����� ���� */
static void set_fee(const unsigned int fee)
{
	s_fee = fee;
}