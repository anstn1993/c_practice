#include <stdio.h>

void save_address(void)
{
	int num = 10;
	printf("num: %d\n", num);
	int* num_address = &num;
	printf("num_address: %p\n", num_address);
	printf("num_address's address: %p\n", &num_address);
}

int main(void)
{
	save_address();
	return 0;
}