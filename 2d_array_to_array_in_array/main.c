#include <stdio.h>

int main(void)
{
	const int nums[3][5] = {
		{ 35, 50, 65, 24, 71 },
		{ 52, 93, 30, 18, 83 },
		{ 72, 53, 41, 88, 69 },
	};/* 2D�迭�� �޸𸮿����� ���������� �����Ǳ� ������ �� ���� �迭�� �ּҸ� ���� �������� �� ����. */

	const int* nums2[3];/* ������ �迭 */

	nums2[0] = nums[0];/* ù��° ���� �迭�� �ּ� ���� */
	nums2[1] = nums[1];/* �ι�° ���� �迭�� �ּ� ���� */
	nums2[2] = nums[2];/* ����° ���� �迭�� �ּ� ���� */

	/* �� ���� �ּ� ����غ��� */
	printf("nums[0] address: %p\n", (void*)nums[0]);
	printf("nums[1] address: %p\n", (void*)nums[1]);
	printf("nums[2] address: %p\n", (void*)nums[2]);

	/* �̺κ��� �߿��ϴ�. nums[0], nums[2]�� ���� �迭�̴�. �׷� �� ���� ���� 10���� ������ �׷� �������� 10*/
	printf("nums[2]'s offset from nums[0]: %d\n", nums[2] - nums[0]);/* 10 */
	printf("nums[1]'s offset from nums[0]: %d\n", nums[1] - nums[0]);/* 5 */

	printf("\n");

	/* nums2��ҵ��� �ּ� ��� */
	printf("nums2[0] address: %p\n", (void*)&nums2[0]);
	printf("nums2[1] address: %p\n", (void*)&nums2[1]);
	printf("nums2[2] address: %p\n", (void*)&nums2[2]);

	/* nums2�� �� ��ҵ��� offset���ϱ� �� �迭���� �׳� �ּҰ� ����ִ� ���̱� ������ ���̰� �迭���� �ٸ���. */
	printf("nums2[2]'s offset from nums2[0]: %d\n", &nums2[2] - &nums2[0]);/* 2 */
	printf("nums2[1]'s offset from nums2[0]: %d\n", &nums2[1] - &nums2[0]);/* 1 */

	return 0;

}