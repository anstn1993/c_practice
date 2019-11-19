#include <string.h>
#include "string_comparer.h"

int compare_string(const void* a, const void* b)
{
	/* �Ű������� ���� �����ʹ� �迭 ���� ���ڿ� ���� �ּҰ� �ȴ� */
	const char** w0 = (const char**)a;
	const char** w1 = (const char**)b;

	return strcmp(*w0, *w1);/* ���� �����Ϳ��� �� �� �������� �ϴϱ� �ش� ���ڿ��� ���� �ּҸ� �����´�. ��ȯ ���� -1, 1. 0*/
}

int compare_string_desc(const void* a, const void* b)
{
	/* �Ű������� ���� �����ʹ� �迭 ���� ���ڿ� ���� �ּҰ� �ȴ� */
	const char** w0 = (const char**)a;
	const char** w1 = (const char**)b;

	return strcmp(*w1, *w0);
	/* return -strcmp(*w0, *w1);*/
}