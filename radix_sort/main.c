#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "userdata.h"

enum { NUM_USERS = 7 };

int compare_uint(const void* p0, const void* p1);/* ����ü�� �v���� �� */

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

	assert(i == NUM_USERS);/* ������ i�� 7���� �����ߴ����� Ȯ���� �� �ִ�. ����뿡 ������ ��� */

	puts("==sort by age, id ==");
	for (i = 0; i < NUM_USERS; ++i) {
		unsigned char age = users[i].user.age;
		unsigned short id = users[i].user.id;
		/* �� ������ ��ġ�� ���� 16��Ʈ�� ���̰�, ���� 16��Ʈ�� id�� �ȴ�. �� sort_key��� int�� �����ʹ� id�� age�� ���ÿ� ǥ���ϴ� ������
			���̰� 16���̰� id�� 4�� 0x00100004�� ���̰� 15���̰� id�� 4�� 0x00F00004*/
		users[i].sort_key = age << 16 | id;
	}

	qsort(users, NUM_USERS, sizeof(radix_userdata_t), compare_uint);
	for (i = 0; i < NUM_USERS; ++i) {
		printf("age: %3d, id: %5d, sex: %d\n", users[i].user.age, users[i].user.id, users[i].user.sex);
	}

	puts("==sort by age(desc), sex ==");
	assert(SEX_UNKNOWN < (1 << 2));

	for(i = 0; i < NUM_USERS; ++i) {
		unsigned char inv_age = 255 - users[i].user.age;/* char���� �ִ밪���� ���̸� ���ָ� ���̰� ���� ���� ����� ���� ���� �۾����鼭 �������� ���İ� ������ */
		sex_t sex = users[i].user.sex;

		users[i].sort_key = inv_age << 2 | sex;/* sex_t�� �������� 3���� ���� �ֱ� ������ 2��Ʈ�� ǥ�� �����ϴϱ� 2ĭ�� �̵� */
	}
	qsort(users, NUM_USERS, sizeof(radix_userdata_t), compare_uint);
	for (i = 0; i < NUM_USERS; ++i) {
		printf("age: %3d, id: %5d, sex: %d\n", users[i].user.age, users[i].user.id, users[i].user.sex);
	}

	return 0;
}

int compare_uint(const void* p0, const void* p1)/* sort key�� ���ϴ� �Լ� */
{
	const unsigned int* i0 = p0;
	const unsigned int* i1 = p1;

	return *i0 - *i1;
}