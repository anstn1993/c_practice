#include <stdio.h>

int main(void)
{
	const int NUM = 0x12345678;
	const char* NUM_ADDRESS = (char*)&NUM;/* ��Ʈ���� �ּҰ��� char������ ĳ�����Ͽ� �޸� �̵��� 1����Ʈ�� ������ �����ϰ� �����. */

	size_t i;

	for (i = 0; i < sizeof(NUM); i++) {
		printf("%hhx ", NUM_ADDRESS[i]);/* %hhx: 16���� ���, *(NUM_ADDRESS + 1) */
	}
	printf("\n");

	printf("NUM in hex form: 0x%x", NUM);/* %x: 16���� ��� */


}