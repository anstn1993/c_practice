#include "vector.h"

void add_vec3(const int* v1, const int* v2, int* out_v3)/* 3개짜리 배열을 더하는 거라서 반환할 수 없으니 입력값 출력값을 다 포인터로 줘서 함수 바깥의 원본 수정이 가능하게 한다.  */
{
	size_t i = 0;
	for (i = 0; i < VECTOR_LENGTH; ++i) {
		*out_v3++ = *v1++ + *v2++;/* 후위 증감 연산자를 써서 v1, v2배열 각 요소를 더한 값을 out_v3에 넣어주고 주소 점프 */
	}
}
