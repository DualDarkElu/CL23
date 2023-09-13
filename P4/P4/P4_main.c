#include "p4_lib.h" // 헤더 파일을 여기에 이동

int main(int argc, char* argv[])
{
	// 정수 타입별 최대값 초기화 
	short age1 = SHRT_MAX; 
	age1 = age1 + 5;
	int age2 = INT_MAX; 
	long age3 = LONG_MAX; 
	long long age4 = LLONG_MAX;
	unsigned short age5 = USHRT_MAX;
	age5 = age5 + 5;	
	unsigned int age6 = UINT_MAX;
	unsigned long age7 = ULONG_MAX;
	unsigned long long age8 = ULLONG_MAX;

	/* short, int, long, long long 정수 변수 데이터, 변수 주소, 변수 메모리 공간 크기 출력
		& : 변수에 대응되는 주소 반환 연산자,
		sizeof() : 변수 메모리 크기 반환 연산자
	*/

	printf("데이터 타입별 정수 최대값 출력 : \n\n");
	print_short_info(age1, &age1, sizeof(age1)); 
	print_int_info(age2, &age2, sizeof(age2));
	print_long_info(age3, &age3, sizeof(age3));
	print_longlong_info(age4, &age4, sizeof(age4));

	// 오버플로우 정수값 출력
	printf("데이터 타입별 정수 오버플로우 값 출력 : \n\n");
	age2 = age2 + 2; age3 = age3 + 100; age4 = age4 + 1000;

	print_int_info(age2, &age2, sizeof(age2));
	print_long_info(age3, &age3, sizeof(age3));
	print_longlong_info(age4, &age4, sizeof(age4));

	// unsigned short, unsigned int, unsigned long, unsigned long long 정수 출력
	printf("데이터 타입별 양의 정수 최대값 출력 : \n\n");
	print_ushrt_info(age5, &age5, sizeof(age5));
	print_uint_info(age6, &age6, sizeof(age6));
	print_ulong_info(age7, &age7, sizeof(age7));
	print_ulonglong_info(age8, &age8, sizeof(age8));

	// 오버플로우 양의 정수값 출력
	printf("데이터 타입별 양의 정수 오버플로우 값 출력 : \n\n");
	age6 += 2; age7 += 100; age8 += 1000;
	print_uint_info(age6, &age6, sizeof(age6));
	print_ulong_info(age7, &age7, sizeof(age7));
	print_ulonglong_info(age8, &age8, sizeof(age8));

	return 0;
}