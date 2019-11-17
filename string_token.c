#include <stdio.h>
#define TRUE (1);
#define FALSE (0);

/* ù��° �Ű����� ���ڿ��� �ι�° �Ű����� ���ڰ� �����ϴ��� ã�� �����ϸ� 1(true)�� ��ȯ�ϰ� �������� ������ 0 ��ȯ */
int find_string(const char* str, const char substr)
{
	const char* p = str;/* �˻� ��� ���ڿ� ������ ���� */
	
	while (*p != '\0') {/* �˻� ��� ���ڿ��� ������ �������� ������ ������ �ݺ� */
		if (*p == substr) {/* �˻��� ���ڰ� �˻� ��� ���ڿ��� ���ڿ� ���ٸ� */
			return 1;
		}
		else {/* ���ڰ� �˻� ��� ���ڿ��� ���ڿ� �ٸ��ٸ� */
			++p;/* ���� ���ڷ� �̵� */
		}
	}

	return 0;
}


char* get_string_token(char* str, const char* delims)/* �ι�° �Ű������� ���й��ڷ� �ּ� ù��° �Ű������� ���� ���ڿ��� ��ū�� ���ϴ� �Լ� */
{	
	static char* current_ptr;/* ���� ���ڿ��� ��ġ�� ���� ���� */
	int is_token_confirmed = FALSE;/* ��ū�� ���� ���ڿ� Ȯ�� ���� */
	char* p = NULL;/* ������ ������ */
	

	if (str != NULL) {/* �Լ��� ���ʷ� ����Ǿ ������ ���޵� ��� */
		current_ptr = str;/* ���ڿ��� ���� �ּ� ���� */
	}

	while (*current_ptr != '\0') {/* �ι��ڰ� �ƴϸ� ��� �ݺ�*/
		if (find_string(delims, *current_ptr) == 0) {/* ���й��ڰ� �ƴ϶�� */
			if (is_token_confirmed == FALSE) {/* ��ū �ּҰ� Ȯ������ ���� ��� */
				p = current_ptr;/* ��ȯ �����Ϳ� ���� ������ �޸� �ּҸ� �����Ͽ� ��ū �ּҸ� Ȯ�� */
				is_token_confirmed = TRUE;/* ��ū �ּ� Ȯ�� true */
			}
			++current_ptr;/* ���� �ּҷ� �̵� */
		}
		else {/* ���й��ڶ�� */
			*current_ptr = '\0';/* �ι��ڷ� ���� */
			++current_ptr;/* ���� �ּҷ� �̵� */

			if (is_token_confirmed == TRUE) {/* ��ū �ּҰ� Ȯ���ƴٸ� */
				break;/* �ݺ��� Ż�� */
			}
		}
	}
	return p;/* ��ū �ּ� return */
}

int main(void)
{
	char msg[] = "Hi, MoonSoo. Hey. Bye";/* ���� ������ �������� ������ const�� ���� �� �ǰ� ���� �޸𸮿� ���� */
	const char delims[] = ",. ";/* ���� ���� */

	char* token = get_string_token(msg, delims);
	while (token != NULL) {
		printf("%s\n", token);
		token = get_string_token(NULL, delims);
	}
}