#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//1.
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if ((b == 2) + (a == 3) == 1 &&
//							(b == 2) + (e == 4) == 1 &&
//							(c == 1) + (d == 2) == 1 &&
//							(c == 5) + (d == 3) == 1 &&
//							(e == 4) + (a == 1) == 1)
//							if (a*b*c*d*e == 120)
//
//								printf("a:%d b:%d c:%d d:%d e:%d\n", a, b, c, d, e);
//
//					}
//				}
//			}
//		}
//	}
//
//	system("pause");
//	return 0;
//}
//2.
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
//
//int main()
//{
//	int murder;
//	for (murder = 'A'; murder <= 'D'; murder++)
//	{
//		if ((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3)
//			printf("murder��%c\n", murder);
//	}
//
//	system("pause");
//	return 0;
//}
//3.����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
#define N 15
int main()
{
	int i = 0;//��
	int j = 0;//��
	int x = 0;
	int a[N][N] = { 0 };
	int input = 0;
	printf("�����������ӡ������ǵ�������");
	scanf("%d", &input);
	for (i = 1; i <= input; i++)
		a[i][1] = a[i][i] = 1;
	for (i = 3; i <= input; i++)
		for (j = 2; j <= i - 1; j++)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];

	for (i = 1; i <= input; ++i)
	{
		for (x = 1; x <= input - i; ++x)
			printf("  ");
		for (j = 1; j <= i; ++j)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	printf("\n");

	system("pause");
	return 0;
}