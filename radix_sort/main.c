#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "userdata.h"

enum { NUM_USERS = 7 };

int compare_uint(const void* p0, const void* p1);/* 구조체를 틍으로 비교 */

int main(void)
{
	radix_userdata_t users[NUM_USERS];
	size_t i;

	i = 0u;

	users[i].user.id = 482;
	users[i].user.sex = SEX_FEMALE;
	users[i++].user.age = 102;

	users[i].user.id = 510;
	users[i].user.sex = SEX_MALE;
	users[i++].user.age = 22;

	users[i].user.id = 32;
	users[i].user.sex = SEX_UNKNOWN;
	users[i++].user.age = 1;

	users[i].user.id = 221;
	users[i].user.sex = SEX_FEMALE;
	users[i++].user.age = 38;

	users[i].user.id = 15;
	users[i].user.sex = SEX_FEMALE;
	users[i++].user.age = 22;

	users[i].user.id = 333;
	users[i].user.sex = SEX_MALE;
	users[i++].user.age = 1;

	users[i].user.id = 1024;
	users[i].user.sex = SEX_UNKNOWN;
	users[i++].user.age = 52;

	assert(i == NUM_USERS);/* 실제로 i가 7까지 도달했는지를 확인할 수 있다. 디버깅에 유용한 방법 */

	puts("==sort by age, id ==");
	for (i = 0; i < NUM_USERS; ++i) {
		unsigned char age = users[i].user.age;
		unsigned short id = users[i].user.id;
		/* 이 연산을 마치면 상위 16비트는 나이가, 하위 16비트는 id가 된다. 즉 sort_key라는 int형 데이터는 id와 age를 동시에 표현하는 데이터
			나이가 16살이고 id가 4면 0x00100004고 나이가 15살이고 id가 4면 0x00F00004*/
		users[i].sort_key = age << 16 | id;
	}

	qsort(users, NUM_USERS, sizeof(radix_userdata_t), compare_uint);
	for (i = 0; i < NUM_USERS; ++i) {
		printf("age: %3d, id: %5d, sex: %d\n", users[i].user.age, users[i].user.id, users[i].user.sex);
	}

	puts("==sort by age(desc), sex ==");
	assert(SEX_UNKNOWN < (1 << 2));

	for(i = 0; i < NUM_USERS; ++i) {
		unsigned char inv_age = 255 - users[i].user.age;/* char형의 최대값에서 나이를 빼주면 나이가 제일 많던 사람의 값이 제일 작아지면서 내림차순 정렬과 같아짐 */
		sex_t sex = users[i].user.sex;

		users[i].sort_key = inv_age << 2 | sex;/* sex_t의 열거형은 3개의 값만 있기 때문에 2비트면 표현 가능하니까 2칸만 이동 */
	}
	qsort(users, NUM_USERS, sizeof(radix_userdata_t), compare_uint);
	for (i = 0; i < NUM_USERS; ++i) {
		printf("age: %3d, id: %5d, sex: %d\n", users[i].user.age, users[i].user.id, users[i].user.sex);
	}

	return 0;
}

int compare_uint(const void* p0, const void* p1)/* sort key를 비교하는 함수 */
{
	const unsigned int* i0 = p0;
	const unsigned int* i1 = p1;

	return *i0 - *i1;
}