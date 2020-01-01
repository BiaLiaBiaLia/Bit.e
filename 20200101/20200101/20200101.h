#pragma once
#include <iostream>
using namespace std;

void PrintArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//�ǱȽ�����
//1.��������(�볲ԭ��)
//�����ܼ�������ĳ����Χ(Ӧ�ó���)
//ȷ�����ݵķ�Χ
//���뱣�����ݸ����Ŀռ�
//ͳ��������ÿ�����ݳ��ֵĴ���
//���մ��������ݽ��л���
//ʱ�临�Ӷȣ�O(N)
//�ռ临�Ӷȣ�O(M)  M��������Ԫ�صĸ���
//�ȶ��ԣ��ȶ���
void countSort(int a[], int size)
{
	//1.�������ݷ�Χ
	int minValue = a[0];
	int maxValue = a[0];
	//O(N)
	for (int i = 0; i < size; i++)
	{
		if (a[i] < minValue)
			minValue = a[i];

		if (a[i] > maxValue)
			maxValue = a[i];
	}

	//2.��ȡ�����Ŀռ�
	int range = maxValue - minValue + 1;
	int* temp = (int*)malloc(sizeof(int)*range);//�ռ��ʼΪ0
	if (NULL == temp)
		return;

	//3.ͳ��ÿ��Ԫ�س��ֵĴ���
	memset(temp, 0, sizeof(int)*range);

	//O(N)
	for (int i = 0; i < size; i++)
		temp[a[i] - minValue]++;

	//����
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (temp[i])
		{
			a[index++] = i + minValue;
			temp[i]--;
		}
	}

	free(temp);
}

//2.��������----��ؼ�������
//1.ͳ��ÿ��Ͱ��Ԫ�صĸ���
//2.����ÿ��Ͱ����ʼ��ַ

//for(��������λ����M)
//3.�Ե�ǰλΪͰ�ı�ţ������ݷŵ���Ӧ��Ͱ�� O(N)
//4.����Ͱ�ı�Ŵ�С���󣬶�ÿ��Ͱ�е�Ԫ�ؽ��л��� O(N)
//Ͱ��Ԫ�ػ��չ���FIFO

//addr[i]=addr[i-1]+Count[i-1];
