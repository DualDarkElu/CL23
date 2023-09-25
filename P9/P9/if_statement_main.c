#include "my_op.h"

// 문제1 : 아래 프로그램을 5개 연산 모두가 실행되도록 수정하시오. 평가 : 제출 1점, 5개 연산자 모두 정상 실행 1점
int main(void)
{
	int x, y, op;
	int result;

	printf("정수 입력값 x : "); scanf_s("%d", &x);
	printf("정수 입력값 y : "); scanf_s("%d", &y);
	printf("연산자(덧셈 1, 뺄셈 2, 곱셈 3, 나눗셈 4, 나머지 5) :  ");
	scanf_s("%d", &op);

	if ((op < 1) || (op > 5)) {
		printf("ERROR: 지원되지 않는 연산자\n");
		return 0;
	} 
	if ((op == 4) || (op == 5)) {
		printf("나누기 또는 나머지 연산 : 나누는 수 0 확인\n");
		if (y == 0){
			printf("ERROR : 나누는 수 0\n");
			return 0;
		}
	else {
			result = my_op(x, y, op);
			printf("연산 결과 = %d\n", result);
		}
	}
	else {
		result = my_op(x, y, op);
		printf("연산 결과 = %d\n", result);
	}
	return 0;
}