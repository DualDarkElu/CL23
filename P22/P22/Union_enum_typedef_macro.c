#include "Client.h"

// ����ü, ������, typedef, ��Ʈ ����ü, �Լ��� ��ũ��
void main()
{
	// (1) ��Ʈ ����ü : ��� ������ ��Ʈ ���� �޸� �Ҵ�, ��Ʈ ���� ������ ó���� ����
	struct Byte_type
	{
		unsigned char first3 : 3; // ������ 3 ��Ʈ
		unsigned char second2 : 2; // ������ 2��Ʈ
		unsigned char third2 : 2; // ������ 2��Ʈ
		unsigned char forth1 : 1; // �ֻ��� ��Ʈ
	} byte;

	byte.first3 = 1;
	byte.second2 = 1;
	byte.third2 = 1;
	byte.forth1 = 1;

	//���� 1 : byte ������ ���� �������� ����ϸ� ����ΰ�? 169
	printf("����Ʈ �� : %d\n", byte);

	// (2) ����ü :  ��ü���� ��� ���� ���� ����
	// ��ü���� ��� ���� ����, ���� ū ��� ���� �޸� ����, ��� ����
	// ��� ���� ���� ��� : ����ü�� ����
	struct id_type 
	{
		long long emp_no; // ��� ��ȣ
		char reg_no[15]; // �ֹ� ��ȣ 
		char pas_no[10]; // ���� ��ȣ
		char dri_no[17]; // �������� ��ȣ
	} id;

	// ���� 2: ����ü�� ����ü�� ���� 8����Ʈ ��� ������ �Ѵ�. sizeof(id)�� ũ��� ���ΰ�? 24
	// ���� 3: ����ü ��� ����ü�� ���������� sizeof(id)�� ũ��� ���ΰ�?  56

	printf("����ü ���� id ũ��: %d\n", sizeof(id)); // 8��Ʈ ����ü ��� ����

	// (3) ����ü : 0���� �����ϴ� �ɺ� ��� ����

	enum type_const { EMP, REG, PAS, DRI }; // EMP = 0, REG = 1, PAS = 2, DRI = 3
	enum type_const type;
	
	printf("EMP : %d\n", EMP);

	printf("�ź��� ����(0-�����, 1-�ֹ���, 2-����, 3-����) :");
	scanf_s("%d", &type);
	printf("�ź��� ���� : %d\n", type);

	switch (type)
	{
		case EMP:
			printf("��� ��ȣ : ");
			scanf_s("%d", &id.emp_no);
			break;
		case REG:
			printf("�ֹ� ��ȣ : ");
			scanf_s("%s", id.reg_no, 15);
			break;
		case PAS:
			printf("���� ��ȣ : ");
			scanf_s("%s", id.pas_no, 10);
			break;
		case DRI:
			printf("��� ��ȣ : ");
			scanf_s("%s", &id.dri_no, 17 );
			break;
	}

	switch (type)
	{
		case EMP:
			printf("��� ��ȣ : %d\n", id.emp_no);
			break;
		case REG:
			printf("�ֹ� ��ȣ : %s\n", id.reg_no);
			break;
		case PAS:
			printf("���� ��ȣ : %s\n", id.pas_no);
			break;
		case DRI:
			printf("���� ��ȣ : %d\n", id.dri_no, 17);
			break;
	}

	// (4) ������ Ÿ�� ������ : typedef
	// ��� ���Ǽ��� ���Ͽ� ������ Ÿ�Կ� �̸��� �ο�, �ּ� ��� ���Ͽ��� ����

	CLIENT *cp; // �����ǵ� ������ Ÿ�� ��� ����ü ���� ����

	cp = (CLIENT *)malloc(sizeof(CLIENT));
	cp->no = 10;
	strcpy_s(cp->name, 20, "Steve");
	cp->pamount = 10000;

	cp->birth = (DATE *)malloc(sizeof(DATE));
	cp->birth->year = 2000;
	cp->birth->month = 12;
	cp->birth->day = 31;


	// ��Ʈ ���� ����ü ���� ����
	BYTE3221 byte1;

	byte1.first3 = 0;
	byte1.second2 = 1;
	byte1.third2 = 2;
	byte1.forth1 = 0;

	printf("����Ʈ1 ��� : %d\n", byte1);

	// ���� 4 : typedef ��ɹ� ����� ������ �����ΰ�?

	// (5) ��ũ�� �Լ� ���� : ����� ���Ǽ��� ���Ͽ� ������ �Լ��� ������ �ǹ��ִ� �Լ��̸��� �Ű������� ��ü
	// �ַ� ��� ���Ͽ� ����

	// #define SQUARE(x) (x * x)

	printf("10^2 : %d\n", SQUARE(10));

	// ���� 5 : ���� ��°��� ���ΰ�? 35
	// ���� 6 : �������� �������� ��µǵ��� �Ϸ��� SQUARE ��ũ�θ� ��� �����ؾ� �ϴ°�? ���θ� �ѹ� �� ���´�
	printf("10^2 : %d\n", SQUARE((5+5)));

	// #define SET_BIT_ON(w, k) ((w) |= (0x0001 << (k))) // // k-��° ���� ��Ʈ�� 1�� ����
	// #define SET_BIT_OFF(w, k) ((w) &= ~(0x0001 << (k))) // k-��° ���� ��Ʈ�� 0���� ����

	// ��ũ�� �Լ� : ��Ʈ ���� ON, OFF
	unsigned short ui = 0;
	SET_BIT_ON(ui, 15);

	// ���� 7 : ���� ��°��� ����ΰ�? 32768
	printf("��Ʈ�� ��� : %d\n", ui);

	SET_BIT_ON(ui, 14);

	// ���� 8 : ���� ��°��� ����ΰ�? 16384
	SET_BIT_OFF(ui, 15);
	printf("��Ʈ�� ��� : %d\n", ui);
	
}