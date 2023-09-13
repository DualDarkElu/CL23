#include <locale.h>

int print_short_info(short age, short* addr, int size);
int print_int_info(int age, int* addr, int size);
int print_long_info(long value, long* addr, int mem_size);
int print_long_long_info(long long value, long long* addr, int mem_size);
int print_float_info(float height, float* addr, int size);
int print_double_info(double value, double* addr, int mem_size);
int print_long_double_info(long double value, long double* addr, int mem_size);
int print_char_info(char value, char* addr, int mem_size);
int print_wctype_t_info(wctype_t value, wctype_t* addr, int mem_size);