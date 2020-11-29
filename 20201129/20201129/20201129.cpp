#include <stdlib.h>
#include <stdio.h>

void PrintArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//1.ֱ�Ӳ�������
// �ȶ��ԣ��ȶ�
// ʱ�临�Ӷ�
// ���			�			ƽ��
// O(n)			O(n^2)			O(n^2)
// ����			����			�����
// �ռ临�Ӷ�	O(1)
void insertSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		// ��������[0,i)
		//��������[i,size)
		//ץ�����[i]��
		//�Ӻ���ǰ�Ƚϲ�����
		int j;
		int k = a[i];
		for (j = i - 1; j >= 0 && k < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = k;//������a[j]=k,���ϸ�forѭ��������������j������һ��--
	}
}


//2.ϣ������
//ǰ�᣺���������У�����Խ�ӽ���������Ч��Խ��
//Ԥ����->����  �������
// �ȶ��ԣ����ȶ�
// ʱ�临�Ӷ�
// ���			�			ƽ��
// O(n)			O(n^2)			O(n^1.2-1.3)
// ����			����			�����
// �ռ临�Ӷ�	O(1)
void insertSortwithgap(int a[], int size, int gap)
{
	for (int i = 0; i < size; i++)
	{
		int j;
		int k = a[i];
		for (j = i - gap; j >= 0 && a[i] < a[j]; j -= gap)
		{
			a[i] = a[j];
		}
		a[j + gap] = k;
	}
}

void shellSort(int a[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		insertSortwithgap(a, size, gap);
		if (gap == 1)
			break;
	}

}int main()
{
	int a[] = { 9,5,2,7,3,6,4,8,3,2,1 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);

	insertSort(a, size);
	PrintArray(a, size);

	shellSort(a, size);
	PrintArray(a, size);

	system("pause");
	return 0;
}