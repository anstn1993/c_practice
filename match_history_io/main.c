#include <stdio.h>
#include "match_history_io.h"

#define MATCH_COUNT (5)
#define NUM_CHAMPS (5)

#define BUFFER_LENGTH (4096)

int main(void)
{
	const char* names[NUM_CHAMPS] = {/* 게임 케릭터 배열 */
		"Akali",
		"Sylas",
		"Yasuo",
		"Leblanc",
		"Aatrox"
	};

	const int wins[NUM_CHAMPS] = {/* 각 케릭터의 승수 */
		52,55, 28, 34, 32
	};

	const int losses[NUM_CHAMPS] = {/* 각 케릭터의 패수 */
		62, 38, 31, 21, 21
	};

	const float average_kills[NUM_CHAMPS] = {/* 각 케릭터의 평균 킬수 */
		6.11f, 6.62f, 4.81f, 5.95f, 5.19f
	};
	const float average_deaths[NUM_CHAMPS] = {/* 각 케릭터의 평균 죽음 수 */
		3.65f, 3.87f, 3.97f, 3.05f, 3.23f
	};
	const float average_assists[NUM_CHAMPS] = {/* 각 케릭터의 평균 어시스트 수 */
		4.63f, 6.68f, 4.47f, 5.25f, 6.02f
	};
	
	char buffer[BUFFER_LENGTH];/* 모든 게임 전적을 이 문자열 버퍼에 저장 */

	write_match_history(buffer, BUFFER_LENGTH,/* 버퍼의 길이를 넣어주는 이유는 버퍼 범위를 넘어서 쓰는 경우를 막기 위해서 */
	names, wins, losses, average_kills, average_deaths, average_assists, NUM_CHAMPS);

	read_match_history(buffer);/* 버퍼에서 전적을 읽고 간략한 계산을 한 뒤 결과를 콘솔창에 출력 */

	return 0;
}

