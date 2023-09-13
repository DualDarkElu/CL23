#include "p5_lib.h" 

int main(int argc, char* argv[])
{
	float x = 0.7; // 이진수 : 0.10110011001100... 단일 정밀도 23비트까지 반복
	float y = 0.9; // 이진수 : 0.11100110011001... 단일 정밀도 23비트까지 반복
	float z = x + y;
	
	printf("float x = 0.7; float y = 0.9; z = x + y;의 x, y, z을 차례대로 출력 :\n");
	print_float_info(x, &x, sizeof(x));
	print_float_info(y, &y, sizeof(y));
	print_float_info(z, &z, sizeof(z));

	double x1 = 0.7; // 이진수 : 0.10110011001100... 두배 정밀도 52비트까지 반복
	double y1 = 0.9; // 이진수 : 0.11100110011001... 두배 정밀도 52비트까지 반복
	double z1 = x1 + y1;

	printf("double x1 = 0.7; double y1 = 0.9;  z1= x1 + y1;의 x1, y1, z1을 차례대로 출력 :\n");
	print_double_info(x1, &x1, sizeof(x1));
	print_double_info(y1, &y1, sizeof(y1));
	print_double_info(z1, &z1, sizeof(z1));

	// 실수 데이터 타입별 변수 최대값, 최소값 초기화 
	float fmax = FLT_MAX;
	double dmax = DBL_MAX;
	long double ldmax = LDBL_MAX;
	float fmin = FLT_MIN;
	double dmin = DBL_MIN;
	long double ldmin = LDBL_MIN;

	printf("float 실수 최대값, 최소값 순서대로 출력 :\n");
	print_float_info(fmax, &fmax, sizeof(fmax));
	print_float_info(fmin, &fmin, sizeof(fmin));

	printf("double 실수 최대값, 최소값 순서대로 출력 :\n");
	print_double_info(dmax, &dmax, sizeof(dmax));
	print_double_info(dmin, &dmin, sizeof(dmin));

	printf("long double 실수 최대값, 최소값 순서대로 출력 :\n");
	print_ldouble_info(ldmax, &ldmax, sizeof(ldmax));
	print_ldouble_info(ldmin, &ldmin, sizeof(ldmin));

	return 0;
}