#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "file_utils.h"

#define TRUE (1)
#define FALSE (0)
/* �Ǻ��� ������ǥó�� ������ ��� Ư�� ������ �ݺ��ؼ� ����ϴ� �Լ� */
void print_with_repeats(const char* filename)
{
	long pos = -1L;/* �ǵ��ƿͼ� �ݺ��� ������ ��ġ�� ����ϴ� ���� */
	int repeating = FALSE;/* ���� ��ġ�� ó�� �湮�ϴ� ���� �� ��° �湮�ϴ� ���� �����ִ� ���� */
	int c;
	FILE* file;

	file = fopen(filename, "r");
	if (file == NULL) {
		perror("error while opening file");
		return;
	}

	c = fgetc(file);
	while (c != EOF) {
		if(c != ':') {/* ���� ���ڰ� ������ǥ�� �ƴϸ� �ٷ� ����ϰ� ���� ���ڷ� */
			putchar(c);
			goto next_char;
		}
		/* ������ ������ǥ�� ��� */
		if (!repeating) {/* ���ʷ� �湮�� ��� */
			if (pos < 0) {/* pos�� ��ȿ�� ��ġ�� �ƴ϶�� �� ���� ������ǥ�� ���� ������ǥ */
				pos = ftell(file);/* �̹� ������ǥ�� ���� ��Ȳ�̱� ������ ���� ���� ��ġ�� ������ǥ ���� ������ ��ġ */
				if (pos < 0) {
					perror("error while getting start position");
					break;
				}
			}
			else {/* pos�� ��ȿ�� ��ġ�� �����ٴ� �� ���� ������ǥ�� �ݴ� ������ǥ��� �ǹ� */
				repeating = TRUE;
				/* ó������ pos��ġ��ŭ ���� �ݺ� */
				if (fseek(file, pos, SEEK_SET) != 0) {
					perror("error while fseek() to start position");
					break;
				}

			}

			goto next_char;
		}

		/* ������ǥ ������ ���ڿ��� �ٽ� ��µǰ� �ݴ� ������ǥ�� �ٽ� ������ �� */
		repeating = FALSE;
		pos = -1;

	next_char:/* �ٷ� ���� ���ڷ� ������Ʈ */
		c = fgetc(file);
	}

	if (fclose(file) == EOF) {
		perror("error while closing file");

	}

}