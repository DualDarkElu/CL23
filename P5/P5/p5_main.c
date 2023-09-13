#include "p5_lib.h" 

int main(int argc, char* argv[])
{
	float x = 0.7; // ������ : 0.10110011001100... ���� ���е� 23��Ʈ���� �ݺ�
	float y = 0.9; // ������ : 0.11100110011001... ���� ���е� 23��Ʈ���� �ݺ�
	float z = x + y;
	
	printf("float x = 0.7; float y = 0.9; z = x + y;�� x, y, z�� ���ʴ�� ��� :\n");
	print_float_info(x, &x, sizeof(x));
	print_float_info(y, &y, sizeof(y));
	print_float_info(z, &z, sizeof(z));

	double x1 = 0.7; // ������ : 0.10110011001100... �ι� ���е� 52��Ʈ���� �ݺ�
	double y1 = 0.9; // ������ : 0.11100110011001... �ι� ���е� 52��Ʈ���� �ݺ�
	double z1 = x1 + y1;

	printf("double x1 = 0.7; double y1 = 0.9;  z1= x1 + y1;�� x1, y1, z1�� ���ʴ�� ��� :\n");
	print_double_info(x1, &x1, sizeof(x1));
	print_double_info(y1, &y1, sizeof(y1));
	print_double_info(z1, &z1, sizeof(z1));

	// �Ǽ� ������ Ÿ�Ժ� ���� �ִ밪, �ּҰ� �ʱ�ȭ 
	float fmax = FLT_MAX;
	double dmax = DBL_MAX;
	long double ldmax = LDBL_MAX;
	float fmin = FLT_MIN;
	double dmin = DBL_MIN;
	long double ldmin = LDBL_MIN;

	printf("float �Ǽ� �ִ밪, �ּҰ� ������� ��� :\n");
	print_float_info(fmax, &fmax, sizeof(fmax));
	print_float_info(fmin, &fmin, sizeof(fmin));

	printf("double �Ǽ� �ִ밪, �ּҰ� ������� ��� :\n");
	print_double_info(dmax, &dmax, sizeof(dmax));
	print_double_info(dmin, &dmin, sizeof(dmin));

	printf("long double �Ǽ� �ִ밪, �ּҰ� ������� ��� :\n");
	print_ldouble_info(ldmax, &ldmax, sizeof(ldmax));
	print_ldouble_info(ldmin, &ldmin, sizeof(ldmin));

	return 0;
}