#include "Array_2d_pointer.h"

// (질문 2) 아래 함수의 매개변수 정의의 문제점은 무엇인가? 
// 포인터 증가 연산 : float 타입 크기 만큼 이동
int input_student1(float *student, int num) // 2차원 배열을 float 포인터 매개변수로 받는 경우
{
	int i;

	for (i = 0; i < num; i++) 
	{
		printf("순번 %d 중간성적 : ", i);
		scanf_s("%f", student); 
		printf("순번 %d 기말성적 : ", i); 
		scanf_s("%f", student + 1); 
		printf("순번 %d 퀴즈성적 : ", i);
		scanf_s("%f", student + 2); 

		++student; 
	}
	return 0;
}

// (질문 3) 아래 함수의 매개변수 정의의 문제점은 무엇인가? 
// 포인터 증가 연산 : 주소 타입 크기 만큼 이동(x64의 경우 8바이트씩 이동, x86의 4바이트씩 이동)
int input_student2(float* student[3], int num) // 2차원 배열을 float 포인터 배열 매개변수로 받는 경우
{
	int i;

	for (i = 0; i < num; i++)
	{
		printf("순번 %d 중간성적 : ", i);
		scanf_s("%f", student);
		printf("순번 %d 기말성적 : ", i);
		scanf_s("%f", student + 1); // 주소 크기만큼 증가(4 또는 8)
		printf("순번 %d 퀴즈성적 : ", i);
		scanf_s("%f", student + 2);

		++student; // 주소 크기만큼 증가(4 또는 8)
	}
	return 0;
}

// 배열 포인터 이해
int input_student3(float (*student)[3], int num) // 2차원 배열을 배열[3] 포인터 매개변수로 받는 경우
{
	int i;

	for (i = 0; i < num; i++)
	{
		printf("순번 %d 중간성적 : ", i);
		scanf_s("%f", *student); // (*student + 0) : i번째 1차원 배열의 0번째 요소 변수의 주소
		printf("순번 %d 기말성적 : ", i);
		scanf_s("%f", *student + 1); // (*student + 1) : i번째 1차원 배열의 1번째 요소 변수의 주소
		printf("순번 %d 퀴즈성적 : ", i);
		scanf_s("%f", *student + 2); // (*student + 2) : i번째 1차원 배열의 2번째 요소 변수의 주소

		++student;
		// 배열 포인터 증가 : 배열 크기만큼 포인터 증가(다음 배열의 시작 주소로 포인터 이동)
		// student는 배열 포인터 변수이므로 증감 연산자 적용 가능(2차원 배열 상수가 아님)
	}
	return 0;
}

int output_student(float(*student)[3], int num) // student : 배열[3]에 대한 포인터 변수
{
	int i;

	for (i = 0; i < num; i++) 
	{
		printf("No : %d, 중간성적 : %.1f, 기말성적 : %.1f, 퀴즈성적 : %.1f\n", i, **student, *(*student + 1), *(*student + 2));

		++student; // 배열 포인터 증가 : 배열 크기만큼 포인터 증가(다음 배열로 포인터 이동)
	}
	return 0;
}


// (문제 1) 배열 포인터 student가 지시하는 2차원 배열의 중간, 기말, 퀴즈 성적 각각의 평균을 구해 
// 포인터 avg가 지시하는 1차원 배열의 각 요소 변수에 저장하는 함수를 포인터로 작성하시오.
void average_student(float (*student)[3], float *avg, int num) 
{
	int i, j;
	int sum[3] = { 0 };

	for (i = 0; i < num; i++) 
	{
		for (j = 0; j < 3; j++)
		{
			sum[j] += *(*student + j);
		}
		student++;
	}

	for (j = 0; j < 3; j++)
	{
		*(avg + j) = sum[j] / num;
	}

}


// (문제 2) student[5][3] 배열의 학생들의 중간, 기말, 퀴즈 성적 각각에 대한 최대값을 구하여 
// max 포인터가 가르키는 1차원 배열에 저장하는 함수를 포인터로 작성하시오.
void max_student(float (*student)[3], float *max, int num) 
{
	int i, j;

	float (*arp)[3]; // 배열 포인터 선언

	arp = student; // 배열 포인터 arp에 2차원 배열의 시작 배열 포인터 대입(0번째 학생의 성적 1차원 배열)
	for (i = 0; i < 3; i++) // i번째 성적에 대해(0:중간, 1:기말, 2:퀴즈)
	{
		*max = *(*arp + i); // i번째 성적의 최대값 초기화(0번째 학생의 성적을 pta 포인터의 내용으로 대입)

		arp++; // 다음 학생의 성적 1차원 배열로 이동
		for (j = 1; j < num; j++) //1번째 학생부터 마지막 학생까지 반복 적용
		{	
			if (*max < *(*arp + i)) // i번째 성적이 기존 최대값 보다 큰지 확인
				*max = *(*arp + i); // i번째 성적에 대한 최대값 교체(pta 포인터 내용 변경)
			arp++; // 다음 학생의 성적 1차원 배열로 이동
		}
		max++; // 최대값 포인터 배열 이동(다음 성적에 대한 최대값 포인터)
		arp = student; // 배열 포인터 arp에 2차원 배열의 시작 배열 포인터 대입(0번째 학생의 성적 1차원 배열)
	}

}


// student[5][3] 배열의 학생들의 중간, 기말, 퀴즈 성적 각각에 대한 최소값을 구하여 
// pta 포인터가 가르키는 1차원 배열에 저장하는 함수를 포인터로 작성하시오.
void min_student(float(*student)[3], float* min, int num)
{
	int i, j;

	float(*arp)[3]; // 배열 포인터 선언

	arp = student; // 배열 포인터 arp에 2차원 배열의 시작 배열 포인터 대입(0번째 학생의 성적 1차원 배열)
	for (i = 0; i < 3; i++) // i번째 성적에 대해(0:중간, 1:기말, 2:퀴즈)
	{
		*min = *(*arp + i); // i번째 성적의 최소값 초기화(0번째 학생의 성적을 pta 포인터의 내용으로 대입)

		arp++; // 다음 학생의 성적 1차원 배열로 이동
		for (j = 1; j < num; j++) //1번째 학생부터 마지막 학생까지 반복 적용
		{
			if (*min > *(*arp + i)) // i번째 성적이 기존 최소값 보다 작은지 확인
				*min = *(*arp + i); // i번째 성적에 대한 최소값 교체(pta 포인터 내용 변경)
			arp++; // 다음 학생의 성적 1차원 배열로 이동
		}
		min++; // 최소값 포인터 배열 이동(다음 성적에 대한 최소값 포인터)
		arp = student; // 배열 포인터 arp에 2차원 배열의 시작 배열 포인터 대입(0번째 학생의 성적 1차원 배열)
	}
}


// 이중 포인터 변수 pp는 전체 학생들에 대한 중간, 기말, 퀴즈 성적 각각에 대한 평균, 최대, 최소값을 저장한 
// average[3], max[3], min[3] 배열 각각의 포인터를 저장하는 포인터 배열 *stat[3]의 이름으로 초기화된다.
//  중간, 기말, 퀴즈 성적 각각에 대한 평균, 최대, 최소값을 출력하는 함수를 이중 포인터를 사용하여 작성하시오.
void statistics_output(float** pp) // 이중 포인터
{
	printf("중간평균 : %.1f, 기말평균 :%.1f, 퀴즈평균 : %.1f\n", **pp, *(*pp + 1), *(*pp + 2));
	pp++;
	printf("중간최대 : %.1f, 기말최대 :%.1f, 퀴즈최대 : %.1f\n", **pp, *(*pp + 1), *(*pp + 2));
	pp++;
	printf("중간최소 : %.1f, 기말최소 :%.1f, 퀴즈최소 : %.1f\n", **pp, *(*pp + 1), *(*pp + 2));

}


	// (문제 3) 2차원 배열 student를 기말 성적 기준으로 내림 차순으로 정렬하는 함수 sort_des_student()를
	// 포인터를 사용하여 작성하시오.
int sort_des_student(float (*student)[3], int num) 
{
	int i, j, largest;
	float (*ap)[3];

	ap = student;
	for (i = 0; i < num; i++)
	{
		largest = i;
		ap = student + i + 1;
		for (j = i + 1; j < num; j++) {
			if (*(*ap + 1) > *(*(student + largest) + 1))
				largest = j;
			ap++;
		}
		swap(*(student + i),  *(student + largest));
	}

}

void swap(float* fp1, float *fp2) {
	float temp[3];

	copy_low(temp, fp1, 3);
	copy_low(fp1, fp2, 3);
	copy_low(fp2, temp, 3);


}

void copy_low(float *low1, float *low2, int num)
{
	int i;

	for (i = 0; i < num; i++)
		*(low1+i) = *(low2+i);

}

