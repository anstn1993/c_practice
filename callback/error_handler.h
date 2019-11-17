#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

void register_error_handler(void (*handler)(const char* msg));/* 어떤 문제가 생기면 에러 메세지를 출력시켜줄 콜백 함수를 함수 포인터 전역 변수에 저정해줄 함수 */

void log_error(const char* msg);/* 어떤 문제가 생기면 실제로 호출하는 함수인데 이 함수 안에서 콜백함수를 실행 */

void default_error_handler(const char* msg);

#endif /* ERROR_HANDLER_H */