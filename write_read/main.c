#include "file_read_write.h"
#include <stdio.h>
#include <errno.h>
#define NAME_LENGTH (100)
#define TRUE (1)


int main(void)
{	
	char filename[NAME_LENGTH];
	int result;
	size_t i;
	while (TRUE) {
		printf("%s", "���� ���� �Է��ϼ���: ");
		if (fgets(filename, NAME_LENGTH, stdin) == NULL) {
			
			break;
		}
		for (i = 0; i < NAME_LENGTH; ++i) {/* ���� ���ڸ� �ι��ڷ� ��ü */
			if (filename[i] == '\n') {
				filename[i] = '\0';
			}
		}
		printf("�Է��� ���� ��: %s\n", filename);
		result = write(filename);
		
		if (result == TRUE) {
			read(filename);
		}
		
	}
	
	return 0;
}