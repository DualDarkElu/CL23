#include <stdio.h>

int main(int argc, char* argv[])
{
	int a; float f;
	int output, output1; float f_output;
	// 1) 대입 연산(데이터 타입 변환 유의)
	a = 3.14 + 1;
	f = 3.14 + 1;

	printf("int 변수에 (3.14+1) 대입 결과 : %d\n\n", a);
	printf("float 변수에 (3.14+1) 대입 결과 : %0.2f\n\n", f);
	printf("float 변수에 (3.14+1) 대입 결과 정수(d) 형식 출력: %d\n\n", f);

	// 2) 산술 연산 (정수 나눗셈 연산 유의)
	printf("10/4 : %d, 10/4.0 : %0.1f, 10%%3 : %d\n\n", 10 / 4, 10 / 4.0, 10 % 3);

	// 3) 증감 연산자(전위 후위 연산 순서 유의)
	int x, y1, y2;
	x = 10;
	y1 = (1 + ++x) + 10;
	y2 = (1 + x++) + 10;
	printf("전위 증가연산 결과 : %d, 후위 증가연산 결과 : %d\n\n", y1, y2);
	x = 10;
	y2 = (1 + ++x) + 10 + x++;
	printf("전위 및 후위 증가연산 후 변수 x 결과 : %d, y2 결과 : %d\n", x, y2); // 12, 33
	x = 10;
	y2 = (1 + x++) + 10 + x++;
	printf("전위 및 후위 증가연산 후 변수 x 결과 : %d, y2 결과 : %d\n\n", x, y2); // 12, 31

	// 4) 복합 대입 연산자
	int x1, y11, y22;
	x1 = 10; y11 = 21; y22 = 22;
	x1 += 100;
	y11 /= 10;
	y22 %= 10;
	printf("x1 += 100 : %d, y11 /= 10 : %d, y22 %%= 10 ; %d\n\n", x1, y11, y22); // 110, 2, 2

	// 5) 관계 연산자(관계 연산자 결합 유의)
	int c1, c2, c3, c4;
	c1 = 100 > 200, c2 = 100 == 200, c3 = 100 != 200, c4 = 100 < 200; // True : 1, False : 0
	printf(" 100 > 200 : %d, 100 == 200 : %d, 100 != 200 : %d, 100 < 200 : %d\n\n", c1, c2, c3, c4); // 0, 0, 1, 1

	c1 = 100;
	// c2 = 10 < c1 < 20; // 좌에서 우로 연산 결합
	c2 = (10 < c1 < 20) && (101 > c1 > 20); // 0
	c3 = (10 < c1) && (c1 > 20); // 1
	printf("c2 : %d, c3 :%d\n", c2, c3);

	// 5) 논리 연산자(비트 논리 연산자와 구분 유의)
	int age, height, result1, result2;
	age = 30, height = 170;
	result1 = (20 < age) && (170 < height);
	printf("&& result : %d\n", result1);
	result1 = (20 < age) || (170 < height);
	printf("|| result : %d\n", result1);
	result2 = (20 < age) && !(170 < height);
	printf("&& result : %d\n", result2);

	// 6) 조건 연산자
	int i, j, max;
	i = 300, j = 200;
	max = (i > j) ? i : j;
	printf("max : %d\n", max);

	// 7) 비트 논리 연산자
	unsigned short ua, ub, uc, ud, ue, uf, ug, uh, ui, output2;
	ua = 65535; // 0xFFFF
	ub = 255; // 0x00FF
	uc = ua & ub;
	printf("FFFF & 0x00FF : %04x\n", uc);

	ud = ua | ub;
	printf("FFFF | 0x00FF : %04x\n", ud);

	ue = ua ^ ub;
	printf("FFFF ^ 0x00FF : %04x\n", ue);

	uf = ub ^ ub;
	printf("FFFF ^ 0xFFFF : %04x\n", uf);

	ug = ub ^ 0;
	printf("00FF ^ 0x0000 : %04x\n", uc);

	uh = ~ub;
	printf("~00FF : %04x\n", uh);
	output2 = (uc & ud) | (ud ^ uf) & (ug ^ uh);
	printf("output2 : %04x\n", output2);

	// 8) 이동(shift) 연산자(부호 비트 채움 유의)
	short sa, sb, sc, sd, output3;
	sa = 17; // ...0111
	sb = sa << 5;
	printf(" 7 << 4 : %d\n", sb); // ..01110000

	sb = sb >> 2;
	printf(" 7 >> 2 : %d\n", sb);

	sc = -7; // 1111111111111001
	sd = sc << 4; // 1111111110010000 --> 1110000 ==> 64 + 32 + 16 = 112(-1)

	printf(" -7 << 4 : %d\n", sd);

	sd = sd >> 2; // 1111111111111110
	sd = sb + sd;
	printf(" -7 >> 2 : %d\n", sd); // ...10 --> 2(-)	

	// 9) 연산자 우선 순위

	int p1 = 3, p2 = 3, p3 = 7, p4 = 9;
	int result3;

	result3 = (p1 < p2++ || p1 + 5 > p3 && p3 < p4 - 2) * 7 ^ 8;
	printf("연산 우선순위 확인 result3: %d\n", result3);

	return 0;
}