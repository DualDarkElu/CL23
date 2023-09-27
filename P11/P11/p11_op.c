#include "p11_op.h"

int my_op(int x, int y, int op) 
{
	int result = 0; 

	switch (op) 
	{
		case PLUS:
			result = x + y;
			break;
		case MINUS:
			result = x - y;
			break;
		case MULTIPLY:
			result = x * y;
			break;
		case DIVIDE:
			result = x / y;
			break;
		case REMAINDER:
			result = x % y;
			break;
		default:
			printf("Operator not supported!!\n");
	}
	return(result);
}

void decimal_convert(int x, int y)// ������ȯ ��� �Լ� : ��ȯ���� �ֿܼ� ���
{
	// ������ x�� y ������ ��ȯ�ϰ� ����ϴ� �Լ��� ����Լ� �������� �ۼ��Ͻÿ�(�����ڷ� ����).
	// ����4 : decimal_convert() ����Լ��� �� ������ ȣ��� ������ �� ó�� ȣ��� ������ �Ű����� x�� y�� ���� \
	             "(�Ű����� x = %d, y = %d)\n"�� �������� ���ʴ�� ����ϵ��� decimal_convert()�� �����Ͻÿ�.
	printf("(�Ű����� x = %d, y = %d)\n", x, y);
	if (x == 0) return;
	decimal_convert(x / y, y);
	printf("%d", x % y);
}