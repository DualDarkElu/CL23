#include <stdio.h>
#include <string.h> // 문자열 처리 관련 표준 함수 헤더 파일


void main(int argc, char* argv[]) // 메인 함수 인자 : argc, argv
{

	// 1. 문자열 정의와 초기화

	// 문자열 상수 : "abcdef"
	// ASCII NULL 문자('\0')끝을 표시 : 문자 갯수 정보 불필요
	// 문자열 저장 : 문자 배열에 저장 - char ca[20];

	// 문자 배열 초기화1 : 나머지 문자는 NULL로 초기화


	char ca[20] = "abcdef";

	printf("문자열 출력1 : ");
	for (int i = 0; ca[i] != '\0'; i++) // 문자열 끝에 NULL(\0) 존재
	{
		printf("%c", ca[i]);
	}

	char* cp = ca;

	printf("\n문자열 출력2 : ");
	while (*cp != NULL)
	{
		printf("%c", *cp++);
	}
	printf("\n문자열 출력 완료\n");

	printf("\n문자배열 크기 : %d\n", sizeof(ca)); // 20

	// 질문 1 : sizeof("abcdef")은 얼마인가? 
	//"7"
	// 질문 2 : sizeof("가나다라마바")은 얼마인가?
	//"13"
	//utf-8으로 인코딩하는 경우는 얼마인가?
	printf("\n문자열(abcdef) 크기 : %d\n", sizeof("abcdef"));
	printf("\n문자열(가나다라마바) 크기 : %d\n", sizeof("가나다라마바"));


	// 문자 배열 초기화2 : 
	char cb[] = "abcdef"; // 문자열 상수 크기로 배열 크기 자동 설정

	printf("\n문자열 출력3 : ");
	for (int i = 0; cb[i] != '\0'; i++)
	{
		printf("%c", cb[i]);
	}
	printf("\n문자열 출력 완료\n");

	printf("\n문자배열 크기 : %d\n", sizeof(cb));


	// 문자 대신 ASCII 코드값 출력
	printf("\n문자열 ASCII 코드 출력2 : ");
	int i;
	for (i = 0; cb[i] != '\0'; i++)
	{
		printf("%d\n", cb[i]);
	}

	// 질문 3 : 현재 시점에서 cb[i]를 십진수로 출력하면 얼마인가? 
	//0
	printf("%d \n", cb[i]); // NULL 문자 출력


	// 2. 문자 입력과 출력 함수 : getchar(), putchar()
	// 문자 입력 : getchar();

	printf("\n문자 입력1 :"); // 영문자 1개를 입력하시오.
	char c;
	c = getchar(); // 버퍼 입력 --> 버퍼에 (입력 문자 + '\n' 문자) 2개 문자 저장 --> 입력 문자 1개만 입력
	// 버퍼 입력 : 라인 단위로 입력 버퍼에 임시 저장하고 버퍼로부터 함수가 정해진 수의 문자 입력

	// 문자 출력 : putchar();

	printf("\n문자 출력1 :");
	putchar(c);

	// 질문 4. 아래의 getchar()와 putchar()의 실행 결과는 어떻게 될까? 이유는 무엇인가?
	// 입력을 받지 않고 출력을 하지 않는다. 이것은 변수 c 에 아직 문자열이 저장되어 있기 때문이다.
	// 질문 5. 아래의 명령문들이 정상적으로 다음 문자를 입력하고 출력하게 하려면 어떻게 수정해야 하는가? 
	// c에 저장된 버퍼를 클리어하면 된다.
	while ((c = getchar()) != '\n' && c != EOF) {}
	printf("\n문자 입력2 :");
	c = getchar();
	printf("\n문자 출력2 :");
	putchar(c);


	// 3. 문자열 입력과 출력

	// 3.1 getchar()와 putchar() 함수로 문자열 입출력

	printf("\ngetchar() 함수로 문자열 입력1 : 문자열 전체 입력\n");
	char temp[10];
	rewind(stdin);

	for (i = 0; i < 5; i++) // 문자 5개(abcde)를 한꺼번에 입력하시오.
	{
		temp[i] = getchar();
	}
	temp[i] = '\0';

	printf("\nputchar() 함수로 문자열 출력1 : \n");
	for (i = 0; temp[i] != '\0'; i++)
	{
		printf("\ttemp[%d] : ", i); // temp[]의 '\n' 문자도 출력
		putchar(temp[i]);
	}

	printf("\ngetchar() 함수로 문자열 입력2 : 1문자씩 입력\n");
	rewind(stdin);
	char temp2[10];
	for (i = 0; i < 5; i++) // abcde를 문자 1개씩 5번 입력하시오.
	{
		temp2[i] = getchar();
	}
	temp2[i] = '\0';

	// 질문 6 : temp2[3]의 값은 얼마인가?
	//입력을 받지 않아 값이 존재하지 않는다
	printf("\nputchar() 함수로 문자열 출력2 : \n");
	for (i = 0; temp2[i] != '\0'; i++)
	{
		printf("\ttemp2[%d] : ", i); // temp2[]의 '\n' 문자도 출력
		putchar(temp2[i]);
	}

	// 3.2 scanf()와 printf() 함수로 문자열 입출력

	char name[20];

	printf("\n이름 입력 : ");
	scanf_s("%s", name, 20); // name : 문자 배열의 이름, 20 : 최대 입력 문자수, 공백 문자(space)로 문자열 구분, 버퍼 입력
	printf("이름 출력 : %s\n", name);


	// 3.3 gets_s()와 puts() 함수로 문자열 입출력

	// 공백 문자(space)로 구분되는 다수 문자열을 문자 배열로 입력 : gets_s();
	char addr[100];
	rewind(stdin);
	printf("주소 입력 :");
	// getchar();
	gets_s(addr, 100); // 버퍼 입력, '\n' 문자 대신 '\0' 저장
	printf("주소 출력 : ");
	puts(addr); // 버퍼 입력, '\0' 문자 대신 '\n' 출력
	printf("\n\n");


	// 4. 문자열 처리 표준 함수, 문자열과 포인터, main 함수 매개변수  

	// 4.1 문자열 처리 표준 함수

	// 문자열 복제 함수 : strcpy_s()
	char cc[] = "1234567";
	char cd[10];
	strcpy_s(cd, 10, cc); // cc 문자열의 문자를 최대 10개까지 cd 문자열에 복제
	printf("cc : %s, cd : %s\n\n", cc, cd);

	// 문자열 비교 함수 : strcmp(ca, cb)
	// ca > cb이면 +값(1), ca == cb이면 0, ca < cb이면 -값(-1) 반환
	// 문자열 단위로 정렬할때 주로 사용
	char ce[] = "abc";
	char cf[] = "bce";
	char cg[] = "abc";

	printf("strcmp(ce, ce) : % d\n", strcmp(ce, cf));
	printf("strcmp(ce, cg) : %d\n", strcmp(ce, cg));
	printf("strcmp(cf, ce) : %d\n", strcmp(cf, ce));

	// 문자열 길이 함수 : strlen()
	char cs1[] = "abcdefgh";
	printf("\n문자열 길이(abcdefg) : %d\n", strlen(cs1)); // NULL 문자 제외\

	char cs2[] = "가나다라마바사";
	// 질문 7. strlen(cs2)의 값은 얼마인가?
	// 14
	printf("\n문자열 길이(가나다라마바사) : %d\n", strlen(cs2)); // NULL 문자 제외

	// 숫자 문자열 정수 변환 함수 : atoi()

	char str[] = "123";
	printf("문자열 123 정수 출력 : %d\n", str);
	printf("문자열 123 정수변환 후 출력 : %d\n", atoi(str));


	// 4.2 문자열과 문자 포인터

	// 문자 포인터와 문자열 상수
	char* cp1 = "abcdef"; // 문자열 상수의 주소를 cp 포인터에 대입
	printf("문자열 상수 주소 출력 : %p, %p\n", cp1, &"abcdef");
	printf("문자열 출력 : %s\n", cp1);
	printf("포인터 연산을 활용한 문자 출력 : \n");
	while (*cp1 != '\0')
		printf("%c\n", *cp1++);


	// 문자열 상수 포인터에 문자열 복제
	char* cp2 = "가나다";
	char* cp3 = "마바사";

	// 질문 8. 다음 명령문의 문제점은 무엇인가?
	// 문자열 상수는 수정할 수 없는 메모리에 저장되어 있는데 거기에다 다른 문자열을 저장하라고 함
	// 
	//strcpy_s(cp3, 7, cp2); // 문자열 상수에 다른 문자열 복제 불가
	//printf("복제후 문자열 출력 : %s\n", cp3);

	// 질문 9. 다음 명령문의 문제점은 무엇인가?
	// 존재하지 않는 NULL메모리에 문자열을 저장하라고 함
	// 
	// char* cp4 = NULL;
	// strcpy_s(cp4, 7, cp1); // 주소 변수에 문자열 복제 불가
	// printf("복제후 문자열 출력 : %s\n", cp4);

	char temp3[10];
	char* cp4 = temp3;
	strcpy_s(cp4, 7, cp1);

	printf("복제전 문자열 출력 : %s\n", cp1);
	printf("복제후 문자열 출력 : %s\n", cp4);


	// 4.3 문자열 포인터 배열

	// char *ca[10] --> 문자 포인터 요소 변수가 10개인 배열
	char* cap[] = { "abcdef", "가나다", "123" }; // cap[0] = "abcdef", cap[1] = "가나다", cap[2] = "123"
	printf("cap[0] : %s, cap[1] : %s, cap[2] : %s\n", cap[0], cap[1], cap[2]);

	// 문자열 포인터 배열과 main 함수 매개 변수 : main(int argc, char *argv[])
	 // 질문 10. 디버그의 디버그 속성에서 디버깅 명령 인수 100을 입력하였다. 다음 각 출력문의 출력값은 얼마인가?
	//argc : 2
	//argv[0] : C:\Users\admin\Downloads\Project1\Debug\Project1.exe
	//argv[1] : "100"
	//argv[1] : 909811286
	//argv[1] : 100
	printf("argc : %d\n", argc);
	printf("argv[0] : %s\n", argv[0]);
	printf("argv[1] : %s\n", argv[1]);

	printf("argv[1] : %d\n", argv[1]);
	printf("argv[1] : %d\n", atoi(argv[1]));

}