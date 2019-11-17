#include <stdio.h>
#include "bank_account.h"

extern unsigned int g_chequing;
extern unsigned int g_saving;
extern unsigned int s_fee;/*extern을 해도 의미 없음 정적 변수라서*/
extern void set_fee(const unsigned int fee);

int main(void)
{
	printf("g_chequing: %u\n", g_chequing);
	printf("g_saving: %u\n", g_saving);
	/*
	링커 에러
	printf("s_fee: %u\n", s_fee);
	*/

	deposit_into_chequing(300u);
	deposit_into_saving(700u);
	/*
	링커 에러
	set_fee(100);
	*/

	printf("g_chequing: %u\n", g_chequing);
	printf("g_saving: %u\n", g_saving);
	/*
	링커 에러
	printf("s_fee: %u\n", s_fee);
	*/

}