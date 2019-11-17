#include <stdio.h>

int g_x = 100;/*코딩 표준에 의하면 전역변수는 접두어 'g_'를 변수명에 붙여서 그것이 전역변수인 것을 알게 하자고 약속*/

void increase_number(void) 
{
	int y = 200;
	y += 100;/* 지역변수이기 때문에 함수가 종료되면 변수도 스택 메모리에서 소멸 */
	g_x += 100;/*파일 범위에 있는 전역 변수에 접근, 데이터 섹션에 저장 */
}

int main(void)
{
	printf("g_x: %d\n", g_x);/* 100 */
	increase_number();
	printf("g_x: %d\n", g_x);/* 200 */
	/* 아래의 코드는 컴파일 오류 */
	/* printf("y: %d\n", y); */
}