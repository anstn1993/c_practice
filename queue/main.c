#include <assert.h>
#include <stdio.h>

#define TRUE (1)
#define FALSE (0)


enum { MAX_NUMS = 8 };

int s_nums[MAX_NUMS];
size_t s_num_count = 0;
size_t s_front = 0;/* 큐의 데이터 삭제 index */
size_t s_back = 0;/*  큐의 데이터 삽입 index */

void print_queue()
{
	size_t i;
	if (s_back > s_front) {
		for (i = s_front; i < s_back; ++i) {
			printf("%d ", s_nums[i]);
		}
	}
	else {
		for (i = s_front; i < MAX_NUMS; ++i) {
			printf("%d ", s_nums[i]);
		}
		for (i = 0; i < s_back; ++i) {
			printf("%d ", s_nums[i]);
		}
	}
	puts("");
}

int is_empty()
{
	return (s_num_count == 0);
}

void enqueue(int n)
{
	assert(s_num_count < MAX_NUMS);
	s_nums[s_back] = n;
	s_back = (s_back + 1) % MAX_NUMS;
	++s_num_count;
}

int dequeue()
{
	int ret;
	assert(is_empty() == FALSE);
	ret = s_nums[s_front];
	s_front = (s_front + 1) % MAX_NUMS;
	--s_num_count;
	return ret;
}

int main(void)
{
	size_t i;
	for (i = 0; i < 6; ++i) {
		enqueue((i + 1) * 10);
	}
	print_queue();

	for (i = 0; i < 2; ++i) {
		dequeue();
	}
	print_queue();
	return 0;
}