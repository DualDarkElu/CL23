#include "Array_2d.h"

extern float min[4];

void check_2D_array_address(float student[][4]) 
// void check_2D_array_address(float student[][])�� ���� �Ű������� �����ϸ� � ������ �߻��ұ�?
{
	float* p1, * p2, * p3, * p4, * p5, *p6, *p7;

	p1 = student;
	p2 = student[0];
	p3 = &student[0][0];
	p4 = student[1];
	p5 = &student[1][0];
	p6 = student[2];
	p7 = &student[1][0];
	printf("\nstudent ; %p, student[0] : %p, &student[0][0] : %p\n", p1, p2, p3); // 1) ��°��� �� ������ ������ ���ô�.
	printf("\nstudent[1] ; %p, &student[1][0] : %p\n", p4, p5); // 2) ��°��� �� ������ ������ ���ô�.
	printf("\nstudent[2] ; %p, &student[2][0] : %p\n", p6, p7); // 3) ��°��� �� ������ ������ ���ô�.
	// 1), 2), 3) ��°��� ���̰� ������ Ȯ���� ���� �� �̷� ���̰� ������� ������ ���ô�.
}
void input_student(float student[][4], int num) // �迭�� �̸�(�����ּ�)�� �Ű������� �ʱ�ȭ, student�� �ּ� ���� ����
{
	int i;

	for (i = 0; i < num; i++) 
	{
		printf("�л� %d �߰����� : ", i);
		scanf_s("%f", &student[i][0]);
		printf("�л� %d �⸻���� : ", i);
		scanf_s("%f", &student[i][1]);
		printf("�л� %d ����� : ", i);
		scanf_s("%f", &student[i][2]);
		student[i][3] = (student[i][0] + student[i][1] + student[i][2]) / 3; // �� �л��� ���� ��� ����
	}
}

void output_student(float student[][4], int num) 
{
	int i;

	for (i = 0; i < num; i++) 
	{
		printf("�л� ��ȣ : %d, �߰� : %.1f, �⸻ : %.1f, ���� : %.1f, ��� : %.1f\n", i, student[i][0], student[i][1], student[i][2], student[i][3]);
	}

}

void max_exams(float student[][4], float max[], int num)
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		max[i] = student[0][i];
		for (j = 1; j < num; j++)
		{
			if (max[i] < student[j][i])
				max[i] = student[j][i];
		}
	}

}

void min_exams(float student[][4], float min[], int num)
{
	// ���� 1 : ���� max_exams() �Լ��� �����Ͽ� �л����� �߰�, �⸻, ����, ��� ������  �ּҰ��� ã�Ƽ� 
	// ���� 1���� �迭 min[4]�� ������� �����ϴ� �Լ� min_exams()�� �� ��ġ���� �ۼ��Ͻÿ�.
	int i, j;

	for (i = 0; i < 4; i++)
	{
		min[i] = student[0][i];
		for (j = 1; j < num; j++)
		{
			if (min[i] > student[j][i])
				min[i] = student[j][i];
		}
	}
}

void average_exams(float student[][4], float average[], int num)
{
	// ����2 : 2���� �迭 student[5][4]�� ����� �л����� �߰����� ���, �⸻ ���, ���� ���, ��ռ����� ����� ���Ͽ� 
    // average[4]�� ������� �����ϴ� �Լ� average_exams()�� �� ��ġ�� �ۼ��Ͻÿ�. 
	float sum_midterm = 0, sum_final = 0, sum_quiz = 0;
	for (int i = 0; i < num; i++) {
		sum_midterm += student[i][0];
		sum_final += student[i][1];
		sum_quiz += (student[i][2] + student[i][3]) / 2;
	}
	average[0] = sum_midterm / num;
	average[1] = sum_final / num;
	average[2] = sum_quiz / num;
	average[3] = (average[0] + average[1] + average[2]) / 3;
}

void sort_des_student(float student[][4], int num) 
{
	int i, j, largest;

	float temp[4];

	for (i = 0; i < num; i++) 
	{
		largest = i;
		for (j = i + 1; j < num; j++)
			if (student[j][3] > student[largest][3])
				largest = j;

		if (largest != i)
		{
			for (int k = 0; k < 4; k++)
			{
				temp[k] = student[i][k];
				student[i][k] = student[largest][k];
				student[largest][k] = temp[k];
			}
		}
		// ����3: �л��� ��� ������ �������� 2���� �迭 student[5][4]�� ���� �������� �������Ͽ� �����ϵ���
		// �� ��ġ�� ������ ��ɹ����� ä��ÿ�.
	
	}
}

void sort_asc_student(float student[][4], int num)
{
	// ����4 : �л��� ��� ������ �������� 2���� �迭 student[5][4]�� ���� �������� �������Ͽ� �����ϴ� �Լ�
    // sort_asc_student()�� �� ��ġ�� �ۼ��Ͻÿ�. 
	int i, j, smallest;

	float temp[4];

	for (i = 0; i < num; i++)
	{
		smallest = i;
		for (j = i + 1; j < num; j++)
			if (student[j][3] < student[smallest][3])
				smallest= j;

		if (smallest != i)
		{
			for (int k = 0; k < 4; k++)
			{
				temp[k] = student[i][k];
				student[i][k] = student[smallest][k];
				student[smallest][k] = temp[k];
			}
		}
		// ����3: �л��� ��� ������ �������� 2���� �迭 student[5][4]�� ���� �������� �������Ͽ� �����ϵ���
		// �� ��ġ�� ������ ��ɹ����� ä��ÿ�.

	}
}
