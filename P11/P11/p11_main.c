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
		if (op == EXPONENT) {
			op = MULTIPLY;
			result = 1;
			if (y == 0) { // result == 1
				printf("My_op result = %d\n\n", result);
				continue;
			}
			for (int j = 1; j <= y / 2; j++)  // ��ø �ݺ���
				result *= my_op(x, x, op);
			if (y % 2 != 0)
				result = my_op(result, x, op);
		}
		else
			result = my_op(x, y, op);
		printf("���� ��� = %d\n\n", result);
	}

	return 0;
}
/*#include "p11_op.h"

int main(int argc, char *argv[]) 
{
    int x, y, op;
    int result = 0;

    int repeat_num = (argc > 1) ? atoi(argv[1]) : 5;

    for (int i = 0; i < repeat_num; i++)
    {
        printf("������ ����(���� : -1, ���� 1, ���� 2, ���� 3, ������ 4, ������ 5, ���� 6, ������ȯ 7) :  ");
        scanf("%d", &op);

        if (op == -1) break;

        if ((op < 1) || (op > 7)) 
        {
            printf("�������� �ʴ� ����, �ٽ� �����ϼ���!\n");
            continue;
        }

        printf("input x : ");
        scanf("%d", &x);
        printf("input y : ");
        scanf("%d", &y);

        if (op == DECIMAL_CONVERT) 
        {
            decimal_convert(x, y);
            printf("\n\n");
            continue;
        }

        if (((op == DIVIDE) || (op == REMAINDER)) && (y == 0)) 
        {
            printf("ERROR: ������ �� 0\n");
            break;
        }

        my_op(x, y, op, &result);
        printf("���� ��� = %d\n\n", result);
    }

    return 0;
}*/