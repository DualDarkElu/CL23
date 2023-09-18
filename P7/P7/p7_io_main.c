#include "p7_io.h"

int main(int argc, char* argv[])
{
	int age = 20; int *agep;
	unsigned int uint_max = UINT_MAX; 
	unsigned long long ullong_max = ULLONG_MAX;

	// 형식 지정 출력 함수 printf() 이해와 활용

	// int 변수값 다양한 형식 지정 출력
	printf("int 변수 십진수 출력 : %d, \t\t16진수 출력 : %x, \t\t문자 출력 : %c\n", age, age, age, age);
	printf("int 변수 실수(f) : %f\n", age);

	// int 변수의 주소 출력
	printf("int 변수 주소(x) : %x, \t\t주소(08x) : %08x, \t\t주소(p) : %p\n", &age, &age, &age);

	// 변수의 크기 출력
	printf("int 변수 크기d : %d, \t\t주소 크기d : %d\n", sizeof(age), sizeof(&age));


	printf("\n\n");
	age = age + pow(2, 31); // pow(2, 31)은 2^32 지수승 계산 함수
	printf("int 변수 오버플로우값(50 + 2^31) 출력: %d\n", age);
	printf("unsigned 변수 최대값 출력(u) : %u, 출력(llu) : %llu\n", uint_max, ullong_max);
	printf("unsigned int 변수 최대값 출력(d) : %d\n", uint_max);
	printf("unsigned int 변수 오버플로우 출력(d) : %d\n", uint_max + 100);
	printf("unsigned int 변수 오버플로우 출력(u) : %u\n", uint_max + 100);

	printf("\n\n");
	char ch = 'A';
	printf("문자 A 출력(c) : %c, \t\t출력(d) : %d\n", ch, ch);

	printf("\n\n");
	float height = 175.7; float *heightp;
	double height1 = 175.7;
	double dmax = DBL_MAX;
	printf("float 변수 출력(.6f) : %.6f\n", height);
	printf("float 변수 출력(.10f) : %.10f\n", height);
	printf("float 변수 출력(.15f) : %.15f\n", height);

	printf("\n\n");
	printf("double 변수 출력(.10f) : %.10f\n", height1);
	printf("double 변수 출력(.15f) : %.15f\n", height1);

	printf("\n\n");
	printf("double 변수 최대값 출력(.15f) : %.15f\n", dmax);
	printf("double 변수 최대값 출력(.15e) : %.15e\n", dmax);

	printf("\n\n");
	printf("float 변수 출력(d) : %d\n", height);
	printf("double 변수 출력(ld) : %ld\n", height1);

	// 형식 지정 보안 입력 함수 scanf_s() 이해와 활용

	printf("\n\n");
	age = 0;
	printf("age(d) : ");
	scanf_s("%d", &age); // 10진수 형식으로 입력, 변수 주소 인자 전달
	
	printf("age(d) = %d\n", age); // 10진수 형식으로 출력

	printf("\n\n");
	printf("age(x) : "); 
	scanf_s("%x", &age); // 16진수 형식으로 입력
	printf("age(x) = %d\n", age); // 십진수 형식으로 출력

	printf("\n\n");
	printf("age(c) : ");
	scanf_s(" %c", &age); // 문자 형식으로 입력(직전 문자 \n 생략)
	printf("age(c) = %d\n", age); // 십진수 출력
	rewind(stdin); // 입력 버퍼 비우기 함수

	printf("\n\n");
	// age = 0;
	// printf("age(d) : ");
	// scanf_s("%d", age); // 오류 발생(사용 불가 주소)
	// printf("age(d) = %d\n", age); 

	// agep = &age;
	// printf("age(d) : ");
	// scanf_s("%d", agep); // 정상 입력(정상 주소 사용)
	// printf("age(d) = %d\n", *agep); // * : 주소 내용 접근 연산자 

	printf("\n\n");
	age = 0; height = 0.0;
	agep = &age; heightp = &height;
	// 호출측의 인자와 함수측의 매개변수는 완전 별개 --> 함수 독립성 확보, 호출측 변수 내용을 함수에서 수정할 경우에는 반드시 변수의 주소를 호출 인자로 사용
	my_scanf(agep, heightp); //my_scanf(&age, &height);  
	printf("age = %d, height = %.1f\n", age, height);	
	printf("age 주소 = %d\n", &age);
	
	printf("\n\n");
	age = 0; height = 0.0;
	agep = &age; heightp = &height;
	printf("\n\n"); 
    my_scanf2(agep, heightp);
	printf("age = %d, height = %.1f\n", age, height);

	return 0;
}