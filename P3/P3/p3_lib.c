#include <stdio.h>

int print_short_info(short value, short* addr, int mem_size)
{
	printf("short 변수값 = %d, \t변수 주소 = %p, \t메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_int_info(int value, int* addr, int mem_size)
{
	printf("int 변수값 = %d, \t변수 주소 = %p, \t메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_long_info(long value, long* addr, int mem_size)
{
	printf("long 변수값 = %ld, \t변수 주소 = %p, \t메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_long_long_info(long long value, long long* addr, int mem_size)
{
	printf("long long 변수값 = %lld, \t변수 주소 = %p, \t메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_float_info(float value, float* addr, int mem_size)
{
	printf("float 변수값 = %f, \t변수 주소 = %p, \t메모리 크기 = % d \n\n", value, addr, mem_size);
	return 0;
}

int print_double_info(double value, double* addr, int mem_size)
{
	printf("double 변수값 = %lf, \t변수 주소 = %p, \t메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_long_double_info(long double value, long  double* addr, int mem_size)
{
	printf("long double 변수값 = %f, \t변수 주소 = %p, \t메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_char_info(char value, char* addr, int mem_size)
{
	printf("문자 변수값 = %c, \t변수 주소 = %p, \t메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_wctype_t_info(wctype_t value, wctype_t* addr, int mem_size)
{
	printf("문자 변수값 = %c, \t변수 주소 = %p, \t메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}