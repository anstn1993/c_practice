#include <stdio.h>
#include "match_history_io.h"

#define MATCH_COUNT (5)
#define NUM_CHAMPS (5)

#define BUFFER_LENGTH (4096)

int main(void)
{
	const char* names[NUM_CHAMPS] = {/* ���� �ɸ��� �迭 */
		"Akali",
		"Sylas",
		"Yasuo",
		"Leblanc",
		"Aatrox"
	};

	const int wins[NUM_CHAMPS] = {/* �� �ɸ����� �¼� */
		52,55, 28, 34, 32
	};

	const int losses[NUM_CHAMPS] = {/* �� �ɸ����� �м� */
		62, 38, 31, 21, 21
	};

	const float average_kills[NUM_CHAMPS] = {/* �� �ɸ����� ��� ų�� */
		6.11f, 6.62f, 4.81f, 5.95f, 5.19f
	};
	const float average_deaths[NUM_CHAMPS] = {/* �� �ɸ����� ��� ���� �� */
		3.65f, 3.87f, 3.97f, 3.05f, 3.23f
	};
	const float average_assists[NUM_CHAMPS] = {/* �� �ɸ����� ��� ��ý�Ʈ �� */
		4.63f, 6.68f, 4.47f, 5.25f, 6.02f
	};
	
	char buffer[BUFFER_LENGTH];/* ��� ���� ������ �� ���ڿ� ���ۿ� ���� */

	write_match_history(buffer, BUFFER_LENGTH,/* ������ ���̸� �־��ִ� ������ ���� ������ �Ѿ ���� ��츦 ���� ���ؼ� */
	names, wins, losses, average_kills, average_deaths, average_assists, NUM_CHAMPS);

	read_match_history(buffer);/* ���ۿ��� ������ �а� ������ ����� �� �� ����� �ܼ�â�� ��� */

	return 0;
}

