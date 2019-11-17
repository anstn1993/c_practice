void copy_string(char* dest, const char* src)/* 첫번째 파라미터: 복사될 문자열, 두번째 파라미터: 복사할 원본 문자열 */
{
	while (*src != '\0') {/* 원본의 문자가 널문자가 아닐 때까지 반복 */
		*dest++ = *src++;
	}

	*dest = '\0';/*마지막에 널문자 추가*/
}