#include <ctype.h>
#include <stdio.h>

#include "whitespace_counter.h"

void print_whitespace_stat(void)/* ' '이외에 줄바꿈이나 탭문자도 다 공백 문자고 그 외에 다양한 공백 문자들이 있다. */
{
	int c;/* stdin으로 들어오는 문자 저장 */
	size_t num_whitespaces = 0u;/* 공백문자의 수 */
	size_t num_newlines = 0u;/* 새 줄 문자(\n)의 수 */

	c = getchar();
	while (c != EOF) {
		if (isspace(c)) {/* ctype.h파일에 들어있는 공백문자를 찾아주는 내장 함수 */
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