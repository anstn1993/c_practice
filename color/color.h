#ifndef COLOR_H
#define COLOR_H

typedef union {/* 색상의 디테일한 조정을 위해서 각 색상 채널에 접근하면서도 전체 채널이 조합된 색상값을 가져올 때 공용체를 사용하면 유용 */
	unsigned int val;
	struct {
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;/* alpha채널로 투명도를 의미(0xFF는 완전 불투명, 0x00은 완전 투명) */
	} rgba;
} color_t;

#endif /* COLOR_H */