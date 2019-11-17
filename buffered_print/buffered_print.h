#ifndef BUFFERED_PRINT_H
#define BUFFERED_PRINT_H

void buffered_print(const char* src);/* 새로운 문자열을 출력하려고 할 때마다 출력하지 않고 캐릭터 배열(버퍼)에 쌓고 그 버퍼가 가득 차면 한번에 출력하는 메소드, 비워지면 다시 쌓고 출력 반복 */

#endif /* BUFFERED_PRINT_H */