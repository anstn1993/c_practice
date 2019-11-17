#include "simpleio.h"

int main(void)
{
	/* 문자, 부호없는 정수, 문자열만 서식 지정자로 지원하고 %도 생략 */
	printf_simple("c\n", 'A');
	printf_simple("d\n", 10);
	printf_simple("s\n", "Hello");

	printf_simple("\n");
	printf_simple("c d s\n", 'A', 10, "Hello");

	return 0;
}