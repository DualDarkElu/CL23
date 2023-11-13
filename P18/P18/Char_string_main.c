#include <stdio.h>
#include <string.h> // ���ڿ� ó�� ���� ǥ�� �Լ� ��� ����


void main(int argc, char* argv[]) // ���� �Լ� ���� : argc, argv
{

	// 1. ���ڿ� ���ǿ� �ʱ�ȭ

	// ���ڿ� ��� : "abcdef"
	// ASCII NULL ����('\0')���� ǥ�� : ���� ���� ���� ���ʿ�
	// ���ڿ� ���� : ���� �迭�� ���� - char ca[20];

	// ���� �迭 �ʱ�ȭ1 : ������ ���ڴ� NULL�� �ʱ�ȭ


	char ca[20] = "abcdef";

	printf("���ڿ� ���1 : ");
	for (int i = 0; ca[i] != '\0'; i++) // ���ڿ� ���� NULL(\0) ����
	{
		printf("%c", ca[i]);
	}

	char* cp = ca;

	printf("\n���ڿ� ���2 : ");
	while (*cp != NULL)
	{
		printf("%c", *cp++);
	}
	printf("\n���ڿ� ��� �Ϸ�\n");

	printf("\n���ڹ迭 ũ�� : %d\n", sizeof(ca)); // 20

	// ���� 1 : sizeof("abcdef")�� ���ΰ�? 
	//"7"
	// ���� 2 : sizeof("�����ٶ󸶹�")�� ���ΰ�?
	//"13"
	//utf-8���� ���ڵ��ϴ� ���� ���ΰ�?
	printf("\n���ڿ�(abcdef) ũ�� : %d\n", sizeof("abcdef"));
	printf("\n���ڿ�(�����ٶ󸶹�) ũ�� : %d\n", sizeof("�����ٶ󸶹�"));


	// ���� �迭 �ʱ�ȭ2 : 
	char cb[] = "abcdef"; // ���ڿ� ��� ũ��� �迭 ũ�� �ڵ� ����

	printf("\n���ڿ� ���3 : ");
	for (int i = 0; cb[i] != '\0'; i++)
	{
		printf("%c", cb[i]);
	}
	printf("\n���ڿ� ��� �Ϸ�\n");

	printf("\n���ڹ迭 ũ�� : %d\n", sizeof(cb));


	// ���� ��� ASCII �ڵ尪 ���
	printf("\n���ڿ� ASCII �ڵ� ���2 : ");
	int i;
	for (i = 0; cb[i] != '\0'; i++)
	{
		printf("%d\n", cb[i]);
	}

	// ���� 3 : ���� �������� cb[i]�� �������� ����ϸ� ���ΰ�? 
	//0
	printf("%d \n", cb[i]); // NULL ���� ���


	// 2. ���� �Է°� ��� �Լ� : getchar(), putchar()
	// ���� �Է� : getchar();

	printf("\n���� �Է�1 :"); // ������ 1���� �Է��Ͻÿ�.
	char c;
	c = getchar(); // ���� �Է� --> ���ۿ� (�Է� ���� + '\n' ����) 2�� ���� ���� --> �Է� ���� 1���� �Է�
	// ���� �Է� : ���� ������ �Է� ���ۿ� �ӽ� �����ϰ� ���۷κ��� �Լ��� ������ ���� ���� �Է�

	// ���� ��� : putchar();

	printf("\n���� ���1 :");
	putchar(c);

	// ���� 4. �Ʒ��� getchar()�� putchar()�� ���� ����� ��� �ɱ�? ������ �����ΰ�?
	// �Է��� ���� �ʰ� ����� ���� �ʴ´�. �̰��� ���� c �� ���� ���ڿ��� ����Ǿ� �ֱ� �����̴�.
	// ���� 5. �Ʒ��� ��ɹ����� ���������� ���� ���ڸ� �Է��ϰ� ����ϰ� �Ϸ��� ��� �����ؾ� �ϴ°�? 
	// c�� ����� ���۸� Ŭ�����ϸ� �ȴ�.
	while ((c = getchar()) != '\n' && c != EOF) {}
	printf("\n���� �Է�2 :");
	c = getchar();
	printf("\n���� ���2 :");
	putchar(c);


	// 3. ���ڿ� �Է°� ���

	// 3.1 getchar()�� putchar() �Լ��� ���ڿ� �����

	printf("\ngetchar() �Լ��� ���ڿ� �Է�1 : ���ڿ� ��ü �Է�\n");
	char temp[10];
	rewind(stdin);

	for (i = 0; i < 5; i++) // ���� 5��(abcde)�� �Ѳ����� �Է��Ͻÿ�.
	{
		temp[i] = getchar();
	}
	temp[i] = '\0';

	printf("\nputchar() �Լ��� ���ڿ� ���1 : \n");
	for (i = 0; temp[i] != '\0'; i++)
	{
		printf("\ttemp[%d] : ", i); // temp[]�� '\n' ���ڵ� ���
		putchar(temp[i]);
	}

	printf("\ngetchar() �Լ��� ���ڿ� �Է�2 : 1���ھ� �Է�\n");
	rewind(stdin);
	char temp2[10];
	for (i = 0; i < 5; i++) // abcde�� ���� 1���� 5�� �Է��Ͻÿ�.
	{
		temp2[i] = getchar();
	}
	temp2[i] = '\0';

	// ���� 6 : temp2[3]�� ���� ���ΰ�?
	//�Է��� ���� �ʾ� ���� �������� �ʴ´�
	printf("\nputchar() �Լ��� ���ڿ� ���2 : \n");
	for (i = 0; temp2[i] != '\0'; i++)
	{
		printf("\ttemp2[%d] : ", i); // temp2[]�� '\n' ���ڵ� ���
		putchar(temp2[i]);
	}

	// 3.2 scanf()�� printf() �Լ��� ���ڿ� �����

	char name[20];

	printf("\n�̸� �Է� : ");
	scanf_s("%s", name, 20); // name : ���� �迭�� �̸�, 20 : �ִ� �Է� ���ڼ�, ���� ����(space)�� ���ڿ� ����, ���� �Է�
	printf("�̸� ��� : %s\n", name);


	// 3.3 gets_s()�� puts() �Լ��� ���ڿ� �����

	// ���� ����(space)�� ���еǴ� �ټ� ���ڿ��� ���� �迭�� �Է� : gets_s();
	char addr[100];
	rewind(stdin);
	printf("�ּ� �Է� :");
	// getchar();
	gets_s(addr, 100); // ���� �Է�, '\n' ���� ��� '\0' ����
	printf("�ּ� ��� : ");
	puts(addr); // ���� �Է�, '\0' ���� ��� '\n' ���
	printf("\n\n");


	// 4. ���ڿ� ó�� ǥ�� �Լ�, ���ڿ��� ������, main �Լ� �Ű�����  

	// 4.1 ���ڿ� ó�� ǥ�� �Լ�

	// ���ڿ� ���� �Լ� : strcpy_s()
	char cc[] = "1234567";
	char cd[10];
	strcpy_s(cd, 10, cc); // cc ���ڿ��� ���ڸ� �ִ� 10������ cd ���ڿ��� ����
	printf("cc : %s, cd : %s\n\n", cc, cd);

	// ���ڿ� �� �Լ� : strcmp(ca, cb)
	// ca > cb�̸� +��(1), ca == cb�̸� 0, ca < cb�̸� -��(-1) ��ȯ
	// ���ڿ� ������ �����Ҷ� �ַ� ���
	char ce[] = "abc";
	char cf[] = "bce";
	char cg[] = "abc";

	printf("strcmp(ce, ce) : % d\n", strcmp(ce, cf));
	printf("strcmp(ce, cg) : %d\n", strcmp(ce, cg));
	printf("strcmp(cf, ce) : %d\n", strcmp(cf, ce));

	// ���ڿ� ���� �Լ� : strlen()
	char cs1[] = "abcdefgh";
	printf("\n���ڿ� ����(abcdefg) : %d\n", strlen(cs1)); // NULL ���� ����\

	char cs2[] = "�����ٶ󸶹ٻ�";
	// ���� 7. strlen(cs2)�� ���� ���ΰ�?
	// 14
	printf("\n���ڿ� ����(�����ٶ󸶹ٻ�) : %d\n", strlen(cs2)); // NULL ���� ����

	// ���� ���ڿ� ���� ��ȯ �Լ� : atoi()

	char str[] = "123";
	printf("���ڿ� 123 ���� ��� : %d\n", str);
	printf("���ڿ� 123 ������ȯ �� ��� : %d\n", atoi(str));


	// 4.2 ���ڿ��� ���� ������

	// ���� �����Ϳ� ���ڿ� ���
	char* cp1 = "abcdef"; // ���ڿ� ����� �ּҸ� cp �����Ϳ� ����
	printf("���ڿ� ��� �ּ� ��� : %p, %p\n", cp1, &"abcdef");
	printf("���ڿ� ��� : %s\n", cp1);
	printf("������ ������ Ȱ���� ���� ��� : \n");
	while (*cp1 != '\0')
		printf("%c\n", *cp1++);


	// ���ڿ� ��� �����Ϳ� ���ڿ� ����
	char* cp2 = "������";
	char* cp3 = "���ٻ�";

	// ���� 8. ���� ��ɹ��� �������� �����ΰ�?
	// ���ڿ� ����� ������ �� ���� �޸𸮿� ����Ǿ� �ִµ� �ű⿡�� �ٸ� ���ڿ��� �����϶�� ��
	// 
	//strcpy_s(cp3, 7, cp2); // ���ڿ� ����� �ٸ� ���ڿ� ���� �Ұ�
	//printf("������ ���ڿ� ��� : %s\n", cp3);

	// ���� 9. ���� ��ɹ��� �������� �����ΰ�?
	// �������� �ʴ� NULL�޸𸮿� ���ڿ��� �����϶�� ��
	// 
	// char* cp4 = NULL;
	// strcpy_s(cp4, 7, cp1); // �ּ� ������ ���ڿ� ���� �Ұ�
	// printf("������ ���ڿ� ��� : %s\n", cp4);

	char temp3[10];
	char* cp4 = temp3;
	strcpy_s(cp4, 7, cp1);

	printf("������ ���ڿ� ��� : %s\n", cp1);
	printf("������ ���ڿ� ��� : %s\n", cp4);


	// 4.3 ���ڿ� ������ �迭

	// char *ca[10] --> ���� ������ ��� ������ 10���� �迭
	char* cap[] = { "abcdef", "������", "123" }; // cap[0] = "abcdef", cap[1] = "������", cap[2] = "123"
	printf("cap[0] : %s, cap[1] : %s, cap[2] : %s\n", cap[0], cap[1], cap[2]);

	// ���ڿ� ������ �迭�� main �Լ� �Ű� ���� : main(int argc, char *argv[])
	 // ���� 10. ������� ����� �Ӽ����� ����� ��� �μ� 100�� �Է��Ͽ���. ���� �� ��¹��� ��°��� ���ΰ�?
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