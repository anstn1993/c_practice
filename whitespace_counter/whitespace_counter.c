#include <ctype.h>
#include <stdio.h>

#include "whitespace_counter.h"

void print_whitespace_stat(void)/* ' '�̿ܿ� �ٹٲ��̳� �ǹ��ڵ� �� ���� ���ڰ� �� �ܿ� �پ��� ���� ���ڵ��� �ִ�. */
{
	int c;/* stdin���� ������ ���� ���� */
	size_t num_whitespaces = 0u;/* ���鹮���� �� */
	size_t num_newlines = 0u;/* �� �� ����(\n)�� �� */

	c = getchar();
	while (c != EOF) {
		if (isspace(c)) {/* ctype.h���Ͽ� ����ִ� ���鹮�ڸ� ã���ִ� ���� �Լ� */
			++num_whitespaces;
			if (c == '\n') {
				++num_newlines;
			}
		}

		c = getchar();
	}

	printf("# whitespaces: %5d\n", num_whitespaces);
	printf("# new lines: %5d\n", num_newlines);
}