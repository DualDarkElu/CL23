#include "Array_pointer.h"

int main(void)
{
	int student[MAX_NUM] = { 0 }; 
	int i = 0;
	int* pt = NULL; // 정수값을 저장할 수 있는 주소 변수

	printf("학생수 입력 : ");
	scanf_s("%d", &i);

	input_student(student, i); // 학생들의 성적을 배열에 입력

	// (문제 1) student 배열의 학생들 성적을 출력하는 함수 output_student()를 포인터를 사용하여 작성하시오.
	output_student(student, i);  

	// (문제 2) student 배열의 학생들 성적의 평균을 반환하는 함수 average_student()를 포인터를 사용하여 작성하시오.
	printf("\n평균값 : %f\n\n", average_student(student, i));

	// (문제 3) student 배열의 학생들 성적의 최대값을 반환하는 함수 max_student()를 포인터를 사용하여 작성하시오.
	printf("\n최대값 : %d\n\n", max_student(student, i));


	printf("\n내림차순 정렬 : \n");
	// (문제 4) student 배열의 학생들 성적을 내림 차순으로 정렬하는 함수 sort_des_student()를 포인터를 사용하여 작성하시오.
	sort_des_student(student, i);
	output_student(student, i);

	return 0;
}