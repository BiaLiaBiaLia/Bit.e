#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

//void Guess()
//{
//	srand((unsigned int)time(NULL));
//	int i = rand() % 100;
//	int input;
//	while (1)
//	{
//		printf("��������µ�����:\n");
//		scanf("%d", &input);
//		if (input == i)
//		{
//			printf("�¶���\n");
//			break;
//		}
//		else if (input > i)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("��С��");
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	while (1)
//	{
//		printf("***********************\n");
//		printf("*     1.����Ϸ        *\n");
//		printf("*     0.�˳���Ϸ      *\n");
//		printf("***********************\n");
//
//		scanf("%d", &input);
//		if (input == 1)
//		
//			Guess( );
//		
//		else if(input==0)
//		{
//			break;
//		}
//		else
//		{
//			printf("����������������룡\n");
//		}
//	}
//
//	system("pause");
//	return 0;
//}
//2.д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
//int BinarySearch(int arr[], int sz, int key)
//{
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		 mid = left + (right-left) / 2;
//		if (key == arr[mid])
//		{
//			return mid;
//		}
//		else if (key < arr[mid])
//		{
//			right = mid-1;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//			
//	}
//	if (left > right)
//		return -1;
//
//}
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof arr / sizeof arr[0];
//	int k = 0;
//	printf("������������Ҫ���ҵ�����");
//	scanf("%d", &k);
//
//	int i = BinarySearch(arr, sz, k);
//	if (i != -1)
//	{
//		printf("�ҵ��ˣ��±���%d\n", i);
//
//	}
//	else
//	{
//		printf("%d", i);
//	}
//
//	system("pause");
//	return 0;
//}

//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����

//int main()
//{
//	char password[20];
//	char key[20] = "abcdef";
//	printf("���������룺\n");
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", &password);
//		if (0 == strcmp(key, password))
//		{
//			printf("������ȷ!\n");
//			break;
//		}
//		else
//			printf("�������!\n");
//	}
//
//	system("pause");
//	return 0;
//}
//
//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
int main()
{
	char src[20];
	int i = 0;
	scanf("%s", &src);

	//for(i=0;i<strlen(src);i++)
	//{
	//	if ('A' <= src[i] && src[i] <= 'Z')
	//	{
	//		printf("%c", src[i] + 32);
	//	}
	//	if ('a' <= src[i] && src[i] <= 'z')
	//	{
	//		printf("%c", src[i] - 32);
	//	}
	//}
	while (src[i] != '\0')
	{
		if ('A' <= src[i] && src[i] <= 'Z')
		{
			printf("%c", src[i] + 32);
		}
		if ('a' <= src[i] && src[i] <= 'z')
		{
			printf("%c", src[i] - 32);
		}
		i++;
	}
	printf("\n");

	system("pause");
	return 0;
}