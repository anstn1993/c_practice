#include <stdio.h>

void print_address(void)
{
	int num1 = 10;
	int num2 = 20;
	printf("Address of num1: %p\n", (void*)&num1);/* %p�� ����ϸ� �޸� �ּҸ� 16������ ǥ�� */
	printf("Address of num2: %p\n", (void*)&num2);
}

int main(void)
{
	print_address();
	return 0;
}
