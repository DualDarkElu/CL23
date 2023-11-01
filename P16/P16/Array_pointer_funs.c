#include <stdio.h>


// 포인터를 사용하여 1차원 배열에 성적 입력
int input_student(int* student, int num) 
{
	int i;

	for (i = 0; i < num; i++) // 배열 인덱스 0부터 시작
	{
		printf("성적 : ");
		scanf_s("%d", student++); // 성적 입력 후 배열 포인터 증가(다음 요소 변수로 포인터 이동)
	}
	return 0;
}


// 포인터를 사용하여 1차원 배열의 성적을 출력
int output_student(int* student, int num) 
{
	// (문제 1) student 배열의 학생들 성적을 출력하는 함수 output_student()를 배열 대신 포인터를 사용하여 작성하시오.
	printf("\n학생 성적:\n");
	for (int i = 0; i < num; ++i) {
		printf("학생 %d: %d\n", i + 1, *(student + i));
	}
	return 0;
}


// 포인터를 사용하여 1차원 배열의 성적의 평균을 반환
float average_student(int* student, int num)
{
	// (문제 2) student 배열의 학생들 성적의 평균을 반환하는 함수 average_student()를 배열 대신 포인터를 사용하여 작성하시오.
	int sum = 0;
	for (int i = 0; i < num; ++i) {
		sum += *(student + i);
	}
	return (float)sum / num;

}


// 포인터를 사용하여 1차원 배열의 성적의 최대값을 반환
int max_student(int* student, int num)
{
	// (문제 3) student 배열의 학생들 성적의 최대값을 반환하는 함수 max_student()를 배열 대신 포인터를 사용하여 작성하시오.
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

// 포인터를 사용하여 1차원 배열의 성적을 내림차순으로 정렬
int sort_des_student(int *student, int num) 
{
	// (문제 4) student 배열의 학생들 성적을 내림 차순으로 정렬하는 함수 sort_des_student()를 배열 대신 포인터를 사용하여 작성하시오.
	for (int i = 0; i < num - 1; ++i) {
		for (int j = 0; j < num - i - 1; ++j) {
			if (*(student + j) < *(student + j + 1)) {
				swap(student + j, student + j + 1);
			}
		}
	}
	return 0;
}

