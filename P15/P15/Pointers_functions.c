#include "Pointers.h"

// 포인터를 사용하여 적절하게 수정하시오.
void data_swap1(int *data1, int *data2)
{
	int temp;

	temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

// 아래 함수를 포인터를 사용하여 작성하시오.
void data_swap3(int* array1, int* array2) {
    int temp;
    for (int i = 0; i < 5; ++i) {
        temp = array1[i];
        array1[i] = array2[i];
        array2[i] = temp;
    }
}
