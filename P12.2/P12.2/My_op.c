#include "My_op.h"

int my_op(int x, int y, int op) 
{
	int result=0; 

	switch (op) // �����(op) ���� �׻� �����̾�� �Ѵ�.
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
	sum += result;
	return(result);
}

void decimal_convert(int x, int y) // ȣ��� ������ �Ű����� x, y ���� �� �ʱ�ȭ, ����� �� ����
{
	if (x > 0)
	{
		decimal_convert(x / y, y);
		printf("%x", x % y); // �Լ� ���� �� ����
	}
}

void urmomgay(int x, int y)
{
	if (x > 0)
	{
		urmomgay(x / y, y);
		printf("(�Ű����� x = %d, y = %d)\n", x, y);
	}
}