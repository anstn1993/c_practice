#include <stdio.h>
#include <string.h>

#include "buffered_print.h"

#define BUFFER_LENGTH (32)/* 캐릭터 배열(버퍼) 크기 32 */

static size_t s_buffer_index = 0u;/* 현재 버퍼가 어디까지 차있는지를 보여줄 버퍼의 위치 index */
static char s_buffer[BUFFER_LENGTH];/* 계속 쌓아둘 버퍼이기 때문에 전역변수로 설정했고 다른 파일에서 접근할 수 없게 하기 위해서 static사용 */

void buffered_print(const char* src)
{
	size_t num_left;
	const char* p = src;/* 문자열의 시작 위치 포인터 */

	num_left = strlen(src);/* 복사할 문자열의 길이 */
	
	while (num_left > 0) { /*src의 모든 문자를 버퍼로 복사할 때까지 반복문 실행*/
		size_t copy_count = BUFFER_LENGTH - 1 - s_buffer_index;/*버퍼에 복사할 수 있는 문자 수, 최대값 31(널 문자 넣어야 하니까)*/

		const int buffer_empty = s_buffer_index == 0;/* 버퍼의 index가 0이면 buffer는 empty */

		if (num_left < copy_count) {/*버퍼로 복사할 문자수보다 버퍼 안에 남은 공간이 크다면*/
			copy_count = num_left;/*src의 문자열만큼만 복사하면 된다. 굳이 버퍼의 비어있는 양만큼 복사할 이유는 없다*/
		}

		s_buffer_index += copy_count;/* 버퍼 속 현재 위치를 copy_count만큼 증가 */
		num_left -= copy_count;/* src에 남은 문자 수 */

		if (buffer_empty) {/* 버퍼가 비어있었다면 string copy를 해서 바로 넣어주면 되고 */
			strncpy(s_buffer, p, copy_count);
			s_buffer[s_buffer_index] = '\0';/* 널문자 마지막에 추가 */
		}
		else {/* 버퍼에 이미 문자가 들어있다면 그 뒤에 이어 붙이면 된다. */
			strncat(s_buffer, p, copy_count);/* strncat은 자동으로 널 문자를 붙여준다 */
		}

		p += copy_count;/* src 속 문자 이동 */

		if (s_buffer_index == BUFFER_LENGTH - 1) {/* 버퍼가 가득 찼으면 s_buffer를 출력하고 버퍼 속 위치를 0으로 리셋 */
			printf("%s\n", s_buffer);
			s_buffer_index = 0;
		}
	}
}

