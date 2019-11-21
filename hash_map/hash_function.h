#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

size_t hash_int(int value);/* �� ��ü�� �̹� ������ ���� ���̱� ������ size_t�� ĳ�����ؼ� ��ȯ */
size_t hash_float(float value);/* float�� ĳ�����ϸ� �Ҽ��� ���ϰ� ������ϱ� ���� ������ size_t�� �а� �Ѵ�.  */
size_t hash_data(const void* data, size_t length);/* ������ ������ Ÿ�Կ��� ����� �� �ִ� �ؽ� �Լ� */


#endif /* HASH_FUNCTION_H */