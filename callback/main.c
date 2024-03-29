#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "error_handler.h"

#define TRUE (1)
#define FALSE (0)

void simple_stderr_print(const char* msg);
int run(void);

int main(void)
{
	int success;

	success = run();/* 이 함수에서 오류 발생 */

	register_error_handler(default_error_handler);
	if (run() == FALSE) {
		success = FALSE;
	}

	register_error_handler(simple_stderr_print);
	if (run() == FALSE) {
		success = FALSE;
	}
}

int run(void)
{
	int numerator;/* 분자 */
	int denominator;/* 분모 */

	while(TRUE) {
		printf("enter numerator: ");
		if (scanf("%d", &numerator) == 1) {
			break;
		}
	}
	while (TRUE) {
		printf("enter denominator: ");
		if (scanf("%d", &denominator) == 1) {
			break;
		}
	}

	if (denominator == 0) {
		log_error("cannot dividy by zero");
		return FALSE;
	}

	printf("%d / %d = %.2f\n", numerator, denominator, numerator / (float)denominator);

	return TRUE;
}

void simple_stderr_print(const char* msg)
{
	fputs(msg, stderr);
}