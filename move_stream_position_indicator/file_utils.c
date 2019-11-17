#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "file_utils.h"

#define TRUE (1)
#define FALSE (0)
/* 악보의 도돌이표처럼 파일을 열어서 특정 구간을 반복해서 출력하는 함수 */
void print_with_repeats(const char* filename)
{
	long pos = -1L;/* 되돌아와서 반복을 시작할 위치를 기억하는 변수 */
	int repeating = FALSE;/* 현재 위치가 처음 방문하는 건지 두 번째 방문하는 건지 말해주는 변수 */
	int c;
	FILE* file;

	file = fopen(filename, "r");
	if (file == NULL) {
		perror("error while opening file");
		return;
	}

	c = fgetc(file);
	while (c != EOF) {
		if(c != ':') {/* 읽은 문자가 도돌이표가 아니면 바로 출력하고 다음 문자로 */
			putchar(c);
			goto next_char;
		}
		/* 다음은 도돌이표인 경우 */
		if (!repeating) {/* 최초로 방문한 경우 */
			if (pos < 0) {/* pos가 유효한 위치가 아니라는 건 현재 도돌이표는 시작 도돌이표 */
				pos = ftell(file);/* 이미 도돌이표는 읽은 상황이기 때문에 현재 파일 위치는 도돌이표 다음 문자의 위치 */
				if (pos < 0) {
					perror("error while getting start position");
					break;
				}
			}
			else {/* pos가 유효한 위치를 가진다는 건 현재 도돌이표가 닫는 도돌이표라는 의미 */
				repeating = TRUE;
				/* 처음에서 pos위치만큼 가서 반복 */
				if (fseek(file, pos, SEEK_SET) != 0) {
					perror("error while fseek() to start position");
					break;
				}

			}

			goto next_char;
		}

		/* 도돌이표 구간의 문자열이 다시 출력되고 닫는 도돌이표를 다시 만났을 때 */
		repeating = FALSE;
		pos = -1;

	next_char:/* 바로 다음 문자로 업데이트 */
		c = fgetc(file);
	}

	if (fclose(file) == EOF) {
		perror("error while closing file");

	}

}