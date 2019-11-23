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
		perror("������ ���� �߿� ������ ������ϴ�.");
		return 0;
	}

	printf("%s", "������ �����͸� �Է��ϼ���: ");
	while (fgets(buffer, "%s", stdin) != NULL) {
		fwrite(buffer, strlen(buffer), sizeof(char), file);
	}

	fflush(file);
	
	if (fclose(file) == EOF) {
		perror("������ �ݴ� �߿� ������ ������ϴ�.");
		return 0;
	}
	printf("%s", "���� ���� ����\n");
	return 1;
}

void read(const char* filename)
{
	FILE* file;
	char buffer[LENGTH];
	
	file = fopen(filename, "rb");
	if (file == NULL) {
		perror("������ ���� �߿� ������ ������ϴ�.");
		return;
	}
	printf("���� %s�� ������ ���: ", filename);
	while (fgets(buffer, LENGTH, file) != NULL) {
		printf("%s", buffer);
	}

	if (fclose(file) == EOF) {
		perror("������ �ݴ� �߿� ������ ������ϴ�.");
	}
}