#include <stdio.h>

int print_short_info(short value, short* addr, int mem_size)
{
	printf("short 변수값 = %d, 변수 주소 = %d, 메모리 크기 = %d \n\n", value, sizeof(addr), mem_size);
	return 0;
}

int print_int_info(int value, int* addr, int mem_size)
{
	printf("int 변수값 = %d, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_long_info(long value, long* addr, int mem_size)
{
	printf("long 변수값 = %ld, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_longlong_info(long long value, long long* addr, int mem_size)
{
	printf("long long 변수값 = %lld, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}


int print_uint_info(unsigned int value, unsigned int* addr, int mem_size)
{
	printf("unsigned int 변수값 = %u, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_ulong_info(unsigned long value, unsigned long* addr, int mem_size)
{
	printf("unsigned long 변수값 = %lu, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_ulonglong_info(unsigned long long value, unsigned long long* addr, int mem_size)
{
	printf("unsigned long long 변수값 = %llu, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
	return 0;
}