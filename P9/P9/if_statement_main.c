#include "my_op.h"

// ����1 : �Ʒ� ���α׷��� 5�� ���� ��ΰ� ����ǵ��� �����Ͻÿ�. �� : ���� 1��, 5�� ������ ��� ���� ���� 1��
int main(void)
{
	int x, y, op;
	int result;

	printf("���� �Է°� x : "); scanf_s("%d", &x);
	printf("���� �Է°� y : "); scanf_s("%d", &y);
	printf("������(���� 1, ���� 2, ���� 3, ������ 4, ������ 5) :  ");
	scanf_s("%d", &op);

	if ((op < 1) || (op > 5)) {
		printf("ERROR: �������� �ʴ� ������\n");
		return 0;
	} 
	if ((op == 4) || (op == 5)) {
		printf("������ �Ǵ� ������ ���� : ������ �� 0 Ȯ��\n");
		if (y == 0){
			printf("ERROR : ������ �� 0\n");
			return 0;
		}
	else {
			result = my_op(x, y, op);
			printf("���� ��� = %d\n", result);
		}
	}
	else {
		result = my_op(x, y, op);
		printf("���� ��� = %d\n", result);
	}
	return 0;
}