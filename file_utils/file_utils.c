#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "file_utils.h"

void copy_file(const char* src, const char* dst)/* src는 복사할 파일의 경로, dst는 목적지 파일 */
{
	FILE* src_file;
	FILE* dst_file;
	int c;

	src_file = fopen(src, "rb");
	if (src_file == NULL) {/* 오류 처리 */
		perror("error while opening source file");
		return;
	}

	dst_file = fopen(dst, "wb");
	if (dst_file == NULL) {
		perror("error while creating target file");
		goto close_source;/* src파일을 열어둔 상태기 때문에 그냥 return하면 안 되고 닫아줘야 하기 때문에 따로 goto문 사용 */
	}

	c = fgetc(src_file);/* c에 한 글자씩 가져옴. 실행될 때마다 위치 표시자 하나씩 이동 */
	while (c != EOF) {
		fputc(c, dst_file);/* 목적지 파일에 c에 대입된 글자를 하나씩 대입 */
		c = fgetc(src_file);
	}

	if (fclose(dst_file) == EOF) {
		perror("error while closing target file");
	}


close_source:/* goto문을 타지 않아도 최종적으로는 이 코드가 실행되기 때문에 src파일은 닫힌다. */
	if (fclose(src_file) == EOF)  {
		perror("error while closing source file");
	}
}