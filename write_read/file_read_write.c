#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "file_read_write.h"
#define LENGTH (1024)
int write(const char* filename)
{
	FILE* file;
	char buffer[LENGTH];


	file = fopen(filename, "w");
	
	if (file == NULL) {
		perror("파일을 여는 중에 문제가 생겼습니다.");
		return 0;
	}

	printf("%s", "저장할 데이터를 입력하세요: ");
	while (fgets(buffer, "%s", stdin) != NULL) {
		fwrite(buffer, strlen(buffer), sizeof(char), file);
	}

	fflush(file);
	
	if (fclose(file) == EOF) {
		perror("파일을 닫는 중에 문제가 생겼습니다.");
		return 0;
	}
	printf("%s", "파일 저장 성공\n");
	return 1;
}

void read(const char* filename)
{
	FILE* file;
	char buffer[LENGTH];
	
	file = fopen(filename, "rb");
	if (file == NULL) {
		perror("파일을 여는 중에 문제가 생겼습니다.");
		return;
	}
	printf("파일 %s의 데이터 출력: ", filename);
	while (fgets(buffer, LENGTH, file) != NULL) {
		printf("%s", buffer);
	}

	if (fclose(file) == EOF) {
		perror("파일을 닫는 중에 문제가 생겼습니다.");
	}
}