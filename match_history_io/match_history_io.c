#define _CRT_SECURE_NO_WARNINGS/* 윈도우 clang컴파일러에서 컴파일을 하면 s(secure)가 붙은 함수를 쓰지 않을 때 경고가 나오는데 그 경고를 꺼주는 지시어 */

#include <stdio.h>
#include <string.h>

#include "match_history_io.h"

#define LINE_LENGTH (4096)

void write_match_history(char* buffer, size_t buffer_size, const char* names[], const int wins[], const int losses[], const float kills[], const float deaths[], const float assists[], size_t count)
{
	char line[LINE_LENGTH]; /* 한 줄에 한 챔피언의 전적을 저장 */
	size_t i;
	size_t remaining_buffer_size; /* 버퍼 사이즈를 넘어서지 않도록 현재 남아있는 버퍼 공간을 기억할 변수 */

	remaining_buffer_size = buffer_size - 1;/* -1을 한 이유는 널문자 때문 */
	buffer[0] = '\0';/* 널문자를 먼저 넣어주면 c에서는 빈 문자열을 정의하는 것 */

	for (i = 0; i < count; ++i) {
		size_t num_written;/* 한 줄에 입력된 글자 수 */
		sprintf(line, "%8s %.2f %.2f %.2f %d %d\n", names[i], kills[i], deaths[i], assists[i], wins[i], losses[i]);

		num_written = strlen(line);
		if (num_written > remaining_buffer_size) {/* 남아있는 버퍼 크기를 글자 수가 넘어서면 버퍼 오버플로우기 때문에 break; */
			break;
		}

		strcpy(buffer, line);/* line에 들어있는 내용을 버퍼에 복사, 이게 가능한 이유는 다음 줄에서 버퍼의 메모리 주소를 계속 입력된 글자 수만큼 뒤로 이동시켰기 때문이다. */
		buffer += num_written;
		remaining_buffer_size -= num_written;
	}
}

void read_match_history(char* buffer) 
{
	const char* DELIM = "\n";
	char* tokenizer;
	
	printf("%8s %7s %7s %7s %6s %6s %9s\n", "Champ", "Kills", "Deaths", "Assists", "KDA", "Wins", "Losses", "Win Ration");
	tokenizer = strtok(buffer, DELIM);
	while (tokenizer != NULL) {/* 더 이상 토큰화할 게 없으면 널 포인터 반환 */
		char name[LINE_LENGTH];
		float kills;
		float deaths;
		float assists;
		int wins;
		int losses;

		float kda;
		float win_ratio;
		
		/* 문자열로부터 6개의 값을 모두 읽어오는데 읽기 연산이 실패했다면 이 챔피언은 그냥 패스 */
		if (sscanf(tokenizer, "%s %f %f %f %d %d", name, &kills, &deaths, &assists, &wins, &losses) != 6) {
			continue;
		}

		kda = (kills + assists) / deaths;
		win_ratio = wins * 100.0f / (wins + losses);

		printf("%8s %7.2f %7.2f %7.2f %7.2f %6d %6d %8.2f%%\n", name, kills, deaths, assists, kda, wins, losses, win_ratio);

		tokenizer = strtok(NULL, DELIM);
	}
}
