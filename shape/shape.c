#include <stdio.h>

#include "shape.h"

rectangle_t build_rectangle(point_t p0, point_t p1)
{
	rectangle_t rect;
	
	if (p0.x < p1.x) {
		rect.top_left.x = p0.x;
		rect.bottom_right.x = p1.x;
	}
	else {
		rect.top_left.x = p1.x;
		rect.bottom_right.x = p0.x;
	}

	if (p0.y < p1.y) {
		rect.top_left.y = p0.y;
		rect.bottom_right.y = p1.y;
	}
	else {
		rect.top_left.y = p1.y;
		rect.bottom_right.y = p0.y;
	}
	return rect;
}

int get_line_length_sq(line_t line) 
{
	int x_diff;
	int y_diff;

	x_diff = line.end.x - line.start.x;
	y_diff = line.end.y - line.start.y;

	return x_diff * x_diff + y_diff * y_diff;
}

int get_rectangle_area(rectangle_t rect)
{
	int w;
	int h;

	/* abs함수는 매개변수의 절대값 반환, build_rectangle함수로 사각형 구조체를 만들지 않고 직접 선언해서 값을 임의로 집어넣는 경우에 대비해서 설정 */
	w = abs(rect.bottom_right.x - rect.top_left.x);
	h = abs(rect.bottom_right.y - rect.top_left.y);

	return w * h;
}

