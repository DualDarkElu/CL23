#include <stdio.h>

// %.8f : �Ҽ��� 9�ڸ� ���� �ݿø��Ͽ� 8�ڸ����� ǥ��
int print_float_info(float value, float* addr, int mem_size)
{
	printf("float ������ = %.6f, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_double_info(double value, double* addr, int mem_size)
{
	printf("double ������ = %.20lE, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_ldouble_info(long double value, long double* addr, int mem_size)
{
	printf("long double ������ = %.6llf, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}
