#include <string.h>
#include "string_comparer.h"

int compare_string(const void* a, const void* b)
{
	/* 매개변수로 들어온 포인터는 배열 속의 문자열 시작 주소가 된다 */
	const char** w0 = (const char**)a;
	const char** w1 = (const char**)b;

	return strcmp(*w0, *w1);/* 이중 포인터에서 한 번 역참조를 하니까 해당 문자열의 시작 주소를 가져온다. 반환 값이 -1, 1. 0*/
}

int compare_string_desc(const void* a, const void* b)
{
	/* 매개변수로 들어온 포인터는 배열 속의 문자열 시작 주소가 된다 */
	const char** w0 = (const char**)a;
	const char** w1 = (const char**)b;

	return strcmp(*w1, *w0);
	/* return -strcmp(*w0, *w1);*/
}