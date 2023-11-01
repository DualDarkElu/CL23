#include <stdio.h>


// �����͸� ����Ͽ� 1���� �迭�� ���� �Է�
int input_student(int* student, int num) 
{
	int i;

	for (i = 0; i < num; i++) // �迭 �ε��� 0���� ����
	{
		printf("���� : ");
		scanf_s("%d", student++); // ���� �Է� �� �迭 ������ ����(���� ��� ������ ������ �̵�)
	}
	return 0;
}


// �����͸� ����Ͽ� 1���� �迭�� ������ ���
int output_student(int* student, int num) 
{
	// (���� 1) student �迭�� �л��� ������ ����ϴ� �Լ� output_student()�� �迭 ��� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	printf("\n�л� ����:\n");
	for (int i = 0; i < num; ++i) {
		printf("�л� %d: %d\n", i + 1, *(student + i));
	}
	return 0;
}


// �����͸� ����Ͽ� 1���� �迭�� ������ ����� ��ȯ
float average_student(int* student, int num)
{
	// (���� 2) student �迭�� �л��� ������ ����� ��ȯ�ϴ� �Լ� average_student()�� �迭 ��� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	int sum = 0;
	for (int i = 0; i < num; ++i) {
		sum += *(student + i);
	}
	return (float)sum / num;

}


// �����͸� ����Ͽ� 1���� �迭�� ������ �ִ밪�� ��ȯ
int max_student(int* student, int num)
{
	// (���� 3) student �迭�� �л��� ������ �ִ밪�� ��ȯ�ϴ� �Լ� max_student()�� �迭 ��� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	int max = 0;
	for (int i = 0; i < num; ++i) {
		if (*(student + i) > max) {
			max = *(student + i);
		}
	}
	return max;
}


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// �����͸� ����Ͽ� 1���� �迭�� ������ ������������ ����
int sort_des_student(int *student, int num) 
{
	// (���� 4) student �迭�� �л��� ������ ���� �������� �����ϴ� �Լ� sort_des_student()�� �迭 ��� �����͸� ����Ͽ� �ۼ��Ͻÿ�.
	for (int i = 0; i < num - 1; ++i) {
		for (int j = 0; j < num - i - 1; ++j) {
			if (*(student + j) < *(student + j + 1)) {
				swap(student + j, student + j + 1);
			}
		}
	}
	return 0;
}

