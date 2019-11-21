#include <assert.h>
#include <stdio.h>
#define TRUE (1)
#define FALSE (0)
enum { MAX_NUMS = 8 };
enum { INVALID_INDEX = -1 };

int s_nums[MAX_NUMS];
size_t s_num_count = 0;


void print_stack(void)
{
	size_t i;
	for (i = 0; i < s_num_count; ++i) {
		printf("%d ", s_nums[i]);
	}

	puts("");
}

void push(int n)
{
	assert(s_num_count < MAX_NUMS);

	s_nums[s_num_count++] = n;
}

int is_empty(void)
{
	return (s_num_count == 0);
}

int pop()
{
	assert(is_empty() == FALSE);

	return s_nums[--s_num_count];
}

int main(void)
{
	size_t i;

	for (i = 0; i < 6; ++i) {
		push((i + 1) * 10);
	}

	print_stack();

	for (i = 0; i < 2; ++i) {
		pop();
	}

	print_stack();

	return 0;
}