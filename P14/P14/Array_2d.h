#include <stdio.h>

#define MAX_NUM 5
#define COLUMN 4

void check_2D_array_address(float student[][COLUMN]);
void input_student(float student[][COLUMN], int num); 
void input_student1(float student[]);
void average_exams(float student[][COLUMN], float average[], int num);
void max_exams(float student[][COLUMN], float max[], int num);
void min_exams(float student[][COLUMN], float max[], int num);
void sort_des_student(float student[][COLUMN], int num);
void sort_asc_student(float student[][COLUMN], int num);
void output_student(float student[][COLUMN], int num);
void copy_low(float low1[], float low2[], int num);