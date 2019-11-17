#include <stdio.h>

int main(void)
{
	int x = 3;
	switch (x) {/*스위치문에는 오직 정수 값만 올 수 있다.*/
	case 0:/*case 레이블로는 상수만 쓸 수 있다. 변하는 수는 사용 불가*/
		printf("Case: 0\n");
		break;/*break를 하지 않으면 다음 case를 계속 차례로 실행시킨다.(fall-through)*/
	case 1:
		printf("Case: 1\n");
		break;
	case 2:
		printf("Case: 2\n");
		break;
	case 3:
		printf("Case: 3\n");
		/*intentional fallthrough*/
	default:
		printf("Default Case\n");
		break;
	}
	return 0;
}