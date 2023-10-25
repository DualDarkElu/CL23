#include "Array_2d.h"

extern float min[4];

void check_2D_array_address(float student[][4]) 
// void check_2D_array_address(float student[][])와 같이 매개변수를 정의하면 어떤 문제가 발생할까?
{
	float* p1, * p2, * p3, * p4, * p5, *p6, *p7;

	p1 = student;
	p2 = student[0];
	p3 = &student[0][0];
	p4 = student[1];
	p5 = &student[1][0];
	p6 = student[2];
	p7 = &student[1][0];
	printf("\nstudent ; %p, student[0] : %p, &student[0][0] : %p\n", p1, p2, p3); // 1) 출력값이 왜 같은지 설명해 봅시다.
	printf("\nstudent[1] ; %p, &student[1][0] : %p\n", p4, p5); // 2) 출력값이 왜 같은지 설명해 봅시다.
	printf("\nstudent[2] ; %p, &student[2][0] : %p\n", p6, p7); // 3) 출력값이 왜 같은지 설명해 봅시다.
	// 1), 2), 3) 출력값의 차이가 얼마인지 확인해 보고 왜 이런 차이가 생기는지 설명해 봅시다.
}
void input_student(float student[][4], int num) // 배열의 이름(시작주소)을 매개변수로 초기화, student는 주소 지역 변수
{
	int i;

	for (i = 0; i < num; i++) 
	{
		printf("학생 %d 중간성적 : ", i);
		scanf_s("%f", &student[i][0]);
		printf("학생 %d 기말성적 : ", i);
		scanf_s("%f", &student[i][1]);
		printf("학생 %d 퀴즈성적 : ", i);
		scanf_s("%f", &student[i][2]);
		student[i][3] = (student[i][0] + student[i][1] + student[i][2]) / 3; // 각 학생의 성적 평균 대입
	}
}

void output_student(float student[][4], int num) 
{
	int i;

	for (i = 0; i < num; i++) 
	{
		printf("학생 번호 : %d, 중간 : %.1f, 기말 : %.1f, 퀴즈 : %.1f, 평균 : %.1f\n", i, student[i][0], student[i][1], student[i][2], student[i][3]);
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
	// 문제 1 : 위의 max_exams() 함수를 참조하여 학생들의 중간, 기말, 퀴즈, 평균 성적의  최소값을 찾아서 
	// 전역 1차원 배열 min[4]에 순서대로 저장하는 함수 min_exams()를 이 위치에서 작성하시오.
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
	// 문제2 : 2차원 배열 student[5][4]에 저장된 학생들의 중간성적 평균, 기말 평균, 퀴즈 평균, 평균성적의 평균을 구하여 
    // average[4]에 순서대로 저장하는 함수 average_exams()를 이 위치에 작성하시오. 
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
		// 문제3: 학생의 평균 성적을 기준으로 2차원 배열 student[5][4]를 내림 차순으로 재정렬하여 저장하도록
		// 이 위치에 적절한 명령문들을 채우시오.
	
	}
}

void sort_asc_student(float student[][4], int num)
{
	// 문제4 : 학생의 평균 성적을 기준으로 2차원 배열 student[5][4]를 오름 차순으로 재정렬하여 저장하는 함수
    // sort_asc_student()를 이 위치에 작성하시오. 
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
		// 문제3: 학생의 평균 성적을 기준으로 2차원 배열 student[5][4]를 내림 차순으로 재정렬하여 저장하도록
		// 이 위치에 적절한 명령문들을 채우시오.

	}
}
