#include <stdio.h>

void print_address(void)
{
	int num1 = 10;
	int num2 = 20;
	printf("Address of num1: %p\n", (void*)&num1);/* %p를 사용하면 메모리 주소를 16진수로 표현 */
	printf("Address of num2: %p\n", (void*)&num2);
}

int main(void)
{
	print_address();
	return 0;
}
