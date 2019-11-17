#include <ctype.h>/* tolower���� */

#include "string_utils.h"

int string_case_insensitive_compare(const char* str0, const char* str1)/* �� ���ڿ��� �޾� ��ҹ��� ���� ���� �� �Լ� */
{
	int c1;
	int c2;

	c1 = tolower(*str0);
	c2 = tolower(*str1);

	while (c1 != '\0' && c1 == c2) {/* �ܼ� ���ڿ� �� ���ǰ� ���� */
		c1 = tolower(*++str0);/* ���� ������ �ּҷ� �̵��� �� �� �������� */
		c2 = tolower(*++str1);
	}

	return c1 - c2;/* 0�̸� �� ���ڿ��� ���� �Ű� �ƴϸ� �ٸ� �� */


}
