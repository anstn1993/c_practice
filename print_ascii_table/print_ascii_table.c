#include <stdio.h>

#include "print_ascii_table.h"

void print_ascii_table(void)
{
	const char MIN_PRINTABLE_ASCII = 32;/* 화면에 보여줄 수 있는 유효한 문자가 32 */
	const char NUM_ROWS = 31;/* 출력할 줄 수 */
	const char COL_CHAR_OFFSET = 32;

	char i;

	printf("Dec Hex Char\t");/* \t는 탭 문자 */
	printf("Dec Hex Char\t");
	printf("Dec Hex Char\t");

	for (i = 0; i < NUM_ROWS; ++i) {
		char ch = i + MIN_PRINTABLE_ASCII;/* 32, 33, 34, 35....출력 */
		printf("%03d %#X %c\t", ch, ch, ch);/* 첫 번째 열의 글자는 10진수 숫자, 16진수 숫자, 문자로 출력 */

		ch += COL_CHAR_OFFSET; /* 두번째 열의 문자에도 같은 작업 */
		printf("%03d %#X %c\t", ch, ch, ch);/* 첫 번째 열의 글자는 10진수 숫자, 16진수 숫자, 문자로 출력 */ch += COL_CHAR_OFFSET; /* 두번째 열의 문자에도 같은 작업 */
		
		ch += COL_CHAR_OFFSET; /* 세번째 열의 문자에도 같은 작업 */
		printf("%03d %#X %c\t", ch, ch, ch);/* 첫 번째 열의 글자는 10진수 숫자, 16진수 숫자, 문자로 출력 */
	}
}