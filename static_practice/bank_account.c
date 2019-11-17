#include "bank_account.h"

unsigned int g_chequing = 0u;/*일반통장 잔고*/
unsigned int g_saving = 0u;/*저축통장 잔고*/
static unsigned int s_fee = 20u;/*수수료(수수료는 은행직원만 바꿀 수 있으니 다른 곳에서 접근 금지!)*/

void deposit_into_chequing(const unsigned int amount)
{
	g_chequing += (amount - s_fee);
}

void deposit_into_saving(const unsigned int amount)
{
	g_saving += (amount - s_fee);
}

/* 수수료 설정은 이 파일에서만 가능 */
static void set_fee(const unsigned int fee)
{
	s_fee = fee;
}