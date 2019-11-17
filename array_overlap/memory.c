#include "memory.h"

int is_overlap(int nums1[], const size_t length1, int nums2[], const size_t length2)
{
	return (nums1 <= nums2/* nums1�� ù��° ����� �޸� �ּҰ��� nums2�� ù��° ����� �޸� �ּҰ� �� */
		? nums1 + length1 > nums2/* nums2�� ù��° �޸� �ּҰ��� �� ū ��� ���� nums1�� ������ ����� �޸� �ּҰ� nums2�� ù��° ����� �ּҰ��� �Ѿ�� ��ġ�� �� */
		: nums2 + length2 > nums1);/* nums1�� ù��° �޸� �ּҰ��� �� ū ��� ���� nums2�� ������ ����� �޸� �ּҰ� nums1�� ù��° ����� �ּҰ��� �Ѿ�� ��ġ�� �� */
}