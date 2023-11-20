#include "Client_link.h"

// ����ü �����Ϳ� ���� �޸� �Ҵ�, ����ü ���� ����Ʈ, ���� ����Ʈ�� ���� ������

int main(void)
{
	// 1) ����ü �����Ϳ� ���� �޸� �Ҵ�
	
	// ����ü �����Ϳ� malloc() �Լ��� ����Ͽ� ����ü ũ�⸸ŭ(sizeof(struct client_info)) �޸� �Ҵ�

	// ����ü ������ ���� ����
	struct client_info* clientp = NULL;

	// ����ü �����Ϳ� ����ü ũ���� �޸� �Ҵ�, �޸��� ����ü Ÿ�� ����(������ ���꿡 �ʿ�)
	clientp = (struct client_info*)malloc(sizeof(struct client_info)); 

	// �޸� �Ҵ�� ����ü �������� ��� ������ �� ����
	clientp->no = 1;
	strcpy_s(clientp->name, MAX_LEN, "Steve");
	clientp->pamount = 10000;

	// ��� ����ü �����Ϳ� �޸� �Ҵ�
	clientp->birth = (struct date*)malloc(sizeof(struct date));

	// �޸� �Ҵ�� ��� ����ü �������� ��� ������ �� ����
	clientp->birth->year = 2000;
	clientp->birth->month = 12;
	clientp->birth->day = 31;

	// ����ü ������ ��� ������ �� ���
	printf("����ȣ : %d\n", clientp->no);
	printf("���̸� : %s\n", clientp->name);
	printf("���űݾ� : %.2f\n", clientp->pamount);
	printf("�������(YYYY/MM/DD): %d/%d/%d\n\n", clientp->birth->year, clientp->birth->month, clientp->birth->day);
	
	// �����Ϳ� �Ҵ�� �޸� ����, ����� �ݵ�� ����
	free(clientp); 

	// ���� 1 : �� ��ġ���� clientp->no = 1; ��ɹ��� �����ϸ� ��� �ɱ�?
	
	// ���� 2 : ���� �޸� �Ҵ��� ������ �����ΰ�?

	// ���� 3 : ���� �޸𸮴� �� ���� ��� ������ ������ �Ҵ��ϴ°�?

	// ���� 4 : ���� loop ��ɹ����� malloc() �Լ��� ����ϰ� free() �Լ��� ������� ������ � ������ �߻��ϴ°�?


	// 2) �ڱ� ����(self-reference) ����ü ������ : ����ü ��� ������ ����ü �ڽ��� �����Ͱ� ���Ե� ����ü
	// �� : struct client_info_list
	
	// struct client_info_list {
	//		int no;
	//		char name[MAX_LEN];
	//		double pamount;
	//		struct date* birth;
	//		struct client_info_list* next; // �ڱ� ����(self-reference) ������
	// };



	// 3) ����ü ���� ����Ʈ(Linked-List of Structures) 
	
	// �ټ��� ����ü �޸𸮰� �ڱ� ���� �����Ϳ� ���� ����� ����ü ���� --> �ʿ��� ���� ����ü �޸� �Ҵ� �� ����
	
	// �� ����ü ���� ����Ʈ ����

	// ù��° �� ����ü�� ���� ������ ���� ���� : ��� ������
	struct client_info_list* client_head = NULL; 
	
	int num;
	printf("�� �� : ");
	scanf_s("%d", &num);

	// �� ������ �Է��ϴ� ����ü�� ��������ŭ �����ϴ� ����ü ���� ����Ʈ�� ����� ù��° ����ü�� �����͸� ��ȯ�ϴ� �Լ�
	// input_client()�� Client_link_functions.c ���Ͽ� �ۼ�

	printf("\n\n�� ����ŭ �� ���� �Է� : \n\n");
	client_head = input_client(num); // ����ü ���� ����Ʈ�� ���(1��° ����ü�� ���� ������) ��ȯ
	

	// �� ����ü ���� ����Ʈ�� �� �� ������ ����ϴ� output_client()�Լ��� Client_link_functions.c ���Ͽ� �ۼ�
	printf("\n\n�� ��� ���: \n");
	output_client(client_head);


	// 4) ����ü ���� ����Ʈ�� ����(2����) ������ 
	// ������(�ּ�)�� ���� ������ : �Լ����� ȣ������ �����Ͱ� ����Ű�� ����ü ����� �����ϰ��� �� ��
	

	// client_head�� ����ü ���� ����Ʈ�� ���� �� ����ü�� �����Ͽ� �߰��ϴ� �Լ� : add_client()
	// ���� 8 : client_head = NULL�� ���¿��� ������ ���� ȣ���ϸ� � ������ �߻��ϴ°�?

	// �� ���� �߰�
	printf("\n\n������ ���� �� 1�� ���� �߰� : \n");
	client_head = NULL;
	add_client1(client_head);	
	
	// ���� 9 : �Ʒ� ��°��� ���ΰ�? �� ������ �ذ��Ϸ��� ��� �ؾ� �ϴ°�?
	printf("\n\n�� ��� ���� �ּ�(client_head): %p\n", client_head);

	printf("\n\n������ ���� �� �Է� �� �� ��� ��� : \n");
	output_client(client_head);


	// ���� �����͸� ����Ͽ� ����ü ���� ����Ʈ�� ���� �� ����ü�� �����Ͽ� �߰�

	printf("\n\n���� ���� �� 1�� ���� �߰� : \n");
	add_client2(&client_head); // ��� ���� ��츦 ����Ͽ� ��忡 ���� �ּ�(������) ���� ����

	printf("\n\n���� ���� �� �Է� �� �� ��� ��� : \n");
	output_client(client_head);

	printf("\n\n���� �� 3�� ���� �߰� : \n");
	for (int i = 0; i < 3; i++) 
		add_client2(&client_head);

	printf("\n\n���� �� 3�� �Է� �İ� ��� ���: \n");
	output_client(client_head);

	
	char name[MAX_LEN];

	printf("\n\n���� ���̸� �Է�(1��° �̿� ��) : ");
	scanf_s("%s", name, MAX_LEN);
	
	// ���� : client_head ������ ������ ���� �� �̸� ������ ���ڷ� �Ѱܹ޾� �̸��� �����Ǵ� �� ����ü�� 
	// �����ϴ� �Լ�  delete_client()�� �ۼ��Ͻÿ�.

	delete_client(&client_head, name); 

	// �� 1(3��) : ����
	// �� 2(3��) : ���� 4���� �� ������ ����� ���� ����Ʈ���� 1��°�� �ƴ� �� �̸�(name)�� �����Ǵ�
	// ����ü ������ ���� ����Ʈ���� �����ϰ� �� ����� Ȯ���Ͽ� �ش� �� ������ �����Ǿ����� Ȯ���Ͻÿ�.
	
	printf("\n\n1��° �̿��� �� ���� ���� �� �� ��� ��� : \n");
	output_client(client_head);

	printf("\n\n���� ���̸� �Է�(1��° ��) : ");
	scanf_s("%s", name, MAX_LEN);
	delete_client(&client_head, name);

	//�� 3(4��) : 1�� ���� �� ���� 3���� �� ������ ����� ���� ����Ʈ���� 1��° �� �̸�(name)�� �����Ǵ�
	// ����ü ������ ���� ����Ʈ���� �����ϰ� �� ����� Ȯ���Ͽ� �ش� �� ������ �����Ǿ����� Ȯ���Ͻÿ�.
	printf("\n\n1��° �� ���� ���� �� �� ��� ��� : \n");
	output_client(client_head);

}