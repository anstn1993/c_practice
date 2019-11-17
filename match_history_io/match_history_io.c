#define _CRT_SECURE_NO_WARNINGS/* ������ clang�����Ϸ����� �������� �ϸ� s(secure)�� ���� �Լ��� ���� ���� �� ��� �����µ� �� ��� ���ִ� ���þ� */

#include <stdio.h>
#include <string.h>

#include "match_history_io.h"

#define LINE_LENGTH (4096)

void write_match_history(char* buffer, size_t buffer_size, const char* names[], const int wins[], const int losses[], const float kills[], const float deaths[], const float assists[], size_t count)
{
	char line[LINE_LENGTH]; /* �� �ٿ� �� è�Ǿ��� ������ ���� */
	size_t i;
	size_t remaining_buffer_size; /* ���� ����� �Ѿ�� �ʵ��� ���� �����ִ� ���� ������ ����� ���� */

	remaining_buffer_size = buffer_size - 1;/* -1�� �� ������ �ι��� ���� */
	buffer[0] = '\0';/* �ι��ڸ� ���� �־��ָ� c������ �� ���ڿ��� �����ϴ� �� */

	for (i = 0; i < count; ++i) {
		size_t num_written;/* �� �ٿ� �Էµ� ���� �� */
		sprintf(line, "%8s %.2f %.2f %.2f %d %d\n", names[i], kills[i], deaths[i], assists[i], wins[i], losses[i]);

		num_written = strlen(line);
		if (num_written > remaining_buffer_size) {/* �����ִ� ���� ũ�⸦ ���� ���� �Ѿ�� ���� �����÷ο�� ������ break; */
			break;
		}

		strcpy(buffer, line);/* line�� ����ִ� ������ ���ۿ� ����, �̰� ������ ������ ���� �ٿ��� ������ �޸� �ּҸ� ��� �Էµ� ���� ����ŭ �ڷ� �̵����ױ� �����̴�. */
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
	while (tokenizer != NULL) {/* �� �̻� ��ūȭ�� �� ������ �� ������ ��ȯ */
		char name[LINE_LENGTH];
		float kills;
		float deaths;
		float assists;
		int wins;
		int losses;

		float kda;
		float win_ratio;
		
		/* ���ڿ��κ��� 6���� ���� ��� �о���µ� �б� ������ �����ߴٸ� �� è�Ǿ��� �׳� �н� */
		if (sscanf(tokenizer, "%s %f %f %f %d %d", name, &kills, &deaths, &assists, &wins, &losses) != 6) {
			continue;
		}

		kda = (kills + assists) / deaths;
		win_ratio = wins * 100.0f / (wins + losses);

		printf("%8s %7.2f %7.2f %7.2f %7.2f %6d %6d %8.2f%%\n", name, kills, deaths, assists, kda, wins, losses, win_ratio);

		tokenizer = strtok(NULL, DELIM);
	}
}
