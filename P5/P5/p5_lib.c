#include <stdio.h>

// %.8f : 소수점 9자리 이하 반올림하여 8자리까지 표시
int print_float_info(float value, float* addr, int mem_size)
{
	printf("float 변수값 = %.6f, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_double_info(double value, double* addr, int mem_size)
{
	printf("double 변수값 = %.20lE, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_ldouble_info(long double value, long double* addr, int mem_size)
{
	printf("long double 변수값 = %.6llf, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}
