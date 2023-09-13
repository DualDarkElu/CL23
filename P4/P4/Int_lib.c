#include <stdio.h>

int print_short_info(short value, short* addr, int mem_size)
{
	printf("short ������ = %d, ���� �ּ� = %d, �޸� ũ�� = %d \n\n", value, sizeof(addr), mem_size);
	return 0;
}

int print_int_info(int value, int* addr, int mem_size)
{
	printf("int ������ = %d, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_long_info(long value, long* addr, int mem_size)
{
	printf("long ������ = %ld, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_longlong_info(long long value, long long* addr, int mem_size)
{
	printf("long long ������ = %lld, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}


int print_uint_info(unsigned int value, unsigned int* addr, int mem_size)
{
	printf("unsigned int ������ = %u, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_ulong_info(unsigned long value, unsigned long* addr, int mem_size)
{
	printf("unsigned long ������ = %lu, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}

int print_ulonglong_info(unsigned long long value, unsigned long long* addr, int mem_size)
{
	printf("unsigned long long ������ = %llu, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
	return 0;
}