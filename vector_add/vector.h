#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_LENGTH (3)

void add_vec3(const int* v1, const int* v2, int* out_v3);/* 3개짜리 배열을 더하는 거라서 반환할 수 없으니 입력값 출력값을 다 포인터로 줘서 함수 바깥의 원본 수정이 가능하게 한다.  */

#endif /* VECTOR_H */