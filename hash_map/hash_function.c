#include <stddef.h>

#include "hash_function.h"

size_t hash_int(int value)/* 그 자체가 이미 고유한 정수 값이기 때문에 size_t로 캐스팅해서 반환 */
{
	return value;
}

size_t hash_float(float value)/* float을 캐스팅하면 소수점 이하가 사라지니까 이진 패턴을 size_t로 읽게 한다.  */
{
	return *((size_t*)&value);
}

size_t hash_data(const void* data, size_t length)/* 범용적 데이터 타입에서 사용할 수 있는 해시 함수 */
{
	const char* p;
	size_t i;
	size_t hash;

	p = data;
	hash = 0;
	for (i = 0; i < length; ++i) {
		hash = 65599 * hash + *p++;
	}

	return hash ^ (hash >> 16);
}