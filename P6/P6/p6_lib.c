#include <stdio.h>


int print_char_info(char value, char* addr, int mem_size)
{
	printf("������ ������ = %c, ���� �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
}

int print_wchar_info(wctype_t value, wctype_t* addr, int mem_size)
{
	wprintf(L"���̵幮�� ������= %c, �ּ� = %p, �޸� ũ�� = %d \n\n", value, addr, mem_size);
}