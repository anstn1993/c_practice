#ifndef SHAPE_H
#define SHAPE_H

typedef struct {/* 2차원 평면에 좌표를 나타내는 구조체 */
	int x;
	int y;
} point_t;

typedef struct {/* 점 두개를 이어서 만든 선을 나타내는 구조체 */
	point_t start;
	point_t end;
} line_t;

typedef struct {/* 대각선의 위치에 있는 점 두개를 알면 사각형을 구할 수 있음 */
	point_t top_left;
	point_t bottom_right;
} rectangle_t;

rectangle_t build_rectangle(point_t p0, point_t p1);/* 실제로 두 점이 왼쪽 위와 오른쪽 아래에 위치한 점인지를 검사하고 맞지 않으면 조정을 해서 구조체로 반환하는 함수*/
int get_line_length_sq(line_t line);/* 선의 길이를 구하는데 길이의 제곱이 반환 */
int get_rectangle_area(rectangle_t rect);/* 사각형의 넓이를 구하는 함수 */

#endif SHAPE_H