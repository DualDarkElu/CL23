#include "my_op.h"

// ���� 2 : �Ʒ� �Լ��� switch ���� ����Ͽ� �����Ͻÿ�.�� : switch �� ���Ȯ�� 1��, 5�� ������ ��� ���� 1��
int my_op(int x, int y, int op)
{
	int result = 0;
	/*if (op == PLUS)
		result = x + y;
	else if (op == MINUS)
		result = x - y;
	else if (op == MULTIPLY)
		result = x * y;
	else if (op == DIVIDE)
		result = x / y;
	else if (op == REMAINDER)
		result = x % y;*/

    switch (op) {
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
    }
    return(result);
}