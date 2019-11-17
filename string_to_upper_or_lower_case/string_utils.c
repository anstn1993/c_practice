#include "string_utils.h"

int is_alpha(int c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');/* 매개변수가 대문자 A~Z나 소문자 a~z 사이에 있는지 확인 */
}

int to_upper(int c)
{
	if (is_alpha(c)) {
		/* 0x20은 십진수로 32다. c & ~0x20은 c에서 32를 빼는 것과 같다. 32는 2의 승수이기 때문에 비트패턴에 1이 하나 들어간다. 
		같은 알파벳의 소문자와 대문자는 32씩 차이가 난다. 그러니까 대문자로 바꿀 때 비트패턴상 32자리의 1을 0으로만 바꾸면 되는 것이다. 
		a~z의 비트패턴이 110 0001~111 1010이다. 그럼 a를 예로 들면 대문자 A는 a보다 32가 작으니까 6째자리의 1이 0으로 바껴서 100 0001이 된다. c & ~0x20이 그거 하는 거다.
		32의 비트패턴은 10 0000이고 그걸 ~(bitwise not)을 해주면 01 1111이 되고 이걸 110 0001과 &연산 해주면 100 0001이 되어 65(A)가 되는 것이다. */
		return c & ~0x20;
	}

	return c;
}

int to_lower(int c)
{
	if (is_alpha(c)) {
		/* 위에 to_upper를 이해했으면 이것도 쉽다. A에서 a로 변환한다고 치면 A는 100 0001이고 10 0000과 |연산을 해주는 거니까 결과는 110 0001이 되어 97(a)가 되는 것이다. */
		return c | 0x20;
	}

	return c;
}

void string_toupper(char* str)
{
	while (*str != '\0') {
		*str = to_upper(*str);
		++str;
	}
}

void string_tolower(char* str)
{
	while (*str != '\0') {
		*str = to_lower(*str);
		++str;
	}
}