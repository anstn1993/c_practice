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
		printf("%s", "파일 명을 입력하세요: ");
		if (fgets(filename, NAME_LENGTH, stdin) == NULL) {
			
			break;
		}
		for (i = 0; i < NAME_LENGTH; ++i) {/* 새줄 문자를 널문자로 교체 */
			if (filename[i] == '\n') {
				filename[i] = '\0';
			}
		}
		printf("입력한 파일 명: %s\n", filename);
		result = write(filename);
		
		if (result == TRUE) {
			read(filename);
		}
		
	}
	
	return 0;
}