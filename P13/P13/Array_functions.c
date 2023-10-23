#include "Array.h"


// ��ü �л� ���� �Է�, �л� �� : num
int input_student(int student[], int num) { // student[] : �Ű������� �迭 �̸����� ����(�迭 ������ �ƴ�), 
                                                        // ȣ�������κ��� �迭 �̸�(���� �ּ�) �ʱ�ȭ
	int i;

	printf("\n�л� ��ü ������ �迭�� �Է�\n");
	for (i = 0; i < num; i++) // �迭 �ε��� 0���� ����
	{
		printf("���� : ");
		scanf_s("%d", &student[i]); // student[i] : student �迭�� ��� ����
	}
	return 0;
}

/*
int input_student(int student1[], int num) // ���� �Լ� ���ǿ� ����� �����ұ��?
{
	int i;

	for (i = 0; i < num; i++) // �迭 �ε��� 0���� ����
	{
		printf("���� : ");
		scanf_s("%d", &student1[i]); // student[i] : student �迭�� ��� ����
	}
	return 0;
}
*/

/*
int input_student(int *student, int num) //  ���� �Լ� ���ǿ� ����� �����ұ��? �迭 �̸� == �迭 ��� �������� ���� �ּ�
{
	int i;
	for (i = 0; i < num; i++) 
	{
		printf("���� : ");
		scanf_s("%d", &student[i]);
	}
	return 0;
}
*/

// �л� ��ü ���� ���, �л��� : num
int output_student(int student[], int num) // �迭�� �̸�(�����ּ�)�� �Ű������� �ʱ�ȭ
{
	int i;

	printf("\n�迭�� �л� ��ü ������ ���\n");
	for (i = 0; i < num; i++) {
		printf("����[%d] : %d\n", i, student[i]);
	}
	return 0;
}

// ��ü �л� ������ ��հ��� ����Ͽ� ��ȯ�ϴ� �Լ�
float average_student(int student[], int num)
{
	int i, sum = 0;

	for (i = 0; i < num; i++) {
		sum += student[i];
	}

	return(sum / num);
}

// ��ü �л� ������ �ִ밪�� ã�Ƽ� ��ȯ�ϴ� �Լ�
int max_student(int student[], int num)
{
	int i, max;

	max = student[0];
	for (i = 1; i < num; i++) {
		if (max < student[i])
			max = student[i];
	}

	return(max);
}

// ��ü �л� ������ �ּҰ��� ã�Ƽ� ��ȯ�ϴ� �Լ�
int min_student(int student[], int num) 
{
	// ���� 1 : student �迭�� ��ü �л� ������ �ּҰ��� ��ȯ�ϴ� �Լ��� �� ��ġ�� �ۼ��Ͻÿ�.
	int i, min;

	min = student[0];
	for (i = 1; i < num; i++) {
		if (min > student[i])
			min = student[i];
	}

	return(min);
}


// ���� 2 : �迭�� ���� �������� �����ϴ� �Ʒ� �Լ��� �úθ��� �����Ͻÿ�.
int sort_des_student(int student[], int num)
{
	int i, j, largest;

	for (i = 0; i < num; i++) // ���� ū ��� ������ ã�Ƽ� i��° ��� ������ ��ü
	{
		largest = i; // i��°�� ���� ū ������ �����ϰ� ����
		for (j = i + 1; j < num; j++)
			if (student[j] > student[largest])
				largest = j; // �� ū ��� ������ ������ ���� ū ��� ������ �ε����� largest�� ����

		// ���� ū ��� ����(student[largest]�� i��° ��� ����(student[i])�� ��ü
		int temp = student[i];
		student[i] = student[largest]; // ���� ū ��� ������ i��° ������ ����
		student[largest] = temp; // ���� i��° ������ ���� ū ��� ���� ��ġ�� ����
	}
	return 0;
}


int sort_asc_student(int student[], int num) 
{
	// ���� 3 : ���� ���� ���� �Լ��� �����Ͽ� �迭�� ���� �������� �����ϴ� �Լ��� �� ��ġ�� �ۼ��Ͻÿ�. 
	int i, j, smallest;

	for (i = 0; i < num; i++) // ���� ū ��� ������ ã�Ƽ� i��° ��� ������ ��ü
	{
		smallest = i; // i��°�� ���� ū ������ �����ϰ� ����
		for (j = i + 1; j < num; j++)
			if (student[j] < student[smallest])
				smallest = j; // �� ū ��� ������ ������ ���� ū ��� ������ �ε����� largest�� ����

		// ���� ū ��� ����(student[largest]�� i��° ��� ����(student[i])�� ��ü 
		int temp = student[i];
		student[i] = student[smallest]; // ���� ū ��� ������ i��° ������ ����
		student[smallest] = temp; // ���� i��° ������ ���� ū ��� ���� ��ġ�� ����
	}
	return 0;
}

// ���� 4 : �Ʒ��� backup_student() �Լ��� �����ϰ� �����Ͽ� �ۼ��Ͻÿ�.
int backup_student(int student1[], int backup1[], int num) 
{
	int i;

	for (i = 0; i < num; i++)
	{
		backup1[i] = student1[i];
	}
	return 0;
}