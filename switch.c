#include <stdio.h>

int main(void)
{
	int x = 3;
	switch (x) {/*����ġ������ ���� ���� ���� �� �� �ִ�.*/
	case 0:/*case ���̺�δ� ����� �� �� �ִ�. ���ϴ� ���� ��� �Ұ�*/
		printf("Case: 0\n");
		break;/*break�� ���� ������ ���� case�� ��� ���ʷ� �����Ų��.(fall-through)*/
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