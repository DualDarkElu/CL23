#include <stdio.h>

int my_scanf(int* agep, float* heightp)
{
	//printf("age(d) :"); 
	//scanf_s("%d", agep); // ���� �ּ� ����
	printf("height(f) :");
	scanf_s("%f", heightp); // ���� �ּ� ����
	printf("age(d) :");
	scanf_s("%d", &agep); // ���� �ּ� ����
	return 0;
}

int my_scanf2(int* agep, float* heightp)
{
	printf("age : ");
	scanf_s("%d", &agep); // ���� ����
	printf("height : ");
	scanf_s("%f", &heightp); // ���� ����
	return 0;
}