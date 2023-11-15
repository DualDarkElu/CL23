#include "Client.h"

// ����ü ������ �Ű������� ����ϴ� input_client_pointer1() �Լ� �ۼ�
void input_client_pointer1(struct client_info* client1) // ����ü ������ �Ű� ���� ����
{
	// ����ü ������ ������ ��� ���� ���� : -> ������ ���
	printf("����ȣ :");
	scanf_s("%d", &client1->no);
	printf("���̸� :");
	scanf_s("%s", client1->name, MAX_LEN);
	printf("���űݾ� :");
	scanf_s("%lf", &client1->pamount);
	printf("�������(YYYY MM DD) :");
	scanf_s("%d %d %d", &(client1->birth.year), &(client1->birth.month), &(client1->birth.day));
}


void output_client(struct client_info client)
{
	printf("����ȣ : %d\n", client.no);
	printf("���̸� : %s\n", client.name);
	printf("���űݾ� : %.2f\n", client.pamount);
	printf("�������(YYYY/MM/DD): %d/%d/%d\n\n", client.birth.year, client.birth.month, client.birth.day);
}


// ���� 1 : Client.h�� ���ǵ� struct client_info1 ����ü Ÿ������ ���ǵ� client3 ������ �� ������ �Է��ϴ� 
// input_client_pointer2() �Լ��� Client_functions.c �ҽ� ���Ͽ� �ۼ��Ͻÿ�.
void input_client_pointer2(struct client_info1* client1)
{
	// �� ��ġ�� ������ �ڵ带 ä��ÿ�.
	printf("����ȣ :");
	scanf_s("%d", &client1->no);
	printf("���̸� :");
	scanf_s("%s", client1->name, MAX_LEN);
	printf("���űݾ� :");
	scanf_s("%lf", &client1->pamount);
	printf("�������(YYYY MM DD) :");
	scanf_s("%d %d %d", &(client1->birth->year), &(client1->birth->month), &(client1->birth->day));
}


// ���� 2 : Client.h�� ���ǵ� struct client_info1 ����ü Ÿ������ ���ǵ� client3 ������ �� ������ ����ϴ� 
// output_client2() �Լ��� Client_functions.c �ҽ� ���Ͽ� �ۼ��Ͻÿ�.
void output_client2(struct client_info1 client)
{
	// �� ��ġ�� ������ �ڵ带 ä��ÿ�.
	printf("����ȣ : %d\n", client.no);
	printf("���̸� : %s\n", client.name);
	printf("���űݾ� : %.2f\n", client.pamount);
	printf("�������(YYYY/MM/DD): %d/%d/%d\n\n", client.birth->year, client.birth->month, client.birth->day);
}

// ���� 3. Client_functions.c �ҽ� ���Ͽ� ����ü �迭 �Ű� ������ �ۼ��� input_client_all() �Լ��� ����ü ������ �Ű� ������ �����ϰ�
// ����ü ������ ������ ����Ͽ� �����Ͻÿ�.
void input_client_all(struct client_info client[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("����ȣ :");
		scanf_s("%d", &client[i].no);
		printf("���̸� :");
		scanf_s("%s", client[i].name, MAX_LEN);
		printf("���űݾ� :");
		scanf_s("%lf", &client[i].pamount);
		printf("�������(YYYY MM DD) :");
		scanf_s("%d %d %d", &client[i].birth.year, &client[i].birth.month, &client[i].birth.day);
	}
}


// ���� 4. Client_functions.c �ҽ� ���Ͽ� ����ü �迭 �Ű� ������ �ۼ��� output_client_all() �Լ��� ����ü ������ �Ű� ������ �����ϰ�
// ����ü ������ ������ ����Ͽ� �����Ͻÿ�.
void output_client_all(struct client_info client[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("����ȣ : %d\n", client[i].no);
		printf("���̸� : %s\n", client[i].name);
		printf("���űݾ� : %.2f\n", client[i].pamount);
		printf("�������(YYYY/MM/DD): %d/%d/%d\n\n", client[i].birth.year, client[i].birth.month, client[i].birth.day);
	}
}

