#include <stdio.h>

void move_one_byte()
{
	int num = 10;
	int* num_address = &num;
	printf("num: %d\n", num);
	printf("num_address: %p\n", num_address);

	num_address = (char*)num_address + 1;
	printf("one_byte_moved_num: %d\n", *num_address);
	printf("one_byte_moved_num_address: %p\n", num_address);
}

int main(void)
{
	move_one_byte();
	return 0;
}