#include <stdio.h>

int my_printf(char* data, char* data1);
int my_printf2(char* data, char* data1);

int main(int argc, char* argv[])
{
	my_printf("Hello World!!", argv[1]);
	my_printf2("Hello World!!", argv[1]);

	return 0;
}

int my_printf(char* data, char* data1)
{
	printf("\n\n%s from %s\n\n", data, data1);
	return 0;
}

int my_printf2(char* data, char* data1)
{
	printf("****%s**** from %s\n\n", data, data1);
	return 0;
}