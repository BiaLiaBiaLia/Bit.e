#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include <math.h>
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	unsigned int sum = 0;
//	for (i = 0; i < 32; ++i)
//	{
//		sum += ((value >> i) & 1) << (31 - i);//�Ƚ�ֵȡ���������Ƶ���λ��
//	  //sum += ((value >> i) & 1)*pow(2, 31 - i)ͬ��,�����math.h
//	}                                         
//	return sum;
//}
//int main()
//{
//	unsigned int input = 0;
//	printf("������Ҫ��ת������");
//	scanf("%u", &input);
//	printf("��ת���ֵΪ��%u\n", reverse_bit(input));
//
//	system("pause");
//	return 0;
//}
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//float my_average(int a,int b)//ʹ��float��õ�ƽ������ΪС��
//{
//	float average = 0.0;
//	average = (a & b) + (a^b) / 2.0;
//	return average;
//}
//float My_average(int a, int b)
//{
//	float avg = 0.0;
//	avg = a - (a - b) / 2.0;
//	return avg;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a,&b);
//	printf("ƽ�����ǣ�%0.2f\n", my_average(a, b));
//	printf("ƽ�����ǣ�%0.2f\n", My_average(a, b));
//
//	system("pause");
//	return 0;
//}
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//int main()
//{
//	int i = 0;
//	int ret = 0;
//	int arr[] = { 1,2,3,4,2,1,4 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	printf("����Ϊ��");
//	for (i = 0; i < length; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (i = 0; i < length; ++i)
//	{
//		ret ^= arr[i];
//	}
//	printf("�������Ϊ��%d\n", ret);
//
//	system("pause");
//	return 0;
//}
//4.
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
void reverse(char* left, char* right)//����
{
	assert(left);//�жϲ�����Ϊ��
	assert(right);
	char tmp;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void reverse_str(char* str, int len)
{
	assert(str);
	char* str1 = str;
	char* left = str;
	char* right = str + len - 1;
	reverse(left, right);//�������ַ�������
	while (*str1)
	{
		left = str1;
		while ((*str1 != '\0') && (*str1 != ' '))//���ʳ����ۼ�
		{
			str1++;
		}
		right = str1 - 1;//str����Ϊ���ʺ�Ŀո�,���һΪ�������һ����ĸ
		reverse(left, right);
		if (*str1 == ' ')
		{
			str1++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	reverse_str(arr, len);
	printf("%s\n", arr);

	system("pause");
	return 0;
}