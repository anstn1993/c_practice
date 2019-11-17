#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

void register_error_handler(void (*handler)(const char* msg));/* � ������ ����� ���� �޼����� ��½����� �ݹ� �Լ��� �Լ� ������ ���� ������ �������� �Լ� */

void log_error(const char* msg);/* � ������ ����� ������ ȣ���ϴ� �Լ��ε� �� �Լ� �ȿ��� �ݹ��Լ��� ���� */

void default_error_handler(const char* msg);

#endif /* ERROR_HANDLER_H */