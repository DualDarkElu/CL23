#include <stdio.h>
#include <float.h> // 데이터 타입별 최대, 최소값 정의

int print_float_info(float value, float* addr, int size);
int print_double_info(double value, double* addr, int size);
int print_ldouble_info(long double age, long double* addr, int size);