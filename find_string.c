#include <stdio.h>
#include <string.h>

/* 첫번째 매개변수 문자열에 두번째 매개변수 문자열이 존재하는지 찾고 존재하면 substr문자열의 시작 문자 주소부터 문자열을 반환하고 존재하지 않으면 null 반환 */
char* find_string(const char* str, const char* substr)
{
	const char* p = str;/* 검색 대상 문자열 포인터 복사 */
	const char* sub_p = substr;/* 검색할 문자열 포인터 복사 */
	size_t move_count = 0u;/* 겹치는 문자열이 존재할 때마다 1씩 추가하여 나중에 겹치는 문자열의 시작 문자로 메모리 주소를 되돌리기 위한 변수 */
	while (*p != '\0') {/* 검색 대상 문자열이 문장의 마지막에 도달할 때까지 반복 */
		if (*p == *sub_p) {/* 검색할 문자열의 첫번째 문자가 현재 검색 대상 문자열의 문자와 같다면 */
			++p;/* 검색 대상 문자열의 문자를 다음 문자로 이동 */
			++sub_p;/* 검색할 문자열의 문자를 다음 문자로 이동 */
			++move_count;/* 주소 이동 count +1 */
			if (*sub_p == '\0') {/* 검색할 문자열의 마지막까지 도달한 경우 그 문자열이 검색 대상이 되는 문자열에 존재함을 의미 */
				return p - move_count;/* 현재 검색할 문자열의 위치에서 이동한 만큼 되돌아갔을 때의 주소 값 반환 */
			}
		}
		else {/* 검색할 문자열의 첫번째 문자가 현재 검색 대상 문자열의 문자와 다르다면 */
			++p;/* 다음 문자로 이동 */
		}
	}

	return NULL;
}

int main(void)
{
	char msg[] = "There is MoonSoo that I'm looking for.";
	/*char msg[] = "내가 찾는 사람은 문수 입니다. ";*/
	char* result = find_string(msg, "MoonSoo");
	/*char* result = find_string(msg, "문수");*/
	printf("%s\n", result);
	return 0;
}