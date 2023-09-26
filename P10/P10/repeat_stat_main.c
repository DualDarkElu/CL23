#include "my_op.h"

// 문제 3 : 아래 프로그램의 문제1의 위치에 x^y(x의 y승)를 구하는 지수 연산을 my_op() 함수 반복 호출 형식으로 작성하되, \
			연산 결과를 result에 대입하도록 작성하시오. y >= 0 조건을 가정한다. 평가 : 충첩 반복문 사용 확인 1점, 지수 연산 정상 계산 1점
// 문제 4 : 문제3을 해결한 후 for 명령문 프로그램을 while 명령문 프로그램으로 변경하시오. 평가 : while 반복문 변경 확인 1점, 연산 실행 확인 1점
// 문제 5 : 문제4를 해결한 후 while 문 부분을 주석 처리하고 do while 명령문으로 변경하시오.  평가 : do while 반복문 변경 확인 1점, 연산 실행 확인 1점
int main(void)
{
	int x, y, op;
	int result = 0;

	/*while (1)
	{
		printf("연산자 선택(종료 : -1, 덧셈 1, 뺄셈 2, 곱셈 3, 나눗셈 4, 나머지 5, 지수 6) :  ");
		scanf_s("%d", &op);
		if (op == -1) break;
		if ((op < 1) || (op > 6)) {// 연산자 선택 오류, 다시 선택
			printf("지원하지 않는 연산, 다시 선택하세요!\n");
			continue;
		}
		printf("정수 입력 x : ");
		scanf_s("%d", &x);
		printf("정수 입력 y : ");
		scanf_s("%d", &y);

		if (((op == 4) || (op == 5)) && (y == 0)) {// 나누는 수 0 오류, 실행 종료
			printf("ERROR : 나누는 수 0\n");
			break;
		}
		else 
		result = my_op(x, y, op);
		printf("연산 결과 = %d\n\n", result);
	}*/

	do {
		printf("연산자 선택(종료 : -1, 덧셈 1, 뺄셈 2, 곱셈 3, 나눗셈 4, 나머지 5, 지수 6) :  ");
		scanf_s("%d", &op);
		if (op == -1) {
			continue;
		}
		if ((op < 1) || (op > 6)) {// 연산자 선택 오류, 다시 선택
			printf("지원하지 않는 연산, 다시 선택하세요!\n");
			continue;
		}
		printf("정수 입력 x : ");
		scanf_s("%d", &x);
		printf("정수 입력 y : ");
		scanf_s("%d", &y);

		if (((op == 4) || (op == 5)) && (y == 0)) {// 나누는 수 0 오류, 실행 종료
			printf("ERROR : 나누는 수 0\n");
			break;
		}
		else
			result = my_op(x, y, op);
		printf("연산 결과 = %d\n\n", result);
	} while (op != -1);


	return 0;
}