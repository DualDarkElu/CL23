#include "Array_pointer.h"

int main(void)
{
	int student[MAX_NUM] = { 0 }; 
	int i = 0;
	int* pt = NULL; // �������� ������ �� �ִ� �ּ� ����

	printf("�л��� �Է� : ");
	scanf_s("%d", &i);

	input_student(student, i); // �л����� ������ �迭�� �Է�

	// (���� 1) student �迭�� �л��� ������ ����ϴ� �Լ� output_student()�� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	output_student(student, i);  

	// (���� 2) student �迭�� �л��� ������ ����� ��ȯ�ϴ� �Լ� average_student()�� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	printf("\n��հ� : %f\n\n", average_student(student, i));

	// (���� 3) student �迭�� �л��� ������ �ִ밪�� ��ȯ�ϴ� �Լ� max_student()�� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	printf("\n�ִ밪 : %d\n\n", max_student(student, i));


	printf("\n�������� ���� : \n");
	// (���� 4) student �迭�� �л��� ������ ���� �������� �����ϴ� �Լ� sort_des_student()�� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	sort_des_student(student, i);
	output_student(student, i);

	return 0;
}