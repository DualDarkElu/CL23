#include <stdio.h>

int my_scanf(int* agep, float* heightp)
{
	//printf("age(d) :"); 
	//scanf_s("%d", agep); // 변수 주소 전달
	printf("height(f) :");
	scanf_s("%f", heightp); // 변수 주소 전달
	printf("age(d) :");
	scanf_s("%d", &agep); // 변수 주소 전달
	return 0;
}

int my_scanf2(int* agep, float* heightp)
{
	printf("age : ");
	scanf_s("%d", &agep); // 변수 전달
	printf("height : ");
	scanf_s("%f", &heightp); // 변수 전달
	return 0;
}