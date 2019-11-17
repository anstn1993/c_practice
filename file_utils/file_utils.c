#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "file_utils.h"

void copy_file(const char* src, const char* dst)/* src�� ������ ������ ���, dst�� ������ ���� */
{
	FILE* src_file;
	FILE* dst_file;
	int c;

	src_file = fopen(src, "rb");
	if (src_file == NULL) {/* ���� ó�� */
		perror("error while opening source file");
		return;
	}

	dst_file = fopen(dst, "wb");
	if (dst_file == NULL) {
		perror("error while creating target file");
		goto close_source;/* src������ ����� ���±� ������ �׳� return�ϸ� �� �ǰ� �ݾ���� �ϱ� ������ ���� goto�� ��� */
	}

	c = fgetc(src_file);/* c�� �� ���ھ� ������. ����� ������ ��ġ ǥ���� �ϳ��� �̵� */
	while (c != EOF) {
		fputc(c, dst_file);/* ������ ���Ͽ� c�� ���Ե� ���ڸ� �ϳ��� ���� */
		c = fgetc(src_file);
	}

	if (fclose(dst_file) == EOF) {
		perror("error while closing target file");
	}


close_source:/* goto���� Ÿ�� �ʾƵ� ���������δ� �� �ڵ尡 ����Ǳ� ������ src������ ������. */
	if (fclose(src_file) == EOF)  {
		perror("error while closing source file");
	}
}