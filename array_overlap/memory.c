#include "memory.h"

int is_overlap(int nums1[], const size_t length1, int nums2[], const size_t length2)
{
	return (nums1 <= nums2/* nums1의 첫번째 요소의 메모리 주소값과 nums2의 첫번째 요소의 메모리 주소값 비교 */
		? nums1 + length1 > nums2/* nums2의 첫번째 메모리 주소값이 더 큰 경우 만약 nums1의 마지막 요소의 메모리 주소가 nums2의 첫번째 요소의 주소값을 넘어서면 겹치는 것 */
		: nums2 + length2 > nums1);/* nums1의 첫번째 메모리 주소값이 더 큰 경우 만약 nums2의 마지막 요소의 메모리 주소가 nums1의 첫번째 요소의 주소값을 넘어서면 겹치는 것 */
}