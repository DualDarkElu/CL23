#include "my_op.h"
#include "math.h"
int my_op(int x, int y, int op)
{
	/*int result = 0;

	if (op == PLUS)
		result = x + y;
	else if (op == MINUS)
		result = x - y;
	else if (op == MULTIPLY)
		result = x * y;
	else if (op == DIVIDE)
		result = x / y;
	else if (op == REMAINDER)
		result = x % y;

	return(result);*/
	
	int result = 0;

	switch (op) // 제어식(op) 값은 항상 정수이어야 한다.
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
		case EXPONENT:
			result = (int) pow( (double) x, y);
			break;
		default:
			printf("Operator not supported!!\n");
	}
	return(result);

	
}