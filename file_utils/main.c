#include <stdio.h>
#include <string.h>
#include "file_utils.h"

int main(int argc, const char* argv[])/* 2개의 파일명을 인자로 받는다(argc = 3) */
{
	if (argc != 3) {
		FILE* out;
		
		if (argc == 2 && strcmp(argv[1], "--help") == 0) {/* 사용자가 프로그램 사용법을 알고 싶어서 --help를 입력한 경우 */
			out = stdout;
		}
		else {/* 입력 자체를 잘못한 경우 */
			out = stderr;
		}

		fprintf(out, "+--------------------------------------------------------+\n");
		fprintf(out, "|                New File Copier v1+\n");
		fprintf(out, "+--------------------------------------------------------+\n");
		fprintf(out, "     usage: copy <src> <dst>\n");
		fprintf(out, "     usage: copy --help to see help page");

		if (out == stderr) {
			fprintf(out, "\nerror: invalid arguments\n");
		}
		return 1;
	}
	copy_file(argv[1], argv[2]);
	return 0;
}