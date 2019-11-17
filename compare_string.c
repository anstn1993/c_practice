#include <stdio.h>

int compare_string1(const char* str1, const char* str2) 
{
	while (*str1 != '\0' && *str1 == *str2) {/* 첫번째 문자열의 문자가 널문자가 아니고 두 문자가 같으면 계속 다음 문자로 이동을 하고 첫번째 문자열의 문자가 널문자거나 두 문자가 달라지는 순간 탈출 */
		++str1;
		++str2;
	}

	return *str1 - *str2;/* 탈출한 시점의 문자의 아스키코드 숫자를 빼서 0이 return되면 같은 문자열 이외의 문자가 return되면 다른 문자열 */
}

int compare_string2(const char* str1, const char* str2)
{
	while (*str1 != '\0' && *str1 == *str2) {/* 첫번째 문자열의 문자가 널문자가 아니고 두 문자가 같으면 계속 다음 문자로 이동을 하고 첫번째 문자열의 문자가 널문자거나 두 문자가 달라지는 순간 탈출 */
		++str1;
		++str2;
	}

	if (*str1 == *str2) {
		return 0;/* 탈출한 시점의 문자의 아스키코드 숫자를 빼서 0이 return */
	}

	return (*str1 > *str2)? 1 : -1;/* 두 문자의 아스키코드 숫자가 다르면 -1이나 1 리턴 */
}