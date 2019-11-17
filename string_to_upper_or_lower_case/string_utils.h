#ifndef STRING_UTILS_H
#define STRING_UTILS_H

/* 밑의 세 함수의 매개변수가 char가 아니라 int형인 이유는 그냥 c표준이 그렇기 때문이다.  */
int is_alpha(int c);/* 문자가 실제 알파벳이냐를 판단하는 것 */

int to_upper(int c);/* 두 함수의 반환형이 인트인 이유도 c표준이 그렇기 때문. 그리고 어차피 char형도 숫자 */
int to_lower(int c);
/* 위의 세 함수는 이미 c표준 라이브러리에 존재하지만 스스로 작성할 수 있어야 한다. 아스키코드를 아니까 */

void string_toupper(char* str);/* 매개변수로 들어온 포인터를 수정하는 것이기 때문에 반환 따로 안 해줘도 됨. 이렇게 원본을 직접 수정하는 것을 in place라고 한다. 즉 in place하게 바꾼다고 하면 원본을 바꾸라는 것 */
void string_tolower(char* str);

#endif /* STRING_UTILS_H */