#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}

	printf("\n");
}

void merge(int *a, int low, int mid, int high)
{
	//��ʱ��������ռ��űȽϺ������Ԫ�أ�����ʼ��
	int *tmp = (int *)malloc(sizeof(a));
	memset(tmp, -1, sizeof(a) / sizeof(int));

	int index = low;
	int i = low, j = mid + 1;
	//ע��:�����ֵ������㹻Сʱ,low==mid,mid+1==high
	while (i <= mid && j <= high) {
		if (a[i] <= a[j])
			tmp[index++] = a[i++];
		else
			tmp[index++] = a[j++];
	}
	//�����Ԫ����䵽tmp��
	while (i <= mid)
		tmp[index++] = a[i++];
	//���ұ�Ԫ������tmp��
	while (j <= high)
		tmp[index++] = a[j++];
	//��tmp�е����ݿ�����ԭ�����Ӧ����������
	//ע��:end2-begin1+1
	memcpy(a + low, tmp + low, sizeof(int)*(high - low + 1));
}

//�鲢����(�ϲ�����)
//ǰ�᣺�ϲ�������������
//1.�Ȱ���������������ƽ���ֳ�����
//2.�ֱ����������С���䰴�շ����㷨����֪��С������Ԫ�ظ���<=1
//3.�ϲ�����������������
void mergeSortInternal(int *a, int low, int high)
{
	if (low >= high)
		return;
	int mid = (low + high) / 2;
	//[low,mid)
	//[mid,high)
	mergeSortInternal(a, low, mid);
	mergeSortInternal(a, mid + 1, high);

	//�ϲ�������������
	merge(a, low, mid, high);
}


int main()
{
	int a[] = { 9, 3, 5, 4, 9, 2, 7, 9, 3, 6, 8, 8 };
	int size = sizeof(a) / sizeof(int);
	int left = 0;
	int right = size - 1;
	printArray(a, size);

	mergeSortInternal(a, left, right);
	printArray(a, size);

	system("pause");
	return 0;
}