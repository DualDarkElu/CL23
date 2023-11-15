#include "Client.h"

int main(void)
{
	// 1. ����ü ��� ���� : 8 ����Ʈ ����ü ����(Visual Studio)
	
	// 8 ����Ʈ ����ü ���� : CPU�� 8����Ʈ ������ �޸𸮸� �����ϱ� �����ϵ��� �����Ϸ���  
	// ����ü ������ 8�� ��� �ּҿ��� �����ϵ��� �޸𸮸� �Ҵ��ϰ� 8�� ����� ����ü �޸� �Ҵ�
	// Visual Studio�� 8 ����Ʈ ����ü ����
	
	// ����ü�� ��� ���� ���� : char Ÿ���� 1 ����Ʈ ����, int Ÿ���� 4 ����Ʈ ����, double Ÿ���� 8 ����Ʈ ����
	// n ����Ʈ ��� ���� : n�� ��� �ּҿ��� ���� n  ����Ʈ �Ҵ�
	// n ����Ʈ ��� ���� ���� : �⺻ ������ Ÿ�� ��� ���� ��ü�� �ѹ��� CPU ����ü �޸� �б⿡ ���Խ�Ŵ���ν�
	// �޸� �б� Ƚ���� �ٿ� ó�� �ӵ� ���
	
	struct test_type {
			char c[6]; 
			int i; 
			double d;
	} test_var;
	
	printf("\ntest_var ����ü ũ�� : %d\n", sizeof(test_var));
	printf("\ntest_var ����ü �޸� �ּ� : %p\n", &test_var);

	// ���� 1. test_var ����ü ������ �Ҵ�� �޸��� ũ�Ⱑ 8�� ����ΰ�?
	// ���� 2. �������� ����� test_var ����ü ������ ���� �ּҴ� 8�� ����ΰ�?

	// ���� ����ü ���� test_var���� �迭 c[6]�� 0~5, ���� i�� 6~9, ���� d�� 10~17����Ʈ�� �Ҵ��ϸ� 
	// 6~9 ����Ʈ�� ����� i ������ 8����Ʈ ������ �޸𸮸� �����ϴ� CPU�� ���� 0~7, 8~15 ����Ʈ�� 2�� �޸� �б� �ʿ�, 
	// 10~17 ����Ʈ�� ����� d ������ 8~15, 16~25 ����Ʈ�� 2�� �޸� �б� �ʿ�.
	// int ���� i�� 4 ����Ʈ �����ϸ� 8~11����Ʈ�� �����ϹǷ� CPU�� 8~15����Ʈ 1���� �޸� �б�� i ��� ���� ó�� ����
	// double ���� d�� 8����Ʈ �����ϸ� 16~23 ����Ʈ�� �����ϹǷ� CPU�� 16~23����Ʈ 1���� �޸� �б�� d ��� ���� ó�� ����
	// ���� ����ü ���� test_var�� ũ��� 24 ����Ʈ�� �ȴ�.
	

	struct client_info client1;
	// ���� 3. client1 ������ ũ��� ���ΰ�?

	struct client_info_test client_test;
	// ���� 3. client_test ������ ũ��� ���ΰ�? 4

	struct client_info_test1 client_test1;
	// ���� 4. client_test1 ������ ũ��� ���ΰ�? 56


	// 2. ����ü ������ ������ ��� ���� ���� ������ ->

	struct client_info client2;

	// ����ü ������ ������ ��� ���� ���� ������ : ->
	// Client.h ���Ͽ� ���ǵ� struct client_info ����ü Ÿ�� ���� client2�� �ּҸ� ���ڷ� �ʱ�ȭ�ϴ� �Լ� input_client_pointer1() �ۼ�
	printf("\n�� ���� �Է�:\n");
	 input_client_pointer1(&client2);

	 // ����ü ���� client2�� ��� ���� ���
	 printf("\n�� ���� ���:\n");
	output_client(client2);

	// ���� 5. ������ ���� input_client_pointer1() �Լ��� ȣ���ϸ� ��� �ɱ�?
	/*
	struct client_info* clientp = NULL;
	input_client_pointer1(clientp);
	*/

	// ���� 1 : Client.h�� ���ǵ� struct client_info1 ����ü Ÿ������ ���ǵ� client3 ������ �� ������ �Է��ϴ� 
	// input_client_pointer2() �Լ��� Client_functions.c �ҽ� ���Ͽ� �ۼ��Ͻÿ�.

	struct client_info1 client3;
	
	// �� ��ġ�� ������ �ڵ带 �߰��϶�.

	// input_client_pointer2() �Լ��� Client_functions.c �ҽ� ���Ͽ� �ۼ��϶�.
	input_client_pointer2(&client3);

	// ���� 2 : Client.h�� ���ǵ� struct client_info1 ����ü Ÿ������ ���ǵ� client3 ������ �� ������ ����ϴ� 
	// output_client2() �Լ��� Client_functions.c �ҽ� ���Ͽ� �ۼ��Ͻÿ�.
	output_client2(client3);

	// 3. ����ü �迭�� ����ü ������ ����

	struct client_info clients[MAX_NUM] = { 0 };
	int num;

	printf("�� �� : ");
	scanf_s("%d", &num);

	// ���� 3. Client_functions.c �ҽ� ���Ͽ� ����ü �迭 �Ű� ������ �ۼ��� input_client_all() �Լ��� ����ü ������ �Ű� ������ �����ϰ�
	// ����ü ������ ������ ����Ͽ� �����Ͻÿ�.
	input_client_all(clients, num); 
	printf("\n\n�� ��� : \n");

	// ���� 4. Client_functions.c �ҽ� ���Ͽ� ����ü �迭 �Ű� ������ �ۼ��� output_client_all() �Լ��� ����ü ������ �Ű� ������ �����ϰ�
	// ����ü ������ ������ ����Ͽ� �����Ͻÿ�.
	output_client_all(clients, num);

}