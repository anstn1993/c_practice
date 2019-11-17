#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "simpleio.h"

static void print_int_recursive(unsigned int val)/* 자기 자신을 호출하는 재귀함수 */
{
	if (val == 0) {/* 더 이상 볼 자료가 없는 거니까 그냥 재귀에서 탈출 */
		return;
	}

	print_int_recursive(val / 10);/* 10을 나눠서 오른쪽부터 각 자리수에 접근 */
	putchar('0' + val % 10);/* 이렇게 아스키 코드 0에다 각 자리수의 숫자를 더하면 그 수만큼 아스키코드에서 이동하는 것이기 때문에 바로 출력할 값을 구할 수 있다. */
}

void printf_simple(const char* format, ...)
{
	va_list ap;

	va_start(ap, format);
	{
		while (*format != '\0') {
			unsigned val;
			const char* str;

			switch (*format) {
				case 's':/* 문자열인 경우 */
					str = va_arg(ap, const char*);/* 가변인자에서 값 get */
					while (*str != '\0') {
						putchar(*str++);/* 다음 문자가 있는 주소로 이동 */
					}
					break;
				case 'c':
					val = va_arg(ap, unsigned int);/* char는 int로 승격되니까 자료형을 int로 설정 */
					putchar(val);
					break;
				case 'd':
					val = va_arg(ap, unsigned int);
					print_int_recursive(val);
					break;
				default:
					putchar(*format);
					break;
			}	
			++format;
		}
	}
	va_end(ap);
}