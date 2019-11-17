#include <stdio.h>
#include <string.h>

#include "buffered_print.h"

#define BUFFER_LENGTH (32)/* ĳ���� �迭(����) ũ�� 32 */

static size_t s_buffer_index = 0u;/* ���� ���۰� ������ ���ִ����� ������ ������ ��ġ index */
static char s_buffer[BUFFER_LENGTH];/* ��� �׾Ƶ� �����̱� ������ ���������� �����߰� �ٸ� ���Ͽ��� ������ �� ���� �ϱ� ���ؼ� static��� */

void buffered_print(const char* src)
{
	size_t num_left;
	const char* p = src;/* ���ڿ��� ���� ��ġ ������ */

	num_left = strlen(src);/* ������ ���ڿ��� ���� */
	
	while (num_left > 0) { /*src�� ��� ���ڸ� ���۷� ������ ������ �ݺ��� ����*/
		size_t copy_count = BUFFER_LENGTH - 1 - s_buffer_index;/*���ۿ� ������ �� �ִ� ���� ��, �ִ밪 31(�� ���� �־�� �ϴϱ�)*/

		const int buffer_empty = s_buffer_index == 0;/* ������ index�� 0�̸� buffer�� empty */

		if (num_left < copy_count) {/*���۷� ������ ���ڼ����� ���� �ȿ� ���� ������ ũ�ٸ�*/
			copy_count = num_left;/*src�� ���ڿ���ŭ�� �����ϸ� �ȴ�. ���� ������ ����ִ� �縸ŭ ������ ������ ����*/
		}

		s_buffer_index += copy_count;/* ���� �� ���� ��ġ�� copy_count��ŭ ���� */
		num_left -= copy_count;/* src�� ���� ���� �� */

		if (buffer_empty) {/* ���۰� ����־��ٸ� string copy�� �ؼ� �ٷ� �־��ָ� �ǰ� */
			strncpy(s_buffer, p, copy_count);
			s_buffer[s_buffer_index] = '\0';/* �ι��� �������� �߰� */
		}
		else {/* ���ۿ� �̹� ���ڰ� ����ִٸ� �� �ڿ� �̾� ���̸� �ȴ�. */
			strncat(s_buffer, p, copy_count);/* strncat�� �ڵ����� �� ���ڸ� �ٿ��ش� */
		}

		p += copy_count;/* src �� ���� �̵� */

		if (s_buffer_index == BUFFER_LENGTH - 1) {/* ���۰� ���� á���� s_buffer�� ����ϰ� ���� �� ��ġ�� 0���� ���� */
			printf("%s\n", s_buffer);
			s_buffer_index = 0;
		}
	}
}

