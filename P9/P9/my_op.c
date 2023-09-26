#include "my_op.h"

// 문제 2 : 아래 함수를 switch 문을 사용하여 수정하시오.평가 : switch 문 사용확인 1점, 5개 연산자 모두 실행 1점
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