#include "My_op.h"

int runtime = 0;
static int result = 0;

int main(int argc, char *argv[])
{
	int x, y, op;
	int repeat_limit = 10;
	for (int i = 0; i < repeat_limit; i++)
	{
		printf("������ ����(���� : -1, ���� 1, ���� 2, ���� 3, ������ 4, ������ 5, ������ȯ 6) :  ");
		scanf_s("%d", &op);
		if (op == -1) break;
		if ((op < 1) || (op > 6)) // ������ ���� ����, �ٽ� ����
		{
			printf("�������� �ʴ� ����, �ٽ� �����ϼ���!\n");
			continue;
		}
		printf("�Է°� x : ");
		scanf_s("%d", &x);
		printf("�Է°� y : ");
		scanf_s("%d", &y);
		if (op == DECIMAL_CONVERT) { // ������ x�� y������ ��ȯ
			runtime = 0;
			MeGeByeonSoo(x, y);
			decimal_convert(x, y);// decimal_convert() ����� ���� �Լ�
			printf("\n�Լ� �ݺ� Ƚ�� = %d", runtime);
			printf("\n\n");
			continue;
		}
		if (((op == 4) || (op == 5)) && (y == 0)) // ������ �� 0 ����, ���� ����
		{
			printf("ERROE : ������ �� 0\n");
			break;
		}
		result = my_op(x, y, op); // my_op() ����� ���� �Լ�
		printf("my_op ���� ��� = %d\n\n", result);
	}

	return 0;
}