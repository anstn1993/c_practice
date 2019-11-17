#include <assert.h>/* assert()함수 */
#include "algorithm.h"

/* pre-condition: length >= 1 */
void get_min_max(const int nums[], const size_t length, int* out_min, int* out_max)
{
	size_t i;

	assert(length >= 1);/* c는 실행 도중에 예외가 없기 때문에 디버그 모드에서 선결 조건 검사를 위해서 사용 */

	/* 전제에 배열의 사이즈가 1이상이니까 초기 값은 배열의 첫번째 요소로 설정한다. */
	*out_min = nums[0];
	*out_max = nums[0];

	for (i = 1; i < length; ++i) {
		if (*out_min > nums[i]) {/*현재 최솟값보다 작은 값이 나오면 그 값으로 다시 덮어쓴다*/
			*out_min = nums[i];
		}

		if (*out_max < nums[i]) {/*현재 최댓값보다 큰 값이 나오면 그 값으로 다시 덮어쓴다*/
			*out_max = nums[i];
		}
	}
}