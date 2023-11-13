#include "Client.h"

struct date {
	int year;
	int month;
	int day;
};


// ���� ����ü ��� ������ ������ ����ü ������ Ÿ�� ����
struct client_info1 { // ����ü ������ Ÿ�� �̸� : struct client_info1
	int no;
	char name[MAX_LEN];
	double pamount;
	struct date birth; // struct date ����ü ��� ���� ����
};

void output_client(struct client_info1 client)
{
	// ���� 1 : ����ü ������ Ÿ�� struct client_info1�� ���� ����ü Ÿ������ �����ϰ� �ּ����� ������ ��
	//  �Լ� ���θ� �����ϰ� �ۼ��Ͻÿ�.
	printf("����ȣ : %d\n", client.no);
	printf("���̸� : %s\n", client.name);
	printf("���űݾ� : %.2f\n", client.pamount);
	printf("�������(YYYY/MM/DD): %d/%d/%d\n\n", client.birth.year, client.birth.month, client.birth.day);
}


struct client_info1 input_client() // ��ȯ���� Ÿ�� : struct client_info1
{
	// ���� 2 : ����ü ������ Ÿ�� struct client_info1�� ���� ����ü Ÿ������ �����ϰ� �ּ����� ������ ��
	//  �Լ� ���θ� �����ϰ� �ۼ��Ͻÿ�.
	struct client_info1 client;
	printf("����ȣ : ");
	scanf_s("%d", &client.no);
	printf("���̸� : ");
	scanf_s("%s", client.name);
	printf("���űݾ� : ");
	scanf_s("%lf", &client.pamount);
	printf("�������(YYYY MM DD) : ");
	scanf_s("%d %d %d", &client.birth.year, &client.birth.month, &client.birth.day);

	return client;
}

void main(void)
{

	// 1. ����ü ������ Ÿ�� ���ǿ� ����ü ���� ����
	
	// 1.1 ���� ����ü ������ Ÿ�� ���ǿ� ���� ����

	struct client_info { // ����ü ������ Ÿ�� Ű���� : struct, ����ü ������ Ÿ�� �̸� : client_info
		int no; // ����, int Ÿ�� ��� ����
		char name[MAX_LEN]; // �� �̸�, ���� �迭 ��� ����
		double pamount; // ���� �ݾ�, double Ÿ�� ��� ����
		int year; // ����, int Ÿ�� ��� ����
		int month; // ����, int Ÿ�� ��� ����
		int day; // ����, int Ÿ�� ��� ����
	};
	// ���� 1. ����ü ������ Ÿ���� ������ �����ϴ°�?
	// ���� 2. struct client_info ���� ����ü Ÿ���� ���� ������ ����ΰ�?

	// ����ü ���� ����� Ȱ��
	struct client_info client; // ����ü ���� ���� ����
	// ���� 3. ����ü ������ Ÿ�԰� ����ü ������ ��� �ٸ���?

	// ����ü ��� ���� ���� : ����ü����.�������

	// �� ���� �Է�
	printf("\n�ܼ� ����ü�� ���� �� ���� �Է� :\n");
	printf("����ȣ :");
	scanf_s("%d", &client.no);
	printf("���̸� :");
	scanf_s("%s", client.name, MAX_LEN);
	printf("���űݾ� :");
	scanf_s("%lf", &client.pamount);
	printf("�������(YYYY MM DD) :");
	scanf_s("%d %d %d", &client.year, &client.month, &client.day);

	// �� ���� ���
	printf("\n�ܼ� ����ü�� ���� �� ���� ��� :\n");
	printf("\n�� ���� ��� :\n");
	printf("����ȣ : %d\n", client.no);
	printf("���̸� : %s\n", client.name);
	printf("���űݾ� : %.2f\n", client.pamount);
	printf("�������(YYYY/MM/DD): %d/%d/%d\n\n", client.year, client.month, client.day);
	// ���� 4. ����ü ��� ������ ��� �����ϴ°�?

	/*
	// ���� ����ü ������ Ÿ�� ���ǿ� ���� ������ �ϳ��� ��ɹ����� ����
	struct client_info { 
		int no; // ��� ����
		char name[MAX_LEN];
		double pamount;
		int year;
		int month;
		int day;
	} client; // ����ü ���� ����

	// �̸� ���� ����ü ������ Ÿ�� ���� ����
	struct { 
		int no; // ��� ����
		char name[MAX_LEN];
		double pamount;
		int year;
		int month;
		int day;
	} client; // ����ü ���� ����
	*/

	// 1.2 ����ü ��� ������ ������ ����ü ������ Ÿ�� ���ǿ� ���� ����

	struct client_info1 client1; // ����ü ���� ����

	// ����ü ��� ���� ���� : ����ü����.����ü�������.�������
	printf("\n����ü ��� ������ ������ ����ü�� ���� �� ���� �Է� :\n");
	printf("����ȣ :");
	scanf_s("%d", &client1.no);
	printf("���̸� :");
	scanf_s("%s", client1.name, MAX_LEN);
	printf("���űݾ� :");
	scanf_s("%lf", &client1.pamount);
	printf("�������(YYYY MM DD) :");
	scanf_s("%d %d %d", &client1.birth.year, &client1.birth.month, &client1.birth.day);
	// ���� 5. ����ü ��� ������ ��� ������ ��� �����ϴ°�?

	// ����ü ��� ���� ���� : �� ���� ���
	printf("\n����ü ��� ������ ������ ����ü�� ���� �� ���� ��� :\n");
	printf("����ȣ : %d\n", client1.no);
	printf("���̸� : %s\n", client1.name);
	printf("���űݾ� : %.2f\n", client1.pamount);
	printf("�������(YYYY/MM/DD): %d/%d/%d\n\n", client1.birth.year, client1.birth.month, client1.birth.day);
	

	// 2. ����ü�� �Լ� : ���� ����ü Ÿ�� ���� ����
	
	// ���� 6. �ϳ��� ����ü ������ Ÿ���� ���� �ҽ� ������ 2�� �̻��� �Լ����� ����Ϸ��� ����ü ������ Ÿ���� ��� �����ؾ� �ϴ°�?
	
	// ���� 1 : ����ü ������ Ÿ�� struct client_info1�� �� ���Ͽ��� ���� ����ü Ÿ������ �����ϰ� �ּ����� ������ ��
	//  main() �Լ� �Ʒ��� output_client() �Լ��� �����ϰ� �ۼ��Ͻÿ�.
	
	
	// ����ü ������ �Լ� ���ڷ� ���� 
	printf("\n���� �ҽ� ���� �Լ��� ���� �� ���� ��� :\n");
	output_client(client1); 
	// ���� 7. ����ü ���� �Լ� ���� ���ް� �迭 �̸� �Լ� ���� ������ ��� �ٸ���?
	

	
	// ���� 2 : ����ü ������ Ÿ�� struct client_info1�� �� ���Ͽ��� ���� ����ü Ÿ������ �����ϰ� �ּ����� ������ ��
	//  main() �Լ� �Ʒ��� input_client() �Լ��� �����ϰ� �ۼ��Ͻÿ�.

	
	struct client_info1 client2;
	printf("\n���� �ҽ� ���� �Լ��� ���� �� ���� �Է� :\n");
	client2 = input_client(); // ����ü ���� ��ȯ �� ����

	printf("\n���� �ҽ� ���� �Լ��� ���� �� ���� ��� :\n");
	output_client(client2); // ����ü ���� ����
	


	// ���� 8. �ϳ��� ����ü ������ Ÿ���� 2�� �̻��� �ҽ� ���Ͽ��� ����Ϸ��� ����ü ������ Ÿ���� ��� �����ؾ� �ϴ°�?
	
	// ���� 3 :  ����ü ������ Ÿ�� struct client_info1�� Client.h ��� ���Ͽ� �����ϰ� �ּ����� ������ ��
	// output_client() �Լ��� Client_functions.c �ҽ� ���Ͽ� �����ϰ� �ۼ��Ͻÿ�.
	
	/*
	// ����ü ������ �Լ� ���ڷ� ����
	printf("\n��� ���Ͽ� ���ǵ� ����ü Ÿ���� ����ϴ� ��Ƽ �ҽ� ���� �Լ��� ���� �� ���� ��� :\n");	
	output_client(client1);
	*/


	// ���� 4 :  ����ü ������ Ÿ�� struct client_info1�� Client.h ��� ���Ͽ� �����ϰ� �ּ����� ������ ��
	// input_client() �Լ��� Client_functions.c �ҽ� ���Ͽ� �����ϰ� �ۼ��Ͻÿ�.

	/*
	struct client_info1 client3;
	printf("\n��� ���Ͽ� ���ǵ� ����ü Ÿ���� ����ϴ� ��Ƽ �ҽ� ���� �Լ��� ���� �� ���� �Է� :\n");
	
	client3 = input_client1();

	printf("\n��� ���Ͽ� ���ǵ� ����ü Ÿ���� ����ϴ� ��Ƽ �ҽ� ���� �Լ��� ���� �� ���� ��� :\n");	
	output_client1(client3);
	*/
}




