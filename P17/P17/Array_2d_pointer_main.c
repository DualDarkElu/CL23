#include "Array_2d_pointer.h"

int main(void)
{
	float student[10][3] = { {1,2,3}, {4,5,6}, {7,8,9} }; // �л����� �߰�����, �⸻����, ���� ����, ��� ���� 2���� �迭

	// ���� 3���� ��¹��� �ǹ̸� ��Ȯ�ϰ� ����
	printf("2���� �迭 student : %p, ù��° 1���� �迭 student[0] : %p, ù��° ��� ���� &student[0][0] : %p\n\n", student, student[0], &student[0][0]);

	// 1���� �迭�� �̸��� ���ӵ� ��� ������ ���� �ּ�, 2���� �迭�� �̸��� ���ӵ� 1���� �迭�� ���� �ּ�
	
	// 1���� �迭 �̸� ���� ���� : ��� ���� ũ�� ����, 2���� �迭 �̸� ���� ���� : 1���� ��� �迭 ũ�� ����
	
	// 1���� �迭 �ּ��� ���� ���� ����(*) : �ش� ��� ����, 2���� �迭 �ּ��� ���� ���� ����(*) : �ش� 1���� ��� �迭
	
	printf("student 2���� �迭�� �ι�° 1���� �迭 *(student+1) : %p, student[1]: %p\n\n", *(student + 1), student[1]);
	// student+1 : 2���� �迭 student�� �ι�°(1��°) ����� �ּ�, *(student+1) : 2���� �迭 student�� �ι�° ����� ����(�ι�° 1���� �迭)

	printf("student 2���� �迭�� student[0][0] : %.2f,  **student : %.2f\n\n", student[0][0], **student);
	printf("student 2���� �迭�� student[1][1] : %.2f,  *(*(student+1) + 1) : %.2f\n\n", student[1][1], *(*(student + 1)+1));
	// 2���� �迭�� �̸��� ���� ������ ���
	

	// *(student+1) + 1 : �ι�° 1���� �迭�� �ι�°(1��°) ����� �ּ�, *(*(student+1) + 1) : �ι�° 1���� �迭�� �ι�° ��� ����
	// (���� 1) :*(*(student+2) + 2)�� ���� ���ΰ�? 
	//9.00
	printf("*(*(student+2) + 2) : %.2f\n\n", *(*(student + 2) + 2));

	int i; // �л� ��

	printf("�л��� �Է� : ");
	scanf_s("%d", &i);

	input_student1(student, i); 

	// input_student1() �Լ����� �л� 1 : 50, 70, 60, �л� 2 : 65, 55, 75, �л� 3 : 90, 80, 100�� �Է��Ͽ���.
	// (���� 2): student[1][1], student[1][2]�� ���� ���� ���ΰ�? student[2][1], student[2][2]�� ���� ���� ���ΰ�?
	/*student[1][1] : 100.00, student[1][2] : 6.00

	student[2][1] : 8.00, student[2][2] : 9.00*/
	printf("student[1][1] : %.2f, student[1][2] : %.2f\n\n", *(*(student + 1) + 1), *(*(student + 1) + 2));
	printf("student[2][1] : %.2f, student[2][2] : %.2f\n\n", *(*(student + 2) + 1), *(*(student + 2) + 2));

	printf("\n\n");
	float student2[10][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	
	input_student2(student2, i); 

	// input_student2() �Լ����� �л� 1 : 50, 70, 60, �л� 2 : 65, 55, 75, �л� 3 : 90, 80, 100�� �Է��Ͽ���.
	// (���� 3) : student2[1][1], student2[1][2]�� ���� ���� ���ΰ�? student2[2][1], student2[2][2]�� ���� ���� ���ΰ�?
	/*student2[1][1] : 100.00, student2[1][2] : 6.00

	student2[2][1] : 8.00, student2[2][2] : 9.00*/
	printf("student2[1][1] : %.2f, student2[1][2] : %.2f\n\n", *(*(student2 + 1) + 1), *(*(student2 + 1) + 2));
	printf("student2[2][1] : %.2f, student2[2][2] : %.2f\n\n", *(*(student2 + 2) + 1), *(*(student2 + 2) + 2));
	
	printf("\n\n");
	float student3[10][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

	input_student3(student3, i); 
	output_student(student3, i);

	// input_student3() �Լ����� �л� 1 : 50, 70, 60, �л� 2 : 65, 55, 75, �л� 3 : 90, 80, 100�� �Է��Ͽ���.
    // (���� 4) : student3[1][1], student3[1][2]�� ���� ���� ���ΰ�? student3[2][1], student3[2][2]�� ���� ���� ���ΰ�?
	/*student3[1][1] : 55.00, student3[1][2] : 75.00

	student3[2][1] : 80.00, student3[2][2] : 100.00*/
	printf("student3[1][1] : %.2f, student3[1][2] : %.2f\n\n", *(*(student3 + 1) + 1), *(*(student3 + 1) + 2));
	printf("student3[2][1] : %.2f, student3[2][2] : %.2f\n\n", *(*(student3 + 2) + 1), *(*(student3 + 2) + 2));


	float average[3] = { 50,60,70 }; // �߰�, �⸻, ���� ������ ��հ� 1���� �迭
	float max[3] = { 500,600,700 }; // �߰�, �⸻, ���� ������ �ִ밪 1���� �迭
	float min[3] = { 100,200,300 }; // �߰�, �⸻, ���� ������ �ּҰ� 1���� �迭

	float* stat[3]; // �� ��� ������ 1���� �迭 average[3], max[3], min[3]�� �ּҸ� �����ϴ� ������ �迭
	float** pp; // ������ ������ �ּ�(������)�� ���� ������

	stat[0] = average; stat[1] = max; stat[2] = min;

	// ���� ������ ����
	pp = stat;
	printf("**pp : %.2f\n", **pp);
	printf("*(*pp + 1) : %.2f\n", *(*pp + 1));

	// (���� 5) *(*(++pp) + 1)�� ���� ���ΰ�?
	//*(*(++pp) + 1) : 600.00
	printf("*(*(++pp) + 1) : %.2f\n", *(*(++pp) + 1));
	
	pp = stat;
	// (���� 6) *pp, **pp, *(*pp+1), *(*pp+2)�� ������ ���� �����ΰ�?
	//
	
	// (���� 1) �л����� �߰�, �⸻, ���� ������ ��� ������ average[3]�� �� ��� ������ ������� �����ϴ� 
	// average_student() �Լ��� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	average_student(student3, *pp, i);
	printf("�߰� �⸻ ���� ��հ� : %.1f,  %.1f,  %.1f\n", **pp, *(*pp + 1), *(*pp + 2));

	pp++;
	// (���� 6) *pp, **pp, *(*pp+1), *(*pp+2)�� ������ ���� �����ΰ�?

	// (���� 2) �л����� �߰�, �⸻, ���� ������ �ִ밪�� max[3]�� �� ��� ������ ������� �����ϴ� 
	// max_student() �Լ��� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	max_student(student3, *pp, i);
	printf("�߰� �⸻ ���� �ִ밪 : %.1f,  %.1f,  %.1f\n", **pp, *(*pp + 1), *(*pp + 2));

	pp++;
	// (���� 7) *pp, **pp, *(*pp+1), *(*pp+2)�� ������ ���� �����ΰ�?
	min_student(student3, *pp, i);
	printf("�߰� �⸻ ���� �ּҰ� : %.1f,  %.1f,  %.1f\n", **pp, *(*pp + 1), *(*pp + 2));


	// �߰�, �⸻, ���� ������ ���� ���, �ִ밪, �ּҰ� ���
	printf("���� ��� ���� ��� :\n\n");
	statistics_output(stat);

	printf("�⸻ ���� ���� �������� ���� : \n");

	// (���� 3) 2���� �迭 student�� �⸻ ���� �������� ���� �������� �����ϴ� �Լ� sort_des_student()��
	// �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	sort_des_student(student3, i);
	output_student(student3, i);


	return 0;
}
