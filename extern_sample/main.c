#include "minion.h"
#include <stdio.h>

/* 두 전역변수가 어디에 있을지는 모르겠지만 그건 링크단계에서 메꾸고 일단은 컴파일 */
extern unsigned int g_hp;
extern unsigned int g_strength;

int main(void)
{
	printf("Normal minion:\n");
	printf("hp: %u\n", g_hp);/* 100 */
	printf("strength: %u\n", g_strength);/* 10 */

	/*
	이 코드는 컴파일 안 됨. g_gold를 본적이 없는데? 컴파일 할 거였으면 extern을 하든가
	printf("gold: %u\n", g_gold);
	*/

	printf("\n");

	go_berserk();
	add_gold(100);

	printf("Berserk minion\n");
	printf("hp: %u\n", g_hp); /* 150 */
	printf("strength: %u\n", g_strength); /* 30 */

	/*
	여전히 이 코드는 컴파일할 수 없다.
	printf("gold: %u\n, g_gold"); 
	*/
}
 
