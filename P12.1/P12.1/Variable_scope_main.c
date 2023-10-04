#include "My_op.h"
int sum = 0;
int result = 0;


int main(int argc, char *argv[])
{
	int x, y, op;
	int repeat_limit = 10;
	for (int i = 0; i < repeat_limit; i++)
	{
		printf("연산자 선택(종료 : -1, 덧셈 1, 뺄셈 2, 곱셈 3, 나눗셈 4, 나머지 5, 진수변환 6) :  ");
		scanf_s("%d", &op);
		if (op == -1) break;
		if ((op < 1) || (op > 6)) // 연산자 선택 오류, 다시 선택
		{
			printf("지원하지 않는 연산, 다시 선택하세요!\n");
			continue;
		}
		printf("입력값 x : ");
		scanf_s("%d", &x);
		printf("입력값 y : ");
		scanf_s("%d", &y);
		if (op == DECIMAL_CONVERT) { // 십진수 x를 y진수로 변환
			decimal_convert(x, y); // decimal_convert() 사용자 정의 함수
			printf("\n\n");
			continue;
		}
		if (((op == 4) || (op == 5)) && (y == 0)) // 나누는 수 0 오류, 실행 종료
		{
			printf("ERROE : 나누는 수 0\n");
			break;
		}
		result = my_op(x, y, op); // my_op() 사용자 정의 함수
		printf("my_op 연산 결과 = %d\n\n", result);
		sum += result;
		printf("연산결과 누적 합계 : %d\n", sum);
	}
	return 0;
}