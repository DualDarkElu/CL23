#include "Client.h"

// 공용체, 열거형, typedef, 비트 구조체, 함수형 매크로
void main()
{
	// (1) 비트 구조체 : 멤버 변수에 비트 단위 메모리 할당, 비트 단위 데이터 처리에 유용
	struct Byte_type
	{
		unsigned char first3 : 3; // 최하위 3 비트
		unsigned char second2 : 2; // 차하위 2비트
		unsigned char third2 : 2; // 차상위 2비트
		unsigned char forth1 : 1; // 최상위 비트
	} byte;

	byte.first3 = 1;
	byte.second2 = 1;
	byte.third2 = 1;
	byte.forth1 = 1;

	//질문 1 : byte 변수의 값을 십진수로 출력하면 얼머인가? 169
	printf("바이트 값 : %d\n", byte);

	// (2) 공용체 :  대체가능 멤버 변수 연합 정의
	// 대체가능 멤버 변수 연합, 가장 큰 멤버 변수 메모리 공유, 멤버 정렬
	// 멤버 변수 접근 방식 : 구조체와 동일
	struct id_type 
	{
		long long emp_no; // 사원 번호
		char reg_no[15]; // 주민 번호 
		char pas_no[10]; // 여권 번호
		char dri_no[17]; // 운전면허 번호
	} id;

	// 질문 2: 공용체로 구조체와 같이 8비이트 멤버 정렬을 한다. sizeof(id)의 크기는 얼마인가? 24
	// 질문 3: 공용체 대신 구조체로 정의했을때 sizeof(id)의 크기는 얼마인가?  56

	printf("공용체 변수 id 크기: %d\n", sizeof(id)); // 8비트 공용체 멤버 정렬

	// (3) 열거체 : 0부터 시작하는 심볼 상수 정의

	enum type_const { EMP, REG, PAS, DRI }; // EMP = 0, REG = 1, PAS = 2, DRI = 3
	enum type_const type;
	
	printf("EMP : %d\n", EMP);

	printf("신분증 종류(0-사원증, 1-주민증, 2-여권, 3-운전) :");
	scanf_s("%d", &type);
	printf("신분증 종류 : %d\n", type);

	switch (type)
	{
		case EMP:
			printf("사원 번호 : ");
			scanf_s("%d", &id.emp_no);
			break;
		case REG:
			printf("주민 번호 : ");
			scanf_s("%s", id.reg_no, 15);
			break;
		case PAS:
			printf("여권 번호 : ");
			scanf_s("%s", id.pas_no, 10);
			break;
		case DRI:
			printf("사원 번호 : ");
			scanf_s("%s", &id.dri_no, 17 );
			break;
	}

	switch (type)
	{
		case EMP:
			printf("사원 번호 : %d\n", id.emp_no);
			break;
		case REG:
			printf("주민 번호 : %s\n", id.reg_no);
			break;
		case PAS:
			printf("여권 번호 : %s\n", id.pas_no);
			break;
		case DRI:
			printf("운전 번호 : %d\n", id.dri_no, 17);
			break;
	}

	// (4) 데이터 타입 재정의 : typedef
	// 사용 편의성을 위하여 데이터 타입에 이름을 부여, 주소 헤더 파일에서 정의

	CLIENT *cp; // 재정의된 데이터 타입 사용 구조체 변수 정의

	cp = (CLIENT *)malloc(sizeof(CLIENT));
	cp->no = 10;
	strcpy_s(cp->name, 20, "Steve");
	cp->pamount = 10000;

	cp->birth = (DATE *)malloc(sizeof(DATE));
	cp->birth->year = 2000;
	cp->birth->month = 12;
	cp->birth->day = 31;


	// 비트 단위 구조체 변수 정의
	BYTE3221 byte1;

	byte1.first3 = 0;
	byte1.second2 = 1;
	byte1.third2 = 2;
	byte1.forth1 = 0;

	printf("바이트1 출력 : %d\n", byte1);

	// 질문 4 : typedef 명령문 사용의 장점은 무엇인가?

	// (5) 매크로 함수 정의 : 사용의 편의성을 위하여 복잡한 함수형 수식을 의미있는 함수이름과 매개변수로 대체
	// 주로 헤더 파일에 정의

	// #define SQUARE(x) (x * x)

	printf("10^2 : %d\n", SQUARE(10));

	// 질문 5 : 다음 출력값은 얼마인가? 35
	// 질문 6 : 정상적인 제곱값이 출력되도록 하려면 SQUARE 매크로를 어떻게 정의해야 하는가? 가로를 한번 더 놓는다
	printf("10^2 : %d\n", SQUARE((5+5)));

	// #define SET_BIT_ON(w, k) ((w) |= (0x0001 << (k))) // // k-번째 상위 비트를 1로 설정
	// #define SET_BIT_OFF(w, k) ((w) &= ~(0x0001 << (k))) // k-번째 상위 비트를 0으로 설정

	// 매크로 함수 : 비트 단위 ON, OFF
	unsigned short ui = 0;
	SET_BIT_ON(ui, 15);

	// 질문 7 : 다음 출력값은 얼머인가? 32768
	printf("비트값 출력 : %d\n", ui);

	SET_BIT_ON(ui, 14);

	// 질문 8 : 다음 출력값은 얼머인가? 16384
	SET_BIT_OFF(ui, 15);
	printf("비트값 출력 : %d\n", ui);
	
}