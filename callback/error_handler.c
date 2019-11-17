#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

#include "error_handler.h"

static void (*s_handler)(const char*) = NULL;/* �ݹ��Լ��� ������ ���� ���� ����, �ϴ� NULL�� �ʱ�ȭ*/

void register_error_handler(void (*handler)(const char* msg))
{
	s_handler = handler;
}

void log_error(const char* msg)/* �� �Լ��� �׳� �ݹ��Լ��� ȣ���ϴ� ���Ҹ� ���� */
{
	if (s_handler != NULL) {
		s_handler(msg);/* �Լ� ������ ������ ���ǵǾ� ������ �ٷ� �Լ� ���� */
	}
}

void default_error_handler(const char* msg)
{
	time_t now;
	/*
	struct tm
	{
		int tm_sec;   // seconds after the minute - [0, 60] including leap second
		int tm_min;   // minutes after the hour - [0, 59]
		int tm_hour;  // hours since midnight - [0, 23]
		int tm_mday;  // day of the month - [1, 31]
		int tm_mon;   // months since January - [0, 11]
		int tm_year;  // years since 1900
		int tm_wday;  // days since Sunday - [0, 6]
		int tm_yday;  // days since January 1 - [0, 365]
		int tm_isdst; // daylight savings time flag
	}; 
	*/
	struct tm* local;

	now = time(NULL);/* ���� �ð��� ���ϴ� �Լ��� NULL�� ������ ��. */

	local = localtime(&now);/* time�̶�� �Լ��� ��ȯ�ϴ� �ð��� ����� ���� ���� �� �ִ� �����Ͱ� �ƴϴ�. �װ� ����� �б� ���� �ٲ��ִ� �Լ��� localtime�Լ��� �Ű������δ� time�Լ��� ��ȯ�� �������� �ּҰ� ���� ����ü �����ͷ� ��ȯ*/

	fprintf(stderr, "[%02d:%02d:%02d] %s\n", local->tm_hour, local->tm_min, local->tm_sec, msg);
}