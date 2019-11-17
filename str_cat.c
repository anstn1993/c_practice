#include<stdio.h>

void string_cat(char* dest, const char* src)
{
	while (*dest != '\0') {/* ���� ���ڿ��� ���� ������(\0)���� �̵� */
		dest++;
	}

	while (*src != '\0') {/* src�� ���ڿ��� 0\�� �ƴ� �������� ��� �̵��ϸ鼭 dest�迭�� ���� ���ش�. */
		*dest++ = *src++;
	}

	*dest = '\0';/* \0�� �ݺ������� ���� �ʾұ� ������ \0�� �߰����ش�. */
}

int main(void)
{	
	const char* src = "Mansoo";
	char dest[13] = "Hello ";

	string_cat(dest, src);

	printf("%s", dest);
}