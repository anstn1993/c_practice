#include <stdio.h>
#include <assert.h>

enum { MAX_NUMS = 8 };
enum { INVALID_INDEX = -1 };

int s_nums[MAX_NUMS];
size_t s_num_count = 0;

void print_array(void)
{
	size_t i;
	for (i = 0; i < s_num_count; ++i) {
		printf("%d ", s_nums[i]);
	}

	puts("");
}

void insert_at(size_t index, int n)
{
	size_t i;

	assert(index <= s_num_count);
	assert(s_num_count < MAX_NUMS);

	for (i = s_num_count; i > index; --i) {
		s_nums[i] = s_nums[i-1];
	}

	s_nums[index] = n;
	++s_num_count;
}

size_t find_index(int n)
{
	size_t i;

	for (i = 0; i < s_num_count; ++i) {
		if (s_nums[i] == n) {
			return i;
		}
	}

	return INVALID_INDEX;
}

void remove_at(size_t index)
{
	size_t i;

	assert(index < s_num_count);

	--s_num_count;
	for (i = index; i < s_num_count; ++i) {
		s_nums[i] = s_nums[i + 1];
	}
}

void remove_at_unordered(size_t index)/* 새로운 삭제 연산으로 함수. 삭제 후 요소들의 순서 유지가 되지 않음. 그래서 속도 향상 */
{
	assert(index < s_num_count);
	s_nums[index] = s_nums[--s_num_count];/* 삭제하려는 인덱스에다 마지막 인덱스의 값을 대입. 항상 시간 복잡도가 O(1)이 된다. 요소가 하나인 상황에서도 문제 없는 코드임. 그냥 index 0의 값을 index 0에 대입하는 거니까. */
	/* 데이터의 순서가 중요하지 않으면 이렇게 삭제하는 것이 훨씬 빠름 */
}

int main(void)
{
	insert_at(0, 0);
	insert_at(1, 1);
	insert_at(2, 2);
	insert_at(3, 3);
	insert_at(4, 4);
	insert_at(5, 5);

	/* 0 1 2 3 4 5 */
	print_array();

	remove_at(1);
	/* 0 2 3 4 5 */
	print_array();
	
	remove_at_unordered(1);
	/* 0 5 3 4 */
	print_array();
	return 0;
}