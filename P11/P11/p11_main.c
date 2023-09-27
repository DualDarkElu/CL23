#include "p11_op.h"

// ����1 : �Ʒ� ���α׷����� ����ϴ� my_op() �Լ��� ���� ��ȯ���� �ʰ� ���� ����� �Լ��� ���ڷ� �����ϵ��� My_op.c ������ �Լ��� �����ϰ� \
           main �Լ��� �Լ� ȣ�� ���� �κ��� �����Ͽ� ������ ����� ��µǵ��� �����Ͻÿ�.

int main(int argc, char* argv[]) {
	int x, y, op;
	int result = 0;

	int repeat_num = (argc > 1) ? atoi(argv[1]) : 5;
	//argc�� 1 �̻� �Էµɶ� ���ǰ�, atoi�� ���ڿ��� ������ ��ȯ�Ѵ�. ���� �Է°��� ������ �⺻���� 5�� ����Ѵ�.
	//
	// 
	// ����2 : �ݺ����� �ݺ�Ƚ���� �����ϴ� repeat_num �������� ���α׷��� ������ �� �ܺο��� �Է¹��� �� �ֵ��� �����ϰ� \
		             ������� ������ ��� ������Ʈ ������ ����Ͽ� �����Ͻÿ�(�����ڷ� ����).

	for (int i = 0; i < repeat_num; i++)
	{
		printf("������ ����(���� : -1, ���� 1, ���� 2, ���� 3, ������ 4, ������ 5, ���� 6, ������ȯ 7) :  ");
		scanf_s("%d", &op);
		if (op == -1) break;
		if ((op < 1) || (op > 7)) // ������ ���� ����, �ٽ� ����
		{
			printf("�������� �ʴ� ����, �ٽ� �����ϼ���!\n");
			continue;
		}
		printf("inut x : ");
		scanf_s("%d", &x);
		printf("inut y : ");
		scanf_s("%d", &y);
		if (op == DECIMAL_CONVERT) {
			// ����3 : ������ x�� y������ ��ȯ�Ͽ� ����ϴ� �Լ� decimal_convert(x, y)�� ����Լ� ���·� My_op.c ���Ͽ� �����ϰ� \
				// �� ��ġ���� ȣ���Ͻÿ�.  �Լ� ȣ�� �ܿ� ������ ��ɹ��� �� ��ġ���� ������� ���ÿ�. 
			decimal_convert(x, y);
			printf("\n\n");
			continue;
		}
		if (((op == DIVIDE) || (op == REMAINDER)) && (y == 0)) // ������ �� 0 ����, ���� ����
		{
			printf("ERROE : ������ �� 0\n");
			break;
		}
		if (op == EXPONENT)
		{
			result = 1;
			for (int j = 0; j < y; j++)
			{
				int temp_result;
				my_op(result, x, MULTIPLY, &temp_result);
				result = temp_result;
			}
		}
		else
			my_op(x, y, op, &result);
		printf("���� ��� = %d\n\n", result);
	}

	return 0;
}

