#include "Client.h"
#include <stdio.h>

void output_client1(struct client_info1 client)
{
	// ���� 3 :  ����ü ������ Ÿ�� struct client_info1�� Client.h ��� ���Ͽ� �����ϰ� �ּ����� ������ ��
	// output_client() �Լ��� ������ �����ϰ� �ۼ��Ͻÿ�.
	printf("����ȣ: %d\n", client.no);
	printf("���̸�: %s\n", client.name);
	printf("���űݾ�: %.2f\n", client.pamount);
	printf("�������(YYYY/MM/DD): %d/%d/%d\n", client.birth.year, client.birth.month, client.birth.day);
}

struct client_info1 input_client1()
{
	// ���� 4 :  ����ü ������ Ÿ�� struct client_info1�� Client.h ��� ���Ͽ� �����ϰ� �ּ����� ������ ��
	// input_client() �Լ��� ������ �����ϰ� �ۼ��Ͻÿ�.
	struct client_info1 client;
	printf("����ȣ :");
	scanf_s("%d", &client.no);
	printf("���̸� :");
	scanf_s("%s", client.name); 
	printf("���űݾ� :");
	scanf_s("%lf", &client.pamount);
	printf("�������(YYYY MM DD) :");
	scanf_s("%d %d %d", &client.birth.year, &client.birth.month, &client.birth.day);

	return client;
}


