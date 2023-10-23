#include "Array.h"

int main(void)
{

	int student[10] = { 0 }; // int 변수 10개의 연속, student[0],..., student[9], student: 배열의 이름, 연속 변수 10개의 시작 주소
	int backup[10] = { 0 }; // 첫 3개 변수 1로 초기화, 나머지는 0으로 초기화
	// student = { 10, 20, 20 };  오류 : student는 변수가 아님, 연속된 10개 변수 배열의 이름(배열 요소 변수들의 시작 주소)

	printf("student : %p, &student[0] : %p\n", student, &student[0]); // 두 출력값의 관계는?
	printf("student : %p, &student : %p\n", student, &student); // 두 출력값의 관계는?
	
	printf("배열크기 : %d\n", sizeof(student)); // student 배열이 포함하는 전체 변수들의 크기
	printf("배열주소 크기 : %d\n", sizeof(&student)); // student 배열이 포함하는 전체 변수들의 시작 주소의 크기

	int i = 0;
	printf("\n학생수 입력 : ");
	scanf_s("%d", &i);

	// 전체 학생 성적 입력 함수 호출
	input_student(student, i); // 배열의 이름을 인자로 전달, 배열 이름은 요소 변수들의 시작 주소

	// 전체 학생 성적 평균 반환 함수 호출
	printf("\n평균값 : %f\n", average_student(student, i));

	// 전체 학생 성적 최대값 반환 함수 호출
	printf("최대값 : %d\n", max_student(student, i));

	// 전체 학생 성적 최소값 반환 함수 호출
	printf("최소값 : %d\n", min_student(student, i)); // 문제 1 : student 배열의 전체 학생 성적의 최소값을 반환하는 함수 min_student()를 
	                                                                 // Arry_functions.c 소스 파일에서 작성하시오.

	printf("\n내림차순 정렬 : \n");
	
	sort_des_student(student, i); // 문제2 : 전체 학생 성적을 내림차순으로 정렬하여 배열에 재저장하는 함수 호출 함수 sort_des_student()를 
	                                     // Arry_functions.c 소스 파일에서 올바르게 수정하시오.
	// 내림 차순으로 정렬된 배열의 학생 성적 출력
	output_student(student, i);
	
	
	printf("\n오름차순 정렬 : \n"); 
	sort_asc_student(student, i); // 문제 3 : 내림 차순 정렬 함수를 참조하여 배열을 오름 차순으로 정렬하는 함수 sort_asc_student()를 
	                                     // Arry_functions.c 소스 파일에서 작성하시오.
	// 오름 차순으로 정렬된 배열의 학생 성적 출력
	output_student(student, i);
	
	// student 배열을 backup 배열로 복제하는 함수 호출
	backup_student(student, backup, i); // 문제 4 : student 배열을 backup 배열로 복제하는 함수 backup_student()를 
										            // Arry_functions.c 소스 파일에 적절하게 수정하여 작성하시오.
	printf("\nbackup 배열 출력 \n");
	output_student(backup, i);

	return 0;
	
}