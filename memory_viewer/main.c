#include <stdio.h>

int main(void)
{
	const int NUM = 0x12345678;
	const char* NUM_ADDRESS = (char*)&NUM;/* 인트형의 주소값을 char형으로 캐스팅하여 메모리 이동시 1바이트씩 점프가 가능하게 만든다. */

	size_t i;

	for (i = 0; i < sizeof(NUM); i++) {
		printf("%hhx ", NUM_ADDRESS[i]);/* %hhx: 16진수 출력, *(NUM_ADDRESS + 1) */
	}
	printf("\n");

	printf("NUM in hex form: 0x%x", NUM);/* %x: 16진수 출력 */


}