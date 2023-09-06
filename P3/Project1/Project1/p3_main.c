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
	// ����1 : �̰����� short ���� age1�� ��, �ּ�, �޸� ũ�⸦ ����ϴ� �Լ��� ȣ���ϰ�, \
	   Variables_lib.c�� ���� �Լ��� ������ ��, Variables_lib.h�� ���� �Լ� ������ �ۼ��Ͻÿ�.
	// ����2 : �̰����� long long ���� age4�� ��, �ּ�, �޸� ũ�⸦ ����ϴ� �Լ��� ȣ���ϰ�, \
	   Variables_lib.c�� ���� �Լ��� ������ ��, Variables_lib.h�� ���� �Լ� ������ �ۼ��Ͻÿ�.

	height1 = height2 = height3 = 178.5;
	print_float_info(height1, &height1, sizeof(height1));
	print_double_info(height2, &height2, sizeof(height2));
	print_long_double_info(height2, &height2, sizeof(height2));
	// ����3 : �̰����� long double ���� height3�� ��, �ּ�, �޸� ũ�⸦ ����ϴ� �Լ��� ȣ���ϰ�, \
	   Variables_lib.c�� ���� �Լ��� ������ ��, Variables_lib.h�� ���� �Լ� ������ �ۼ��Ͻÿ�.

	setlocale(LC_ALL, "KOREAN");
	ch = 'A';
	ch1 = '��';
	print_char_info(ch, &ch, sizeof(ch));
	print_char_info(ch1, &ch1, sizeof(ch1));

	hc = L'��';
	hc1 = '��';
	print_char_info(hc, &hc, sizeof(hc));
	print_char_info(hc1, &hc1, sizeof(hc1));
	// ��ȭ����4 : �̰����� wctype_t ���� hc�� ���ڰ�, �ּ�, �޸� ũ�⸦ ����ϴ� �Լ��� ȣ������ hc1�� ���ؼ��� \
	   ȣ���ϰ�, Variables_lib.c�� ���� �Լ��� ������ ��, Variables_lib.h�� ���� �Լ� ������ �ۼ��Ͻÿ�. \
       ���� ����� ������,  ���̰� ������ ������ ������ ���ÿ�.

	return 0;
}