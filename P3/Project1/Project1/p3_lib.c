#include <stdio.h>

int print_short_info(short value, short* addr, int mem_size)
{
	printf("short ������ = %d, \t���� �ּ� = %p, \t�޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_int_info(int value, int* addr, int mem_size)
{
	printf("int ������ = %d, \t���� �ּ� = %p, \t�޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_long_info(long value, long* addr, int mem_size)
{
	printf("long ������ = %ld, \t���� �ּ� = %p, \t�޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_long_long_info(long long value, long long* addr, int mem_size)
{
	printf("long long ������ = %lld, \t���� �ּ� = %p, \t�޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_float_info(float value, float* addr, int mem_size)
{
	printf("float ������ = %f, \t���� �ּ� = %p, \t�޸� ũ�� = % d \n\n", value, addr, mem_size);
	return 0;
}

int print_double_info(double value, double* addr, int mem_size)
{
	printf("double ������ = %lf, \t���� �ּ� = %p, \t�޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_long_double_info(long double value, long  double* addr, int mem_size)
{
	printf("long double ������ = %f, \t���� �ּ� = %p, \t�޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_char_info(char value, char* addr, int mem_size)
{
	printf("���� ������ = %c, \t���� �ּ� = %p, \t�޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_wctype_t_info(wctype_t value, wctype_t* addr, int mem_size)
{
	printf("���� ������ = %c, \t���� �ּ� = %p, \t�޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}