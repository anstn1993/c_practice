#include <stdio.h>

#include "algorithm.h"

#define LENGTH (5)/*이렇게 LENGTH라는 이름의 메크로를 설정해두면 이후 이 키워드를 넣으면 다 5로 치환해준다.*/

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