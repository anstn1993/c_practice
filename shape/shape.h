#ifndef SHAPE_H
#define SHAPE_H

typedef struct {/* 2���� ��鿡 ��ǥ�� ��Ÿ���� ����ü */
	int x;
	int y;
} point_t;

typedef struct {/* �� �ΰ��� �̾ ���� ���� ��Ÿ���� ����ü */
	point_t start;
	point_t end;
} line_t;

typedef struct {/* �밢���� ��ġ�� �ִ� �� �ΰ��� �˸� �簢���� ���� �� ���� */
	point_t top_left;
	point_t bottom_right;
} rectangle_t;

rectangle_t build_rectangle(point_t p0, point_t p1);/* ������ �� ���� ���� ���� ������ �Ʒ��� ��ġ�� �������� �˻��ϰ� ���� ������ ������ �ؼ� ����ü�� ��ȯ�ϴ� �Լ�*/
int get_line_length_sq(line_t line);/* ���� ���̸� ���ϴµ� ������ ������ ��ȯ */
int get_rectangle_area(rectangle_t rect);/* �簢���� ���̸� ���ϴ� �Լ� */

#endif SHAPE_H