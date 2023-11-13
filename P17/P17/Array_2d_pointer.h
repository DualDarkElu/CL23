#include <stdio.h>


#define MAX_NUM 5
#define COLUMN 3

int input_student1(float *student, int num);
int input_student2(float(*student)[3], int num);
int output_student(float(*student)[3], int num);
void average_student(float(*student)[3], float* pta, int num);
void max_student(float(*student)[3], float* pta, int num);
void min_student(float(*student)[3], float* pta, int num);
void statistics_output(float** pp);
int sort_des_student(float(*student)[3], int num);
void swap(float* fp1, float* fp2);
void copy_low(float* low1, float* low2, int num);