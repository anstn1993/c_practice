#include <stdio.h>

/* n팩토리얼을 계산 후 출력함(goto의 안 좋은 예) */
void calculate_factorial(const unsigned int n)
{
	unsigned int result = 1;
	unsigned int i = 1;

	goto begin_loop;
	/* 후방으로 goto하는 것은 안 좋은 예다. 코드 읽기 정말 힘들어진다. 그냥 아래로 점프해도 될 걸
	심지어 그냥 begin_loop에서 print하고 return하면 될 것을 이렇게 하는 건 미친 짓*/
exit_loop:
	printf("%d factorial: %d\n", n, result); 
	return;

begin_loop:
	while (i <= n) {
		result *= i ;
		++i;
	}

	goto exit_loop;
}

/* 두번째 매개변수의 숫자가 첫번째 매개변수인 2차원 배열(3*3행렬)에 있는지 찾는 함수(goto의 좋은 예)*/
void find_number(int arr[3][3], const int n) {
	size_t i;/* 행 index */
	size_t j;/* 열 index */

	/* 만약 두번째 매개변수가 첫번째 매개변수 행렬에 없으면 이 행렬에서 찾아본다. */
	int default_matrix[4][4] = {
		{4, 1, 3, 1},
		{9, 2 ,-1, 6},
		{6, 0, 10, 5},
		{1, 2, 3, 3}
	};
	
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			if (arr[i][j] == n) {
				printf("%d found in square_matrix.", n);
				goto found;
			}
		}
	}

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			if (default_matrix[i][j] == n) {
				printf("%d found in default_matrix.", n);
				goto found;
			}
		}
	}

found:
	printf("Number: %d\n", n);
	printf("Index positions: (%zu, %zu)\n", i, j);
}

int main(void)
{
	int square_matrix[3][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8}
	};

	calculate_factorial(4);/* 4팩토리얼 */
	find_number(square_matrix, 0);/* found in square_matrix */
	find_number(square_matrix, -1);/* found in default_matrix */
}

