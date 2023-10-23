#include "Array.h"

int main(void)
{

	int student[10] = { 0 }; // int ���� 10���� ����, student[0],..., student[9], student: �迭�� �̸�, ���� ���� 10���� ���� �ּ�
	int backup[10] = { 0 }; // ù 3�� ���� 1�� �ʱ�ȭ, �������� 0���� �ʱ�ȭ
	// student = { 10, 20, 20 };  ���� : student�� ������ �ƴ�, ���ӵ� 10�� ���� �迭�� �̸�(�迭 ��� �������� ���� �ּ�)

	printf("student : %p, &student[0] : %p\n", student, &student[0]); // �� ��°��� �����?
	printf("student : %p, &student : %p\n", student, &student); // �� ��°��� �����?
	
	printf("�迭ũ�� : %d\n", sizeof(student)); // student �迭�� �����ϴ� ��ü �������� ũ��
	printf("�迭�ּ� ũ�� : %d\n", sizeof(&student)); // student �迭�� �����ϴ� ��ü �������� ���� �ּ��� ũ��

	int i = 0;
	printf("\n�л��� �Է� : ");
	scanf_s("%d", &i);

	// ��ü �л� ���� �Է� �Լ� ȣ��
	input_student(student, i); // �迭�� �̸��� ���ڷ� ����, �迭 �̸��� ��� �������� ���� �ּ�

	// ��ü �л� ���� ��� ��ȯ �Լ� ȣ��
	printf("\n��հ� : %f\n", average_student(student, i));

	// ��ü �л� ���� �ִ밪 ��ȯ �Լ� ȣ��
	printf("�ִ밪 : %d\n", max_student(student, i));

	// ��ü �л� ���� �ּҰ� ��ȯ �Լ� ȣ��
	printf("�ּҰ� : %d\n", min_student(student, i)); // ���� 1 : student �迭�� ��ü �л� ������ �ּҰ��� ��ȯ�ϴ� �Լ� min_student()�� 
	                                                                 // Arry_functions.c �ҽ� ���Ͽ��� �ۼ��Ͻÿ�.

	printf("\n�������� ���� : \n");
	
	sort_des_student(student, i); // ����2 : ��ü �л� ������ ������������ �����Ͽ� �迭�� �������ϴ� �Լ� ȣ�� �Լ� sort_des_student()�� 
	                                     // Arry_functions.c �ҽ� ���Ͽ��� �ùٸ��� �����Ͻÿ�.
	// ���� �������� ���ĵ� �迭�� �л� ���� ���
	output_student(student, i);
	
	
	printf("\n�������� ���� : \n"); 
	sort_asc_student(student, i); // ���� 3 : ���� ���� ���� �Լ��� �����Ͽ� �迭�� ���� �������� �����ϴ� �Լ� sort_asc_student()�� 
	                                     // Arry_functions.c �ҽ� ���Ͽ��� �ۼ��Ͻÿ�.
	// ���� �������� ���ĵ� �迭�� �л� ���� ���
	output_student(student, i);
	
	// student �迭�� backup �迭�� �����ϴ� �Լ� ȣ��
	backup_student(student, backup, i); // ���� 4 : student �迭�� backup �迭�� �����ϴ� �Լ� backup_student()�� 
										            // Arry_functions.c �ҽ� ���Ͽ� �����ϰ� �����Ͽ� �ۼ��Ͻÿ�.
	printf("\nbackup �迭 ��� \n");
	output_student(backup, i);

	return 0;
	
}