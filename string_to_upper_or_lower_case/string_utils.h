#ifndef STRING_UTILS_H
#define STRING_UTILS_H

/* ���� �� �Լ��� �Ű������� char�� �ƴ϶� int���� ������ �׳� cǥ���� �׷��� �����̴�.  */
int is_alpha(int c);/* ���ڰ� ���� ���ĺ��̳ĸ� �Ǵ��ϴ� �� */

int to_upper(int c);/* �� �Լ��� ��ȯ���� ��Ʈ�� ������ cǥ���� �׷��� ����. �׸��� ������ char���� ���� */
int to_lower(int c);
/* ���� �� �Լ��� �̹� cǥ�� ���̺귯���� ���������� ������ �ۼ��� �� �־�� �Ѵ�. �ƽ�Ű�ڵ带 �ƴϱ� */

void string_toupper(char* str);/* �Ű������� ���� �����͸� �����ϴ� ���̱� ������ ��ȯ ���� �� ���൵ ��. �̷��� ������ ���� �����ϴ� ���� in place��� �Ѵ�. �� in place�ϰ� �ٲ۴ٰ� �ϸ� ������ �ٲٶ�� �� */
void string_tolower(char* str);

#endif /* STRING_UTILS_H */