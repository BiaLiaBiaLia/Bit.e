#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include <math.h>
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	unsigned int sum = 0;
//	for (i = 0; i < 32; ++i)
//	{
//		sum += ((value >> i) & 1) << (31 - i);//先将值取出，再左移调换位置
//	  //sum += ((value >> i) & 1)*pow(2, 31 - i)同理,需调用math.h
//	}                                         
//	return sum;
//}
//int main()
//{
//	unsigned int input = 0;
//	printf("请输入要反转的数：");
//	scanf("%u", &input);
//	printf("反转后的值为：%u\n", reverse_bit(input));
//
//	system("pause");
//	return 0;
//}
//2.不使用（a + b） / 2这种方式，求两个数的平均值。
//float my_average(int a,int b)//使用float求得的平均数可为小数
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
//	printf("平均数是：%0.2f\n", my_average(a, b));
//	printf("平均数是：%0.2f\n", My_average(a, b));
//
//	system("pause");
//	return 0;
//}
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//int main()
//{
//	int i = 0;
//	int ret = 0;
//	int arr[] = { 1,2,3,4,2,1,4 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	printf("数据为：");
//	for (i = 0; i < length; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (i = 0; i < length; ++i)
//	{
//		ret ^= arr[i];
//	}
//	printf("这个数字为：%d\n", ret);
//
//	system("pause");
//	return 0;
//}
//4.
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
void reverse(char* left, char* right)//逆序
{
	assert(left);//判断参数不为空
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
	reverse(left, right);//将整个字符串逆序
	while (*str1)
	{
		left = str1;
		while ((*str1 != '\0') && (*str1 != ' '))//单词长度累加
		{
			str1++;
		}
		right = str1 - 1;//str加完为单词后的空格,需减一为单词最后一个字母
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