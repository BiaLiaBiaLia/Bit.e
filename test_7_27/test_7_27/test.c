#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//1.
//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	int x = 0;
//	while (value)
//	{
//		x = value % 2;
//		value >>= 1;
//		if (x == 1)
//			count++;
//		/*if (value % 2)
//			count++;
//		value >>= 1;*/
//	}
//	return count;
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%u", &n);
//	int m = count_one_bits(n);
//	printf("��������1�ĸ���Ϊ��%d\n", m);
//
//	system("pause");
//	return 0;
//}
//
//2.��ȡһ�������������������е�ż��λ������λ��
//�ֱ�������������С�
//int main()
//{
//	int i = 0;
//	int j = 0;
//;	int x = 0;
//	scanf("%d", &x);
//	printf("��ȡ��ż��λΪ��");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d", (x >> i) & 1);
//	}
//	printf("\n");
//	printf("��ȡ������λΪ��");
//	for (j = 30; j >= 0; j -= 2)
//	{
//		printf("%d", (x >> j) & 1);
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

//3. ���һ��������ÿһλ��
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%d  ", x % 10);
//}
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	print(x);
//
//	system("pause");
//	return 0;
//}
//4.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
int count_dif_bits(int m, int n)
{
	int count = 0;
	int x = m ^ n;
	int z = 0;
	while (x)
	{
		z = x % 2;
		x >>= 1;
		if (z == 1)
			count++;
	}
	return count;
}
int main()
{
	int m = 0;
	int n = 0;
	int x = 0;
	scanf("%d %d", &m, &n);

	printf("����%d��%d�Ķ����Ʊ���У���%d��λ��bit����ͬ\n", m, n, count_dif_bits(m, n));

	system("pause");
	return 0;
}