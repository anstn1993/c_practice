#include <stdio.h>

#include "algorithm.h"

#define LENGTH (5)/*�̷��� LENGTH��� �̸��� ��ũ�θ� �����صθ� ���� �� Ű���带 ������ �� 5�� ġȯ���ش�.*/

int main(void)
{
	const int nums[LENGTH] = { 3, 10, 5, 8, 7 };
	int min;
	int max;

	get_min_max(nums, LENGTH, &min, &max);

	printf("min: %d\n", min);
	printf("max: %d\n", max);
	
	return 0;
}