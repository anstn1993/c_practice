#include <ctype.h>/* tolower내장 */

#include "string_utils.h"

int string_case_insensitive_compare(const char* str0, const char* str1)/* 두 문자열을 받아 대소문자 구분 없는 비교 함수 */
{
	int c1;
	int c2;

	c1 = tolower(*str0);
	c2 = tolower(*str1);

	while (c1 != '\0' && c1 == c2) {/* 단순 문자열 비교 조건과 동일 */
		c1 = tolower(*++str0);/* 다음 문자의 주소로 이동한 후 값 가져오기 */
		c2 = tolower(*++str1);
	}

	return c1 - c2;/* 0이면 두 문자열은 같은 거고 아니면 다른 것 */


}
