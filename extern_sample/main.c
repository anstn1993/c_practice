#include "minion.h"
#include <stdio.h>

/* �� ���������� ��� �������� �𸣰����� �װ� ��ũ�ܰ迡�� �޲ٰ� �ϴ��� ������ */
extern unsigned int g_hp;
extern unsigned int g_strength;

int main(void)
{
	printf("Normal minion:\n");
	printf("hp: %u\n", g_hp);/* 100 */
	printf("strength: %u\n", g_strength);/* 10 */

	/*
	�� �ڵ�� ������ �� ��. g_gold�� ������ ���µ�? ������ �� �ſ����� extern�� �ϵ簡
	printf("gold: %u\n", g_gold);
	*/

	printf("\n");

	go_berserk();
	add_gold(100);

	printf("Berserk minion\n");
	printf("hp: %u\n", g_hp); /* 150 */
	printf("strength: %u\n", g_strength); /* 30 */

	/*
	������ �� �ڵ�� �������� �� ����.
	printf("gold: %u\n, g_gold"); 
	*/
}
 
