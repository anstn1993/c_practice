#include<stdio.h>

void string_cat(char* dest, const char* src)
{
	while (*dest != '\0') {/* 현재 문자열의 가장 마지막(\0)까지 이동 */
		dest++;
	}

	while (*src != '\0') {/* src의 문자열이 0\이 아닌 순간까지 계속 이동하면서 dest배열에 값을 써준다. */
		*dest++ = *src++;
	}

	*dest = '\0';/* \0은 반복문에서 들어가지 않았기 때문에 \0을 추가해준다. */
}

int main(void)
{	
	const char* src = "Mansoo";
	char dest[13] = "Hello ";

	string_cat(dest, src);

	printf("%s", dest);
}