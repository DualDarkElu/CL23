#include "p11_op.h"

// 문제1 : 아래 프로그램에서 사용하는 my_op() 함수가 값을 반환하지 않고 연산 결과를 함수의 인자로 전달하도록 My_op.c 파일의 함수를 수정하고 \
           main 함수의 함수 호출 관련 부분을 변경하여 동일한 결과가 출력되도록 수정하시오.

int main(int argc, char* argv[]) {
	int x, y, op;
	int result = 0;

	int repeat_num = (argc > 1) ? atoi(argv[1]) : 5;
	//argc가 1 이상 입력될때 사용되고, atoi는 문자열을 정수로 변환한다. 마냑 입력값이 없으면 기본값을 5로 사용한다.
	//
	// 
	// 문제2 : 반복문의 반복횟수를 결정하는 repeat_num 변수값을 프로그램을 실행할 때 외부에서 입력받을 수 있도록 수정하고 \
		             명령줄의 개발자 명령 프롬프트 도구를 사용하여 실행하시오(강의자료 참고).

	for (int i = 0; i < repeat_num; i++)
	{
		printf("연산자 선택(종료 : -1, 덧셈 1, 뺄셈 2, 곱셈 3, 나눗셈 4, 나머지 5, 지수 6, 진수변환 7) :  ");
		scanf_s("%d", &op);
		if (op == -1) break;
		if ((op < 1) || (op > 7)) // 연산자 선택 오류, 다시 선택
		{
			printf("지원하지 않는 연산, 다시 선택하세요!\n");
			continue;
		}
		printf("inut x : ");
		scanf_s("%d", &x);
		printf("inut y : ");
		scanf_s("%d", &y);
		if (op == DECIMAL_CONVERT) {
			// 문제3 : 십진수 x를 y진수로 변환하여 출력하는 함수 decimal_convert(x, y)를 재귀함수 형태로 My_op.c 파일에 정의하고 \
				// 이 위치에서 호출하시오.  함수 호출 외에 나머지 명령문은 이 위치에서 사용하지 마시오. 
			decimal_convert(x, y);
			printf("\n\n");
			continue;
		}
		if (((op == DIVIDE) || (op == REMAINDER)) && (y == 0)) // 나누는 수 0 오류, 실행 종료
		{
			printf("ERROE : 나누는 수 0\n");
			break;
		}
		if (op == EXPONENT)
		{
			result = 1;
			for (int j = 0; j < y; j++)
			{
				int temp_result;
				my_op(result, x, MULTIPLY, &temp_result);
				result = temp_result;
			}
		}
		else
			my_op(x, y, op, &result);
		printf("연산 결과 = %d\n\n", result);
	}

	return 0;
}

