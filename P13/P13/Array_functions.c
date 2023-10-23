#include "Array.h"


// 전체 학생 성적 입력, 학생 수 : num
int input_student(int student[], int num) { // student[] : 매개변수가 배열 이름임을 선언(배열 선언이 아님), 
                                                        // 호출측으로부터 배열 이름(시작 주소) 초기화
	int i;

	printf("\n학생 전체 성적을 배열에 입력\n");
	for (i = 0; i < num; i++) // 배열 인덱스 0부터 시작
	{
		printf("성적 : ");
		scanf_s("%d", &student[i]); // student[i] : student 배열의 요소 변수
	}
	return 0;
}

/*
int input_student(int student1[], int num) // 위의 함수 정의와 결과가 동일할까요?
{
	int i;

	for (i = 0; i < num; i++) // 배열 인덱스 0부터 시작
	{
		printf("성적 : ");
		scanf_s("%d", &student1[i]); // student[i] : student 배열의 요소 변수
	}
	return 0;
}
*/

/*
int input_student(int *student, int num) //  위의 함수 정의와 결과가 동일할까요? 배열 이름 == 배열 요소 변수들의 시작 주소
{
	int i;
	for (i = 0; i < num; i++) 
	{
		printf("성적 : ");
		scanf_s("%d", &student[i]);
	}
	return 0;
}
*/

// 학생 전체 성적 출력, 학생수 : num
int output_student(int student[], int num) // 배열의 이름(시작주소)을 매개변수로 초기화
{
	int i;

	printf("\n배열의 학생 전체 성적을 출력\n");
	for (i = 0; i < num; i++) {
		printf("성적[%d] : %d\n", i, student[i]);
	}
	return 0;
}

// 전체 학생 성적의 평균값을 계산하여 반환하는 함수
float average_student(int student[], int num)
{
	int i, sum = 0;

	for (i = 0; i < num; i++) {
		sum += student[i];
	}

	return(sum / num);
}

// 전체 학생 성적의 최대값을 찾아서 반환하는 함수
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

// 전체 학생 성적의 최소값을 찾아서 반환하는 함수
int min_student(int student[], int num) 
{
	// 문제 1 : student 배열의 전체 학생 성적의 최소값을 반환하는 함수를 이 위치에 작성하시오.
	int i, min;

	min = student[0];
	for (i = 1; i < num; i++) {
		if (min > student[i])
			min = student[i];
	}

	return(min);
}


// 문제 2 : 배열을 내림 차순으로 정렬하는 아래 함수를 올부르게 수정하시오.
int sort_des_student(int student[], int num)
{
	int i, j, largest;

	for (i = 0; i < num; i++) // 가장 큰 요소 변수를 찾아서 i번째 요소 변수와 교체
	{
		largest = i; // i번째가 가장 큰 것으로 가정하고 시작
		for (j = i + 1; j < num; j++)
			if (student[j] > student[largest])
				largest = j; // 더 큰 요소 변수가 있으면 가장 큰 요소 변수의 인덱스를 largest로 변경

		// 가장 큰 요소 변수(student[largest]와 i번째 요소 변수(student[i])와 교체
		int temp = student[i];
		student[i] = student[largest]; // 가장 큰 요소 변수를 i번째 변수로 복제
		student[largest] = temp; // 원래 i번째 변수를 가장 큰 요소 변수 위치로 복제
	}
	return 0;
}


int sort_asc_student(int student[], int num) 
{
	// 문제 3 : 내림 차순 정렬 함수를 참조하여 배열을 오름 차순으로 정렬하는 함수를 이 위치에 작성하시오. 
	int i, j, smallest;

	for (i = 0; i < num; i++) // 가장 큰 요소 변수를 찾아서 i번째 요소 변수와 교체
	{
		smallest = i; // i번째가 가장 큰 것으로 가정하고 시작
		for (j = i + 1; j < num; j++)
			if (student[j] < student[smallest])
				smallest = j; // 더 큰 요소 변수가 있으면 가장 큰 요소 변수의 인덱스를 largest로 변경

		// 가장 큰 요소 변수(student[largest]와 i번째 요소 변수(student[i])와 교체 
		int temp = student[i];
		student[i] = student[smallest]; // 가장 큰 요소 변수를 i번째 변수로 복제
		student[smallest] = temp; // 원래 i번째 변수를 가장 큰 요소 변수 위치로 복제
	}
	return 0;
}

// 문제 4 : 아래의 backup_student() 함수를 적절하게 수정하여 작성하시오.
int backup_student(int student1[], int backup1[], int num) 
{
	int i;

	for (i = 0; i < num; i++)
	{
		backup1[i] = student1[i];
	}
	return 0;
}