#include "Array_2d_pointer.h"

int main(void)
{
	float student[10][3] = { {1,2,3}, {4,5,6}, {7,8,9} }; // 학생들의 중간성적, 기말성적, 퀴즈 성적, 평균 성적 2차원 배열

	// 다음 3개의 출력문의 의미를 정확하게 이해
	printf("2차원 배열 student : %p, 첫번째 1차원 배열 student[0] : %p, 첫번째 요소 변수 &student[0][0] : %p\n\n", student, student[0], &student[0][0]);

	// 1차원 배열의 이름은 연속된 요소 변수의 시작 주소, 2차원 배열의 이름은 연속된 1차원 배열의 시작 주소
	
	// 1차원 배열 이름 증가 연산 : 요소 변수 크기 단위, 2차원 배열 이름 증가 연산 : 1차원 요소 배열 크기 단위
	
	// 1차원 배열 주소의 내용 접근 연산(*) : 해당 요소 변수, 2차원 배열 주소의 내용 접근 연산(*) : 해당 1차원 요소 배열
	
	printf("student 2차원 배열의 두번째 1차원 배열 *(student+1) : %p, student[1]: %p\n\n", *(student + 1), student[1]);
	// student+1 : 2차원 배열 student의 두번째(1번째) 요소의 주소, *(student+1) : 2차원 배열 student의 두번째 요소의 내용(두번째 1차원 배열)

	printf("student 2차원 배열의 student[0][0] : %.2f,  **student : %.2f\n\n", student[0][0], **student);
	printf("student 2차원 배열의 student[1][1] : %.2f,  *(*(student+1) + 1) : %.2f\n\n", student[1][1], *(*(student + 1)+1));
	// 2차원 배열의 이름은 이중 포인터 상수
	

	// *(student+1) + 1 : 두번째 1차원 배열의 두번째(1번째) 요소의 주소, *(*(student+1) + 1) : 두번째 1차원 배열의 두번째 요소 변수
	// (질문 1) :*(*(student+2) + 2)의 값은 얼마인가? 
	//9.00
	printf("*(*(student+2) + 2) : %.2f\n\n", *(*(student + 2) + 2));

	int i; // 학생 수

	printf("학생수 입력 : ");
	scanf_s("%d", &i);

	input_student1(student, i); 

	// input_student1() 함수에서 학생 1 : 50, 70, 60, 학생 2 : 65, 55, 75, 학생 3 : 90, 80, 100을 입력하였다.
	// (질문 2): student[1][1], student[1][2]의 값은 각각 얼마인가? student[2][1], student[2][2]의 값은 각각 얼마인가?
	/*student[1][1] : 100.00, student[1][2] : 6.00

	student[2][1] : 8.00, student[2][2] : 9.00*/
	printf("student[1][1] : %.2f, student[1][2] : %.2f\n\n", *(*(student + 1) + 1), *(*(student + 1) + 2));
	printf("student[2][1] : %.2f, student[2][2] : %.2f\n\n", *(*(student + 2) + 1), *(*(student + 2) + 2));

	printf("\n\n");
	float student2[10][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	
	input_student2(student2, i); 

	// input_student2() 함수에서 학생 1 : 50, 70, 60, 학생 2 : 65, 55, 75, 학생 3 : 90, 80, 100을 입력하였다.
	// (질문 3) : student2[1][1], student2[1][2]의 값은 각각 얼마인가? student2[2][1], student2[2][2]의 값은 각각 얼마인가?
	/*student2[1][1] : 100.00, student2[1][2] : 6.00

	student2[2][1] : 8.00, student2[2][2] : 9.00*/
	printf("student2[1][1] : %.2f, student2[1][2] : %.2f\n\n", *(*(student2 + 1) + 1), *(*(student2 + 1) + 2));
	printf("student2[2][1] : %.2f, student2[2][2] : %.2f\n\n", *(*(student2 + 2) + 1), *(*(student2 + 2) + 2));
	
	printf("\n\n");
	float student3[10][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

	input_student3(student3, i); 
	output_student(student3, i);

	// input_student3() 함수에서 학생 1 : 50, 70, 60, 학생 2 : 65, 55, 75, 학생 3 : 90, 80, 100을 입력하였다.
    // (질문 4) : student3[1][1], student3[1][2]의 값은 각각 얼마인가? student3[2][1], student3[2][2]의 값은 각각 얼마인가?
	/*student3[1][1] : 55.00, student3[1][2] : 75.00

	student3[2][1] : 80.00, student3[2][2] : 100.00*/
	printf("student3[1][1] : %.2f, student3[1][2] : %.2f\n\n", *(*(student3 + 1) + 1), *(*(student3 + 1) + 2));
	printf("student3[2][1] : %.2f, student3[2][2] : %.2f\n\n", *(*(student3 + 2) + 1), *(*(student3 + 2) + 2));


	float average[3] = { 50,60,70 }; // 중간, 기말, 퀴즈 성적의 평균값 1차원 배열
	float max[3] = { 500,600,700 }; // 중간, 기말, 퀴즈 성적의 최대값 1차원 배열
	float min[3] = { 100,200,300 }; // 중간, 기말, 퀴즈 성적의 최소값 1차원 배열

	float* stat[3]; // 각 요소 변수가 1차원 배열 average[3], max[3], min[3]의 주소를 저장하는 포인터 배열
	float** pp; // 변수의 내용이 주소(포인터)인 이중 포인터

	stat[0] = average; stat[1] = max; stat[2] = min;

	// 이중 포인터 이해
	pp = stat;
	printf("**pp : %.2f\n", **pp);
	printf("*(*pp + 1) : %.2f\n", *(*pp + 1));

	// (질문 5) *(*(++pp) + 1)의 값은 얼마인가?
	//*(*(++pp) + 1) : 600.00
	printf("*(*(++pp) + 1) : %.2f\n", *(*(++pp) + 1));
	
	pp = stat;
	// (질문 6) *pp, **pp, *(*pp+1), *(*pp+2)의 내용은 각각 무엇인가?
	//
	
	// (문제 1) 학생들의 중간, 기말, 퀴즈 각각의 평균 성적을 average[3]의 각 요소 변수에 순서대로 저장하는 
	// average_student() 함수를 포인터를 사용하여 작성하시오.
	average_student(student3, *pp, i);
	printf("중간 기말 퀴즈 평균값 : %.1f,  %.1f,  %.1f\n", **pp, *(*pp + 1), *(*pp + 2));

	pp++;
	// (질문 6) *pp, **pp, *(*pp+1), *(*pp+2)의 내용은 각각 무엇인가?

	// (문제 2) 학생들의 중간, 기말, 퀴즈 각각의 최대값을 max[3]의 각 요소 변수에 순서대로 저장하는 
	// max_student() 함수를 포인터를 사용하여 작성하시오.
	max_student(student3, *pp, i);
	printf("중간 기말 퀴즈 최대값 : %.1f,  %.1f,  %.1f\n", **pp, *(*pp + 1), *(*pp + 2));

	pp++;
	// (질문 7) *pp, **pp, *(*pp+1), *(*pp+2)의 내용은 각각 무엇인가?
	min_student(student3, *pp, i);
	printf("중간 기말 퀴즈 최소값 : %.1f,  %.1f,  %.1f\n", **pp, *(*pp + 1), *(*pp + 2));


	// 중간, 기말, 퀴즈 성적에 대한 평균, 최대값, 최소값 출력
	printf("성적 통계 정보 출력 :\n\n");
	statistics_output(stat);

	printf("기말 성적 기준 내림차순 정렬 : \n");

	// (문제 3) 2차원 배열 student를 기말 성적 기준으로 내림 차순으로 정렬하는 함수 sort_des_student()를
	// 포인터를 사용하여 작성하시오.
	sort_des_student(student3, i);
	output_student(student3, i);


	return 0;
}
