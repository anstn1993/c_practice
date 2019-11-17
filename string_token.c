#include <stdio.h>
#define TRUE (1);
#define FALSE (0);

/* 첫번째 매개변수 문자열에 두번째 매개변수 문자가 존재하는지 찾고 존재하면 1(true)을 반환하고 존재하지 않으면 0 반환 */
int find_string(const char* str, const char substr)
{
	const char* p = str;/* 검색 대상 문자열 포인터 복사 */
	
	while (*p != '\0') {/* 검색 대상 문자열이 문장의 마지막에 도달할 때까지 반복 */
		if (*p == substr) {/* 검색할 문자가 검색 대상 문자열의 문자와 같다면 */
			return 1;
		}
		else {/* 문자가 검색 대상 문자열의 문자와 다르다면 */
			++p;/* 다음 문자로 이동 */
		}
	}

	return 0;
}


char* get_string_token(char* str, const char* delims)/* 두번째 매개변수를 구분문자로 둬서 첫번째 매개변수로 들어온 문자열의 토큰을 구하는 함수 */
{	
	static char* current_ptr;/* 현재 문자열의 위치를 정적 선언 */
	int is_token_confirmed = FALSE;/* 토큰의 시작 문자열 확정 여부 */
	char* p = NULL;/* 리턴할 포인터 */
	

	if (str != NULL) {/* 함수가 최초로 실행되어서 원본이 전달된 경우 */
		current_ptr = str;/* 문자열의 시작 주소 대입 */
	}

	while (*current_ptr != '\0') {/* 널문자가 아니면 계속 반복*/
		if (find_string(delims, *current_ptr) == 0) {/* 구분문자가 아니라면 */
			if (is_token_confirmed == FALSE) {/* 토큰 주소가 확정되지 않은 경우 */
				p = current_ptr;/* 반환 포인터에 현재 문자의 메모리 주소를 대입하여 토큰 주소를 확정 */
				is_token_confirmed = TRUE;/* 토큰 주소 확정 true */
			}
			++current_ptr;/* 다음 주소로 이동 */
		}
		else {/* 구분문자라면 */
			*current_ptr = '\0';/* 널문자로 수정 */
			++current_ptr;/* 다음 주소로 이동 */

			if (is_token_confirmed == TRUE) {/* 토큰 주소가 확정됐다면 */
				break;/* 반복문 탈출 */
			}
		}
	}
	return p;/* 토큰 주소 return */
}

int main(void)
{
	char msg[] = "Hi, MoonSoo. Hey. Bye";/* 원본 수정이 가해지기 때문에 const를 쓰면 안 되고 스택 메모리에 저장 */
	const char delims[] = ",. ";/* 구분 문자 */

	char* token = get_string_token(msg, delims);
	while (token != NULL) {
		printf("%s\n", token);
		token = get_string_token(NULL, delims);
	}
}