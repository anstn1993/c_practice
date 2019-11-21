#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "hash_function.h"

typedef struct {
	unsigned char age;
	unsigned int id;
	char name[64];
}employee_t;

int main(void)
{
	employee_t person;
	size_t hash;
	float fvalue;

	hash = hash_int(10);
	printf("int     %u\n", hash);
	hash = hash_int(-10);/* 비트패턴을 양수형 정수로 읽어서 출력 */
	printf("int     %u\n", hash);

	hash = hash_int('A');
	printf("char     %u\n", hash);

	hash = hash_float(3.2f);
	printf("float     %u\n", hash);/* 비터패턴을 정수로 읽어서 출력 */
	
	hash = hash_data("Moon Soo Kim", strlen("Moon Soo Kim"));
	printf("string %u\n", hash);

	fvalue = 3.2f;
	hash = hash_data(&fvalue, sizeof(float));
	printf("float  %u\n", hash);/* 비터패턴을 정수로 읽어서 출력 */

	memset(&person, 0, sizeof(employee_t));/* 구조체 메모리 공간을 0으로 초기화해줘야 한다. 그러지 않으면 문자열을 복사해서 넣을 때 공간을 가득 채우지 않으면 나머지 공간에 쓰레기 값이 어떻게 들어가 있을지 몰라서 해시 값에 영향을 주기 때문 */
	person.age = 23;
	person.id = 18274192;
	strcpy(person.name, "Moon Soo Kim");

	hash = hash_data(&person, sizeof(employee_t));
	printf("struct %u\n", hash);

	return 0;

}