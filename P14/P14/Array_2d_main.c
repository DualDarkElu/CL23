#include "Array_2d.h"

float min[4]; 

int main(void)
{
	float student[5][4] = { 0 }; // �� : �л� ��, �� : �л��� �߰�, �⸻, ����, ���
	float student1[5][4] = { 0 };
	float average[4] = { 0 }; 
	float max[4] = { 0 };
	float min[4] = { 0 };
	int i, j = 0;

	// �迭 �ּ� Ȯ��
	check_2D_array_address(student);

	printf("�л��� �Է� : ");
	scanf_s("%d", &i);

	// �л� ���� �Է�
	input_student(student, i); // �л����� �߰�, �⸻, ����, ��� ���� �Է��� �Է��Ͽ� 2���� �迭 student[5][4]�� ����

	// �л� ���� ���
	output_student(student, i);

	// �л����� �߰�, �⸻, ����, ��� ������  �ִ밪�� ã�Ƽ� 1���� �迭 max[4]�� ������� ����
	max_exams(student, max, i);
	printf("\n�߰�, �⸻, ����, ��� �ִ밪 : %.1f,  %.1f,  %.1f, %.1f\n", max[0], max[1], max[2], max[3]);

	// ���� 1 : �л����� �߰�, �⸻, ����, ��� ������  �ּҰ��� ã�Ƽ� ���� 1���� �迭 min[4]�� ������� �����ϴ� 
	// �Լ� min_exams()�� Array_2d_functions.c �ҽ� ���Ͽ� �ۼ��Ͻÿ�.
	min_exams(student, min, i);
	printf("\n�߰�, �⸻, ����, ��� �ּҰ� : %.1f,  %.1f,  %.1f, %.2f\n", min[0], min[1], min[2], min[3]);

	// ����2 : 2���� �迭 student[5][4]�� ����� �л����� �߰����� ���, �⸻ ���, ���� ���, ��ռ����� ����� ���Ͽ� 
	// average[4]�� ������� �����ϴ� �Լ� average_exams()�� Array_2d_functions.c �ҽ� ���Ͽ� �ۼ��Ͻÿ�. 
	average_exams(student, average, i);
	printf("\n�߰�, �⸻, ����, ����� ��հ� : %.1f,  %.1f,  %.1f, %.1f\n", average[0], average[1], average[2], average[3]);

	printf("\n�л� ��� ���� �������� ���� : \n");
	// ����3: �л��� ��� ������ �������� 2���� �迭 student[5][4]�� ���� �������� �������Ͽ� �����ϴ� �Լ�
	// sort_des_student()�� Array_2d_functions.c �ҽ� ���Ͽ��� �����ϰ� �����Ͻÿ�.
	sort_des_student(student, i);
	// ������������ ������ 2���� �迭 student[5][4]�� ���
	output_student(student, i);

	printf("\n�л� ��� ���� �������� ���� : \n");
	// ����4 : �л��� ��� ������ �������� 2���� �迭 student[5][4]�� ���� �������� �������Ͽ� �����ϴ� �Լ�
	// sort_asc_student()�� Array_2d_functions.c �ҽ� ���Ͽ� �ۼ��Ͻÿ�. 
	sort_asc_student(student, i); 
	output_student(student, i);

	return 0;
}
