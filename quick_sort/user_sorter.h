#ifndef USER_SORTER_H
#define USER_SORTER_H

/* qsort�Լ��� �Ű������� �� �� �Լ���. �迭���� � ����ڰ� ���� �������� ���� */
int compare_age_id(const void* p0, const void* p1);/* ������ ������������ ����, ���̰� ������ id�� ������������ ���� */
int compare_age_desc_sex(const void* p0, const void* p1);/* ������ ������������ ����, ���̰� ������ ������ ���� �������� ���� */

#endif /* USER_SORTER_H */