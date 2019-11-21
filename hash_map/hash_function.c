#include <stddef.h>

#include "hash_function.h"

size_t hash_int(int value)/* �� ��ü�� �̹� ������ ���� ���̱� ������ size_t�� ĳ�����ؼ� ��ȯ */
{
	return value;
}

size_t hash_float(float value)/* float�� ĳ�����ϸ� �Ҽ��� ���ϰ� ������ϱ� ���� ������ size_t�� �а� �Ѵ�.  */
{
	return *((size_t*)&value);
}

size_t hash_data(const void* data, size_t length)/* ������ ������ Ÿ�Կ��� ����� �� �ִ� �ؽ� �Լ� */
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