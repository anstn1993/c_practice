#ifndef USER_SORTER_H
#define USER_SORTER_H

/* qsort함수의 매개변수로 들어갈 비교 함수들. 배열에서 어떤 사용자가 먼저 등장할지 결정 */
int compare_age_id(const void* p0, const void* p1);/* 나이의 오름차순으로 정렬, 나이가 같으면 id의 오름차순으로 정렬 */
int compare_age_desc_sex(const void* p0, const void* p1);/* 나이의 내림차순으로 정렬, 나이가 같으면 성별에 따른 오름차순 정렬 */

#endif /* USER_SORTER_H */