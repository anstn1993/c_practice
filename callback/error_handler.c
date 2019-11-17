#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

#include "error_handler.h"

static void (*s_handler)(const char*) = NULL;/* 콜백함수를 저장할 정적 전역 변수, 일단 NULL로 초기화*/

void register_error_handler(void (*handler)(const char* msg))
{
	s_handler = handler;
}

void log_error(const char* msg)/* 이 함수는 그냥 콜백함수를 호출하는 역할만 수행 */
{
	if (s_handler != NULL) {
		s_handler(msg);/* 함수 포인터 변수가 정의되어 있으면 바로 함수 실행 */
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

	now = time(NULL);/* 현재 시간을 구하는 함수로 NULL을 넣으면 됨. */

	local = localtime(&now);/* time이라는 함수가 반환하는 시간은 사람이 쉽게 읽을 수 있는 데이터가 아니다. 그걸 사람이 읽기 쉽게 바꿔주는 함수가 localtime함수고 매개변수로는 time함수로 반환된 데이터의 주소가 들어가고 구조체 포인터로 반환*/

	fprintf(stderr, "[%02d:%02d:%02d] %s\n", local->tm_hour, local->tm_min, local->tm_sec, msg);
}