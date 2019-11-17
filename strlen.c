int strlen(const char* str)
{
	size_t i;
	for (i = 0; str[i] != '\0'; ++i) {
	}
	
	return i;
}

int strlen_advanced1(const char* str)
{
	const char* p = str;

	while (*p++ != '\0'){
	}

	return p - str - 1;
}

int strlen_advanced2(const char* str) {
	size_t count = 0;
	const char* p = str;

	while (*p++ != '\0') {
		++count;
	}

	return count;
}