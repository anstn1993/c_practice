#include <stdio.h>

#include "print_ascii_table.h"

void print_ascii_table(void)
{
	const char MIN_PRINTABLE_ASCII = 32;/* ȭ�鿡 ������ �� �ִ� ��ȿ�� ���ڰ� 32 */
	const char NUM_ROWS = 31;/* ����� �� �� */
	const char COL_CHAR_OFFSET = 32;

	char i;

	printf("Dec Hex Char\t");/* \t�� �� ���� */
	printf("Dec Hex Char\t");
	printf("Dec Hex Char\t");

	for (i = 0; i < NUM_ROWS; ++i) {
		char ch = i + MIN_PRINTABLE_ASCII;/* 32, 33, 34, 35....��� */
		printf("%03d %#X %c\t", ch, ch, ch);/* ù ��° ���� ���ڴ� 10���� ����, 16���� ����, ���ڷ� ��� */

		ch += COL_CHAR_OFFSET; /* �ι�° ���� ���ڿ��� ���� �۾� */
		printf("%03d %#X %c\t", ch, ch, ch);/* ù ��° ���� ���ڴ� 10���� ����, 16���� ����, ���ڷ� ��� */ch += COL_CHAR_OFFSET; /* �ι�° ���� ���ڿ��� ���� �۾� */
		
		ch += COL_CHAR_OFFSET; /* ����° ���� ���ڿ��� ���� �۾� */
		printf("%03d %#X %c\t", ch, ch, ch);/* ù ��° ���� ���ڴ� 10���� ����, 16���� ����, ���ڷ� ��� */
	}
}