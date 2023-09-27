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

void decimal_convert(int x, int y)// 진수변환 재귀 함수 : 변환값을 콘솔에 출력
{
	// 십진수 x를 y 진수로 변환하고 출력하는 함수를 재귀함수 형식으로 작성하시오(강의자료 참고).
	// 문제4 : decimal_convert() 재귀함수가 맨 마지막 호출될 때부터 맨 처음 호출될 때까지 매개변수 x와 y의 값을 \
	             "(매개변수 x = %d, y = %d)\n"의 형식으로 차례대로 출력하도록 decimal_convert()을 수정하시오.
	printf("(매개변수 x = %d, y = %d)\n", x, y);
	if (x == 0) return;
	decimal_convert(x / y, y);
	printf("%d", x % y);
}