#include "p7_io.h"

int main(int argc, char* argv[])
{
	int age = 20; int *agep;
	unsigned int uint_max = UINT_MAX; 
	unsigned long long ullong_max = ULLONG_MAX;

	// ���� ���� ��� �Լ� printf() ���ؿ� Ȱ��

	// int ������ �پ��� ���� ���� ���
	printf("int ���� ������ ��� : %d, \t\t16���� ��� : %x, \t\t���� ��� : %c\n", age, age, age, age);
	printf("int ���� �Ǽ�(f) : %f\n", age);

	// int ������ �ּ� ���
	printf("int ���� �ּ�(x) : %x, \t\t�ּ�(08x) : %08x, \t\t�ּ�(p) : %p\n", &age, &age, &age);

	// ������ ũ�� ���
	printf("int ���� ũ��d : %d, \t\t�ּ� ũ��d : %d\n", sizeof(age), sizeof(&age));


	printf("\n\n");
	age = age + pow(2, 31); // pow(2, 31)�� 2^32 ������ ��� �Լ�
	printf("int ���� �����÷ο찪(50 + 2^31) ���: %d\n", age);
	printf("unsigned ���� �ִ밪 ���(u) : %u, ���(llu) : %llu\n", uint_max, ullong_max);
	printf("unsigned int ���� �ִ밪 ���(d) : %d\n", uint_max);
	printf("unsigned int ���� �����÷ο� ���(d) : %d\n", uint_max + 100);
	printf("unsigned int ���� �����÷ο� ���(u) : %u\n", uint_max + 100);

	printf("\n\n");
	char ch = 'A';
	printf("���� A ���(c) : %c, \t\t���(d) : %d\n", ch, ch);

	printf("\n\n");
	float height = 175.7; float *heightp;
	double height1 = 175.7;
	double dmax = DBL_MAX;
	printf("float ���� ���(.6f) : %.6f\n", height);
	printf("float ���� ���(.10f) : %.10f\n", height);
	printf("float ���� ���(.15f) : %.15f\n", height);

	printf("\n\n");
	printf("double ���� ���(.10f) : %.10f\n", height1);
	printf("double ���� ���(.15f) : %.15f\n", height1);

	printf("\n\n");
	printf("double ���� �ִ밪 ���(.15f) : %.15f\n", dmax);
	printf("double ���� �ִ밪 ���(.15e) : %.15e\n", dmax);

	printf("\n\n");
	printf("float ���� ���(d) : %d\n", height);
	printf("double ���� ���(ld) : %ld\n", height1);

	// ���� ���� ���� �Է� �Լ� scanf_s() ���ؿ� Ȱ��

	printf("\n\n");
	age = 0;
	printf("age(d) : ");
	scanf_s("%d", &age); // 10���� �������� �Է�, ���� �ּ� ���� ����
	
	printf("age(d) = %d\n", age); // 10���� �������� ���

	printf("\n\n");
	printf("age(x) : "); 
	scanf_s("%x", &age); // 16���� �������� �Է�
	printf("age(x) = %d\n", age); // ������ �������� ���

	printf("\n\n");
	printf("age(c) : ");
	scanf_s(" %c", &age); // ���� �������� �Է�(���� ���� \n ����)
	printf("age(c) = %d\n", age); // ������ ���
	rewind(stdin); // �Է� ���� ���� �Լ�

	printf("\n\n");
	// age = 0;
	// printf("age(d) : ");
	// scanf_s("%d", age); // ���� �߻�(��� �Ұ� �ּ�)
	// printf("age(d) = %d\n", age); 

	// agep = &age;
	// printf("age(d) : ");
	// scanf_s("%d", agep); // ���� �Է�(���� �ּ� ���)
	// printf("age(d) = %d\n", *agep); // * : �ּ� ���� ���� ������ 

	printf("\n\n");
	age = 0; height = 0.0;
	agep = &age; heightp = &height;
	// ȣ������ ���ڿ� �Լ����� �Ű������� ���� ���� --> �Լ� ������ Ȯ��, ȣ���� ���� ������ �Լ����� ������ ��쿡�� �ݵ�� ������ �ּҸ� ȣ�� ���ڷ� ���
	my_scanf(agep, heightp); //my_scanf(&age, &height);  
	printf("age = %d, height = %.1f\n", age, height);	
	printf("age �ּ� = %d\n", &age);
	
	printf("\n\n");
	age = 0; height = 0.0;
	agep = &age; heightp = &height;
	printf("\n\n"); 
    my_scanf2(agep, heightp);
	printf("age = %d, height = %.1f\n", age, height);

	return 0;
}