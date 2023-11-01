#include "Pointers.h"

void main(void)
{
	int i_data1 = 100, i_data2 = 200;
	double d_data = 3.14;
	char c_data = 'A';

	// (1) 포인터 변수 선언
	// 포인터 변수 : 변수의 메모리 시작 주소를 저장하는 변수
	// 포인터 변수 선언 : 지시 대상 메모리 데이터 타입, * 키워드, 변수명

	int *ip1, *ip2; 



	// (2) 포인터 연산자 : &, *
	//  & : 변수 주소 반환 연산자,  * : 포인터 변수의 메모리 내용 접근 연산자
	
	// 변수의 시작 주소 반환 : &변수
	ip1 = &i_data1; ip2 = &i_data2;
	printf("ip1 : %p, ip2 : %p\n\n", ip1, ip2); 
	// 출력 형식 지정자 %p : 주소를 8자리 16진수(x86) 또는 16자리 16진수(x64)로 출력

	// 포인터 변수가 지정하는 메모리 내용 접근 : *포인터 
	printf("*ip1 : %d, *ip2 : %d\n\n", *ip1, *ip2); 
	// ip1, ip2가 지정하는 int 타입 메모리 접근

	// & 연산자와 * 연산자 관계 
	// (문제 1) : *&i_data1의 값은 얼마인지 십진수로 쓰시오.
	printf("*&i_data1의 값 : %d", *&i_data1);

	printf("\n\n\n\n");


	// (3) 포인터 변수 크기 : 4(32비트 환경) 또는 8(64비트 환경)
	// 일반 변수의 크기와 포인터 변수 크기의 관계 이해

	double* dp1 = &d_data;
	char* cp1 = &c_data;
	printf("int 변수 크기 : %d, double 변수 크기 : %d, char 변수 크기 : %d\n\n", sizeof(i_data1), sizeof(d_data), sizeof(c_data));
	printf("int 포인터 크기 : %d, double 포인터 크기 : %d\n\n", sizeof(ip1), sizeof(dp1));
	
	// (문제 2) : sizeof(cp1)의 값이 얼마인지 10진수로 쓰시오. 64비트 환경에서 컴파일한것으로 가정한다. 8
	printf("\n\n\n\n");

	// (4) 포인터 초기화 : NULL(특수 주소 0, 컴퍼일러에 의해 접근 차단되는 일반 프로그램에서 사용할 수 없는 주소)
	// 포인터 변수는 반드시 NULL 초기화 필요 : 메모리 할당(변수 지정 포함) 없이 값을 저장하는 오류 방지 목적
	// 초기화 되지 않은 포인터 변수에 값을 저장하는 시도가 어떤 문제를 초래할 수 있는지 이해

	int* ip3 = NULL;
	printf("초기화된 포인터(ip3 = NULL) : %p\n\n", ip3);
	// ip3 = 500; 
	// NULL(0번) 주소에 500 저장 시도, 0번 주소는 응용 프로그램이 사용할 수 없는 주소이므로 OS가 실행 오류 검출

	printf("\n\n\n\n");

	// (5) 포인터 연산 : 배열 포인터 연산에서 주로 활용
	// 포인터 변수 증감 : 포인터 변수가 지시하는 메모리 타입의 크기 단위로 증감
	printf("int 포인터 ip1 : %p\n\n", ip1); 
	ip1++;
	printf("int 포인터 ip1++ : %p\n\n", ip1); // 4 단위로 증감
	ip1++;
	printf("int 포인터 ip1++ : %p\n\n", ip1); // 4 단위로 증감

	printf("int 포인터 ip1 : %p, ip1+1 : %p, ip1 + 2 : %p\n\n", ip1, ip1 + 1, ip1 + 2); // 4 단위로 증감
	
	printf("double 포인터 dp1 : %p, dp1+1 : %p, dp1+2 : %p\n\n", dp1+1, dp1+2, dp1+3); // 8 단위로 증감

	// (문제 3) : 다음 두 출력값의 차이가 얼마인지 10진수로 쓰시오. 5
	printf("char 포인터 cp1 : %p,  cp1+2 : %p\n\n", cp1, cp1+5); 
	

	printf("\n\n\n\n");


	// (6) 1차원 배열 이름과 포인터 연산

	// 배열 이름에 대한 증감 연산
	double d1_array[5] = { 1, 2, 3, 4, 5 };
	printf("1차원 배열 d_array : %p, d1_array+1 : %p, d1_array+2 : %p, d1_array+4 : %p\n\n", d1_array, d1_array + 1, d1_array + 2, d1_array + 4);
	// 구성 요소 변수(double) 크기 8 단위로 증감
	
	// (문제 4) : d1_array와 (d1_array + 4)를 출력했을 때 출력값의 차이는 십진수로 얼마인가? 32


	// d1_array + 1 : 요소 변수 d_array[1]의 주소 
	// *(d1_array + 1) == d_array[1]
	
	printf("1차원 배열 *(d1_array+1) : %.2f,   d_array[1] : %.2f\n\n", *(d1_array + 1), d1_array[1]);
	
	// *(d1_array + 2) == d_array[2]
	printf("1차원 배열 *(d1_array+2) : %.2f,   d_array[2] : %.2f\n\n", *(d1_array + 2), d1_array[2]);

	// (문제 5) : *(d1_array + 4)를 출력했을 때 값이 얼마인지 쓰시오. 5

	// 주의 : d1_array는 변수가 아니므로 증감 연산자(d1_array++) 적용 불가 --> 주소 변수에 배열 이름을 대입한 후 증감 연산자 사용
	double* dp2; 
	dp2 = d1_array;

	// 주의 : 포인터 변수의 내용을 함수 인자로 사용하는 경우 해당 포인터 변수에 대한 증감 연산은 적용 가능
	printf("1차원 배열 *(d1_array) : %.2f\n\n", *(dp2));
	printf("1차원 배열 *(d1_array+1) by *(++dp2) : %.2f,   d_array[1] : %.2f\n\n", *(++dp2), d1_array[1]);
	printf("1차원 배열 *(d1_array+2) by *(++dp2) : %.2f,   d_array[2] : %.2f\n\n", *(++dp2), d1_array[2]);

	printf("\n\n\n\n");


	// (7) 2차원 배열 이름에 대한 증감 연산
	double d2_array[5][2] = { {1, 2}, {10, 20}, {100, 200}, {1000, 2000}, {0, 0} };
	printf("2차원 배열 d2_array : %p, d2_array+1 : %p, d2_array+2 : %p\n\n", d2_array, d2_array + 1, d2_array + 2);
	// 구성 요소 배열(1차원 double[2]) 크기 16 단위로 증감
	
	// (문제 6) : d2_array와 (d2_array + 4)를 출력했을 때 출력값의 차이는 십진수로 얼마인가? 64

	// d2_array : 2차원 배열 d2_array[5][2]의 시작 주소, 
	// d2_array[0] : 2차원 배열 d2_array[5][2]의 첫번째(0번째) 1차원 배열의 주소, 
	// &d2_array[0][0] : 2차원 배열 d2_array[5][2]의 첫번째(0번째) 요소 변수의 주소
	
	printf("2차원 배열 d2_array : %p, d2_array[0] : %p, &d2_array[0][0] : %p\n\n", d2_array, d2_array[0], &d2_array[0][0]);
	printf("\n\n\n\n");

	// *(d2_array) : d2_array[5][2]의 첫번째(0번째) 1차원 요소 배열 d2_array[0]
	// *(d2_array + 1) : d2_array[5][2]의 두번째(1번째) 1차원 요소 배열 d2_array[1]
	// *(d2_array + 2) : d2_array[5][2]의 세번째(2번째) 1차원 요소 배열 d2_array[2]
	printf("2차원 배열 *(d2_array) : %p, *(d2_array + 1) : %p, *(d2_array + 2) : %p\n\n", *(d2_array), *(d2_array + 1), *(d2_array + 2));
	printf("2차원 배열 d2_array[0] : %p, d2_array[1] : %p, d2_array[2] : %p\n\n", d2_array[0], d2_array[1], d2_array[2]);
	printf("\n\n\n\n");

	// *(d2_array + 1) = d2_array[1], 
	// *(d2_array + 1) +1 == d2_array[1] + 1 == &d2_array[1][1];
	printf("2차원 배열 *(d2_array + 1) : %p,   d2_array[1] : %p\n\n", *(d2_array + 1), d2_array[1]);
	printf("2차원 배열 *(d2_array + 1) +1 : %p,   d2_array[1] + 1 : %p,   &d2_array[1][1] : %p\n\n", *(d2_array + 1) + 1, d2_array[1] + 1, &d2_array[1][1]);
	printf("\n\n\n\n");

	// **(d2_array + 1) = *d2_array[1],  
	// 2차원 배열 d2_array[5][2]의 두번째 1차원 요소 배열 d2_array[1]의 첫번째 요소 변수 d2_array[1][0] 
	printf("2차원 배열 **(d2_array + 1) : %.2f,   *d2_array[1] : %.2f, d2_array[1][1] : %.2f\n\n", **(d2_array + 1), *d2_array[1], d2_array[1][0]);

	// *(*(d2_array + 2) +1) == *(d2_array[2] + 1) == *(&d2_array[2][1]) == d2_array[2][1];
	// 2차원 배열 d2_array[5][2]의 세번째 1차원 요소 배열 d2_array[2]의 두번째 요소 변수 d2_array[2][1]
	printf("2차원 배열 *(*(d2_array + 2) +1) : %.2f,   *(d2_array[2] + 1) : %.2f,   d2_array[2][1] : %.2f\n\n", *(*(d2_array + 2) + 1), *(d2_array[2] + 1), d2_array[2][1]);
	
	// (문제 7) : *(*(d2_array + 3) + 1)를 출력했을 때 값은 십진수로 얼마인가? 2000

	printf("\n\n\n\n");


	// (8) 포인터 타입 변환(형 변환)
	i_data1 = 0x12345678;
	cp1 = (char *)&i_data1;
	// cp1 = &i_data1; 동일한 결과


	for (int i = 0; i < 4; i++)
	{
	 	printf("0x12345678의 %d번째 바이트 : %x\n", i, *(cp1 + i));
	}

	// (문제 8) : *(cp1 + 2)를 십진수로 출력하면 값이 얼마인가? 34

	for (int i = 0; i < 4; i++)
	{
	 	printf("0x12345678의 %d번째 바이트 : %x\n", i, *cp1++);
	}
	


	// (9) 포인터 변수 관련 자주 발생하는 오류
	
	// NULL 포인터 메모리에 값 대입 오류(정상 메모리 주소 미대입 포인터)
	int* ip4 = NULL;
	// *ip4 = 1000; 실행 오류 발생

    ip4 = &i_data1;
	*ip4 = 1000;
	printf("*ip4 : %d\n\n", *ip4); 

	// 포인터에 임의의 값 대입 오류
	// ip4 = 10000; // 포인터에 주소 10000 대입
	// printf("*ip4 : %d\n", *ip4); // 주소 10000의 4 바이트 출력 시도, 오류 발생


	// 값 변수에 의한 함수 호출(call by value) : 변수 복사
	i_data1 = 1000, i_data2 = 2000;
	data_swap1(&i_data1, &i_data2);
	printf("값 변수에 의한 swap 함수 호출 결과 data1 : %d, data2 : %d\n\n", i_data1, i_data2);
	// data_swap1() 함수의 변수 교환이 i_data1과 i_data2 변수에 영향을 미치지 않음

    // (문제 9) : 포인터 변수를 사용하여 data_swap1() 함수를 i_data1과 i_data2를 교환할 수 있도록 적절하게 수정하시오.
	// 포인터 변수에 의한 함수 호출(call by reference) : 포인터 복사
	
	printf(" 포인터 변수에 의한 swap 함수 호출 결과 data1 : %d, data2 : %d\n", i_data1, i_data2);
	// data_swap2() 함수의 포인터 변수 내용 교환은 i_data1과 i_data2 변수의 교환과 연결됨
	



	// (10) 배열 변수에 의한 함수 호출
	int array1[5] = { 1, 2, 3, 4, 5 };
	int array2[5] = { 10, 20, 30, 40, 50 };

	// (문제 10) : 아래 array1과 array2를 교환하는 함수를 포인터를 사용하여 작성하시오.
	data_swap3(array1, array2);

	printf("\nArray1 :");
	for (int i = 0; i < 5; i++)
		printf("%d,  ", array1[i]);

	printf("\nArray2 :");
	for (int i = 0; i < 5; i++)
		printf("%d,  ", array2[i]);
}

