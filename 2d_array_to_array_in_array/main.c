#include <stdio.h>

int main(void)
{
	const int nums[3][5] = {
		{ 35, 50, 65, 24, 71 },
		{ 52, 93, 30, 18, 83 },
		{ 72, 53, 41, 88, 69 },
	};/* 2D배열이 메모리에서는 일직선으로 나열되기 때문에 각 내부 배열의 주소를 따로 저장해준 건 없다. */

	const int* nums2[3];/* 포인터 배열 */

	nums2[0] = nums[0];/* 첫번째 내부 배열의 주소 저장 */
	nums2[1] = nums[1];/* 두번째 내부 배열의 주소 저장 */
	nums2[2] = nums[2];/* 세번째 내부 배열의 주소 저장 */

	/* 각 행의 주소 출력해보자 */
	printf("nums[0] address: %p\n", (void*)nums[0]);
	printf("nums[1] address: %p\n", (void*)nums[1]);
	printf("nums[2] address: %p\n", (void*)nums[2]);

	/* 이부분이 중요하다. nums[0], nums[2]는 숫자 배열이다. 그럼 이 둘을 정수 10개가 빠지고 그럼 오프셋은 10*/
	printf("nums[2]'s offset from nums[0]: %d\n", nums[2] - nums[0]);/* 10 */
	printf("nums[1]'s offset from nums[0]: %d\n", nums[1] - nums[0]);/* 5 */

	printf("\n");

	/* nums2요소들의 주소 출격 */
	printf("nums2[0] address: %p\n", (void*)&nums2[0]);
	printf("nums2[1] address: %p\n", (void*)&nums2[1]);
	printf("nums2[2] address: %p\n", (void*)&nums2[2]);

	/* nums2의 각 요소들의 offset구하기 이 배열에는 그냥 주소가 들어있는 것이기 때문에 차이가 배열과는 다르다. */
	printf("nums2[2]'s offset from nums2[0]: %d\n", &nums2[2] - &nums2[0]);/* 2 */
	printf("nums2[1]'s offset from nums2[0]: %d\n", &nums2[1] - &nums2[0]);/* 1 */

	return 0;

}