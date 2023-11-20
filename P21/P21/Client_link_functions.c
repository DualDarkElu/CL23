#include "Client_link.h"

// �� ���� ����ü ���� ����Ʈ ���� �� ù��° ����ü�� ���� ����Ʈ(���) ��ȯ
struct client_info_list* input_client(int num)
{
	struct client_info_list* head = NULL;
	struct client_info_list* current, * previous = NULL;
	
	// ù��° ����ü ������(head)�� ����ü �޸� �Ҵ�
	head = (struct client_info_list*)malloc(sizeof(struct client_info_list)); 

	// ���� ������(current)�� head ������ ����
	// ��� �����ʹ� ������� ����, ���� ����ü �����͸� �̵���Ű�鼭 ���� ����ü ����
	current = head; 

	// �ű� ����ü�� ���� �����ʹ� �׻� NULL : ���� ����Ʈ�� ������ ǥ��
	current->next = NULL; 

	for(int i = 0; i < num; i++)
	{
		// �� ����ü�� �� ���� �Է�
		printf("����ȣ :");
		scanf_s("%d%*c", &current->no);
		printf("���̸� :");
		scanf_s("%s", current->name, MAX_LEN);
		printf("���űݾ� :");
		scanf_s("%lf", &current->pamount);
		current->birth = (struct date*)malloc(sizeof(struct date));
		printf("�������(YYYY MM DD) :");
		scanf_s("%d %d %d", &current->birth->year, &current->birth->month, &current->birth->day);
	
		// ���� �� ������ ������ ����ü �޸𸮸� �Ҵ��ϰ� ���� ����ü�� ������ ����
		current->next = (struct client_info_list*)malloc(sizeof(struct client_info_list));

		// ���� ����ü ������(current)�� ���� ������(previous)�� �̵��ϰ� ���� �����͸� ���� ����ü�� �̵����� ���� �� ���� �Է�
		previous = current;
		current = current->next;
	}

	// �� ������ �Էµ��� ���� ������ ����ü �޸� ����
	free(current); 
	//���� 5 : ���� free() ��ɹ��� �����ϴ� ��� � ������ �߻��ϴ°�?

	// ���� ����ü�� ���� �����Ϳ� NULL�� �����Ͽ� ����ü ���� ����Ʈ�� �� ǥ��
	previous->next = NULL; 
	//���� 6 : ���� ���� ��ɹ��� �����ϴ� ��� � ������ �߻��ϴ°�?

	return(head); // �� ���� ����ü ����Ʈ�� ���� �ּ�(��� ������) ��ȯ
}

void output_client(struct client_info_list *current)
{
	// ���� �����Ͱ� NULL�� �ɶ����� �� ���� ���
	while(current!= NULL)
	{
		printf("����ȣ : %d\n", current->no);
		printf("���̸� : %s\n", current->name);
		printf("���űݾ� : %.2f\n", current->pamount);
		printf("�������(YYYY/MM/DD): %d/%d/%d\n\n", current->birth->year, current->birth->month, current->birth->day);

		// ���� �����͸� ���� ����ü�� �̵�(������ ����ü�� ���� �����ʹ� NULL�� �����Ǿ� ����)
		current = current->next;
	}
}

void add_client1(struct client_info_list* headp)
{
	struct client_info_list* current = NULL;

	if (headp == NULL) //ù��° �� ���� �Է� --> ���� ����Ʈ ��� ����(NULL --> 1��° ����ü)
	{
		headp = (struct client_info_list*)malloc(sizeof(struct client_info_list));
		
		printf("����ȣ :");
		scanf_s("%d%*c", &headp->no);
		printf("���̸� :");
		scanf_s("%s", headp->name, MAX_LEN);
		printf("���űݾ� :");
		scanf_s("%lf", &headp->pamount);
		headp->birth = (struct date*)malloc(sizeof(struct date));
		printf("�������(YYYY MM DD) :");
		scanf_s("%d %d %d", &headp->birth->year, &headp->birth->month, &headp->birth->day);
		headp->next = NULL; // ������ ����ü�� ���� �����ʹ� �׻� NULL : ���� ����Ʈ�� ������ ǥ��
	}
	else // ��� ���� ����
	{
		current = headp;
		while (current->next != NULL) // while (current != NULL) ���� ���� : NULL->next ����
			current = current->next;
		current->next = (struct client_info_list*)malloc(sizeof(struct client_info_list));
		current = current->next;
		printf("����ȣ :");
		scanf_s("%d%*c", &current->no);
		printf("���̸� :");
		scanf_s("%s", current->name, MAX_LEN);
		printf("���űݾ� :");
		scanf_s("%lf", &current->pamount);
		current->birth = (struct date*)malloc(sizeof(struct date));
		printf("�������(YYYY MM DD) :");
		scanf_s("%d %d %d", &current->birth->year, &current->birth->month, &current->birth->day);
		current->next = NULL; // ������ ����ü�� ���� �����ʹ� �׻� NULL : ���� ����Ʈ�� ������ ǥ��
	}
}

// ���� ������ �Ű����� --> ��� ���� ��� ����Ͽ� ��忡 ���� ������ ���
void add_client2(struct client_info_list** headp) // headp : ���� ������(�����Ϳ� ���� ������)
{
	struct client_info_list* current = NULL;

	if (*headp == NULL) // ���� �������� ����(main �Լ��� client_head)�� NULL
	{
		*headp = (struct client_info_list*)malloc(sizeof(struct client_info_list)); 
		// ���� ������ headp�� ����(main �Լ��� client_head)�� �� ����ü �޸� �Ҵ�(�Ҵ�� �޸� ���� �ּ� ����)

		// ���� �������� ���� �������� ����ü�� ���� �Է�
		printf("����ȣ :");
		scanf_s("%d%*c", &(*headp)->no);
		printf("���̸� :");
		scanf_s("%s", (*headp)->name, MAX_LEN);
		printf("���űݾ� :");
		scanf_s("%lf", &(*headp)->pamount);
		(*headp)->birth = (struct date*)malloc(sizeof(struct date));
		printf("�������(YYYY MM DD) :");
		scanf_s("%d %d %d", &(*headp)->birth->year, &(*headp)->birth->month, &(*headp)->birth->day);

		(*headp)->next = NULL; // ������ ����ü�� ���� �����ʹ� �׻� NULL : ���� ����Ʈ�� ������ ǥ��
	}
	else // ��� ���� ����
	{
		current = *headp; // ���� ������(headp)�� ������ ���� ������(current)�� ����

		// ���� �����͸� �� �� ����ü�� �̵�
		while (current->next != NULL) 
			current = current->next;

		// ���� ����ü�� ���� �����Ϳ� ����ü �޸� �Ҵ�
		current->next = (struct client_info_list*)malloc(sizeof(struct client_info_list));

		// ���� �����͸� ���� ����ü�� �̵�
		current = current->next;

		// ���� ����ü�� �� ���� �Է�
		printf("����ȣ :");
		scanf_s("%d%*c", &current->no);
		printf("���̸� :");
		scanf_s("%s", current->name, MAX_LEN);
		printf("���űݾ� :");
		scanf_s("%lf", &current->pamount);
		current->birth = (struct date*)malloc(sizeof(struct date));
		printf("�������(YYYY MM DD) :");
		scanf_s("%d %d %d", &current->birth->year, &current->birth->month, &current->birth->day);

		current->next = NULL; // ������ ����ü�� ���� �����ʹ� �׻� NULL : ���� ����Ʈ�� ������ ǥ��
	}
}


void delete_client(struct client_info_list** headp, char* name)
{
	// �� ��ġ�� �־��� ������ �ذ��ϴ� ������ �ڵ带 ä��ÿ�.

}
