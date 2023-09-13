#include "p3_lib.h" 

int main(int argc, char* argv[])
{

	short age1; int age2; long age3; long long age4;
	float height1; double height2; long double height3;
	char ch, ch1;
	wctype_t hc, hc1;

	age1 = age2 = age3 = age4 = 30;

	print_short_info(age1, &age1, sizeof(age1));
	print_int_info(age2, &age2, sizeof(age2));
	print_long_info(age3, &age3, sizeof(age3));
	print_long_long_info(age4, &age4, sizeof(age4));
	// 문제1 : 이곳에서 short 변수 age1의 값, 주소, 메모리 크기를 출력하는 함수를 호출하고, \
	   Variables_lib.c에 관련 함수를 정의한 후, Variables_lib.h에 관련 함수 원형을 작성하시오.
	// 문제2 : 이곳에서 long long 변수 age4의 값, 주소, 메모리 크기를 출력하는 함수를 호출하고, \
	   Variables_lib.c에 관련 함수를 정의한 후, Variables_lib.h에 관련 함수 원형을 작성하시오.

	height1 = height2 = height3 = 178.5;
	print_float_info(height1, &height1, sizeof(height1));
	print_double_info(height2, &height2, sizeof(height2));
	print_long_double_info(height2, &height2, sizeof(height2));
	// 문제3 : 이곳에서 long double 변수 height3의 값, 주소, 메모리 크기를 출력하는 함수를 호출하고, \
	   Variables_lib.c에 관련 함수를 정의한 후, Variables_lib.h에 관련 함수 원형을 작성하시오.

	setlocale(LC_ALL, "KOREAN");
	ch = 'A';
	ch1 = '가';
	print_char_info(ch, &ch, sizeof(ch));
	print_char_info(ch1, &ch1, sizeof(ch1));

	hc = L'가';
	hc1 = '가';
	print_char_info(hc, &hc, sizeof(hc));
	print_char_info(hc1, &hc1, sizeof(hc1));
	// 심화문제4 : 이곳에서 wctype_t 변수 hc의 문자값, 주소, 메모리 크기를 출력하는 함수를 호출한후 hc1에 대해서도 \
	   호출하고, Variables_lib.c에 관련 함수를 정의한 후, Variables_lib.h에 관련 함수 원형을 작성하시오. \
       실행 결과를 비교한후,  차이가 있으면 이유를 설명해 보시오.

	return 0;
}