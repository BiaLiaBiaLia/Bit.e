#pragma once
#include <iostream>
using namespace std;

void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	cout << endl;
}

void merge(int *a, int low, int mid, int high)
{
	//��ʱ��������ռ��űȽϺ������Ԫ�أ�����ʼ��
	int *tmp = new int(sizeof(int)*(sizeof(a) / sizeof(int)));
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