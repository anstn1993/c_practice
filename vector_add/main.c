#include <stdio.h>
#include "vector.h"

int main(void)
{
	const int v1[VECTOR_LENGTH] = { 1, 2, 3 };
	const int v2[VECTOR_LENGTH] = { 1, 2, 8 };
	int v3[VECTOR_LENGTH];

	add_vec3(v1, v2, v3);/*배열의 이름을 넣으니까 첫번재 요소의 주소가 들어간다.*/
	
	printf("v3: %d, %d, %d", v3[0], v3[1], v3[2]);/* v3가 함수 안에서 수정되었음에도 불구하고 포인터로 들어갔기 때문에 원본이 수정되었다.  */
	return 0;
}