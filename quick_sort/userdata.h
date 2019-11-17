#ifndef USERDATA_H
#define USERDATA_H

typedef enum {/* 사용자 정보의 성별 */
	SEX_MALE,
	SEX_FEMALE,
	SEX_UNKNOWN,
} sex_t;

typedef struct {/* 사용자 정보 구조체 */
	unsigned short id;
	unsigned char age;
	sex_t sex;
} userdata_t;

#endif /* USERDATA_H */