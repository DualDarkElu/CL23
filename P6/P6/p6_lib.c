#include <stdio.h>


int print_char_info(char value, char* addr, int mem_size)
{
	printf("영문자 변수값 = %c, 변수 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
}

int print_wchar_info(wctype_t value, wctype_t* addr, int mem_size)
{
	wprintf(L"와이드문자 변수값= %c, 주소 = %p, 메모리 크기 = %d \n\n", value, addr, mem_size);
}