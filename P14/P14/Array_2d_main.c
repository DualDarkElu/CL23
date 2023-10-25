#include "Array_2d.h"

float min[4]; 

int main(void)
{
	float student[5][4] = { 0 }; // 행 : 학생 수, 열 : 학생별 중간, 기말, 퀴즈, 평균
	float student1[5][4] = { 0 };
	float average[4] = { 0 }; 
	float max[4] = { 0 };
	float min[4] = { 0 };
	int i, j = 0;

	// 배열 주소 확인
	check_2D_array_address(student);

	printf("학생수 입력 : ");
	scanf_s("%d", &i);

	// 학생 성적 입력
	input_student(student, i); // 학생들의 중간, 기말, 퀴즈, 평균 성적 입력을 입력하여 2차원 배열 student[5][4]에 저장

	// 학생 성적 출력
	output_student(student, i);

	// 학생들의 중간, 기말, 퀴즈, 평균 성적의  최대값을 찾아서 1차원 배열 max[4]에 순서대로 저장
	max_exams(student, max, i);
	printf("\n중간, 기말, 퀴즈, 평균 최대값 : %.1f,  %.1f,  %.1f, %.1f\n", max[0], max[1], max[2], max[3]);

	// 문제 1 : 학생들의 중간, 기말, 퀴즈, 평균 성적의  최소값을 찾아서 전역 1차원 배열 min[4]에 순서대로 저장하는 
	// 함수 min_exams()를 Array_2d_functions.c 소스 파일에 작성하시오.
	min_exams(student, min, i);
	printf("\n중간, 기말, 퀴즈, 평균 최소값 : %.1f,  %.1f,  %.1f, %.2f\n", min[0], min[1], min[2], min[3]);

	// 문제2 : 2차원 배열 student[5][4]에 저장된 학생들의 중간성적 평균, 기말 평균, 퀴즈 평균, 평균성적의 평균을 구하여 
	// average[4]에 순서대로 저장하는 함수 average_exams()를 Array_2d_functions.c 소스 파일에 작성하시오. 
	average_exams(student, average, i);
	printf("\n중간, 기말, 퀴즈, 평균의 평균값 : %.1f,  %.1f,  %.1f, %.1f\n", average[0], average[1], average[2], average[3]);

	printf("\n학생 평균 성적 내림차순 정렬 : \n");
	// 문제3: 학생의 평균 성적을 기준으로 2차원 배열 student[5][4]를 내림 차순으로 재정렬하여 저장하는 함수
	// sort_des_student()를 Array_2d_functions.c 소스 파일에서 적절하게 보완하시오.
	sort_des_student(student, i);
	// 내림차순으로 정렬한 2차원 배열 student[5][4]를 출력
	output_student(student, i);

	printf("\n학생 평균 성적 오름차순 정렬 : \n");
	// 문제4 : 학생의 평균 성적을 기준으로 2차원 배열 student[5][4]를 오름 차순으로 재정렬하여 저장하는 함수
	// sort_asc_student()를 Array_2d_functions.c 소스 파일에 작성하시오. 
	sort_asc_student(student, i); 
	output_student(student, i);

	return 0;
}
