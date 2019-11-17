#ifndef COLOR_H
#define COLOR_H

typedef union {/* ������ �������� ������ ���ؼ� �� ���� ä�ο� �����ϸ鼭�� ��ü ä���� ���յ� ������ ������ �� ����ü�� ����ϸ� ���� */
	unsigned int val;
	struct {
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;/* alphaä�η� ������ �ǹ�(0xFF�� ���� ������, 0x00�� ���� ����) */
	} rgba;
} color_t;

#endif /* COLOR_H */