#include "My_op.h"

extern int runtime;
extern int result = 0;

int my_op(int x, int y, int op) 
{

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
	default:
		printf("Operator not supported!!\n");
	}
	return(result);
}

void decimal_convert(int x, int y) // 호출될 때마다 매개변수 x, y 생성 및 초기화, 종료될 때 삭제
{
	runtime += 1;
	if (x > 0)
	{
		decimal_convert(x / y, y);
		printf("%x", x % y); // 함수 종료 후 실행
	}
}

void MeGeByeonSoo(int x, int y)
{
	if (x > 0)
	{
		MeGeByeonSoo(x / y, y);
		printf("(매개변수 x = %d, y = %d)\n", x, y);
	}
}