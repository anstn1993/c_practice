#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "simpleio.h"

static void print_int_recursive(unsigned int val)/* �ڱ� �ڽ��� ȣ���ϴ� ����Լ� */
{
	if (val == 0) {/* �� �̻� �� �ڷᰡ ���� �Ŵϱ� �׳� ��Ϳ��� Ż�� */
		return;
	}

	print_int_recursive(val / 10);/* 10�� ������ �����ʺ��� �� �ڸ����� ���� */
	putchar('0' + val % 10);/* �̷��� �ƽ�Ű �ڵ� 0���� �� �ڸ����� ���ڸ� ���ϸ� �� ����ŭ �ƽ�Ű�ڵ忡�� �̵��ϴ� ���̱� ������ �ٷ� ����� ���� ���� �� �ִ�. */
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
				case 's':/* ���ڿ��� ��� */
					str = va_arg(ap, const char*);/* �������ڿ��� �� get */
					while (*str != '\0') {
						putchar(*str++);/* ���� ���ڰ� �ִ� �ּҷ� �̵� */
					}
					break;
				case 'c':
					val = va_arg(ap, unsigned int);/* char�� int�� �°ݵǴϱ� �ڷ����� int�� ���� */
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