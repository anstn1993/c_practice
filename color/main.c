#include <stdio.h>

#include "color.h"

int main(void)
{
	color_t trans_black;
	color_t red;
	color_t yellow;

	trans_black.val = 0x0;/* 완전 투명한 검은색으로 val에 대입함으로써 32비트 전체에 0 대입 */
	
	red.val = 0;/* 모든 비트플래그에 0대입 */
	red.rgba.r = 255;/* red채널의 비트플래그에만 255대입 */
	red.rgba.a = 255;/* alpha채널에 255대입해서 완전 불투명 */

	/* 노랑은 빨간색에 초록색을 섞으면 나온다. */
	yellow = red;
	yellow.rgba.g = 255;

	printf("size: %d\n", sizeof(color_t));
	printf("black:0x%08x(%3d, %3d, %3d, %3d)\n", trans_black.val, trans_black.rgba.r, trans_black.rgba.g, trans_black.rgba.b, trans_black.rgba.a);
	printf("red:0x%08x(%3d, %3d, %3d, %3d)\n", red.val, red.rgba.r, red.rgba.g, red.rgba.b, red.rgba.a);
	printf("yellow:0x%08x(%3d, %3d, %3d, %3d)\n", yellow.val, yellow.rgba.r, yellow.rgba.g, yellow.rgba.b, yellow.rgba.a);

	return 0;
}