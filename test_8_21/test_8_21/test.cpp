#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

#if 0
char FindFirstDoubleChar(char str[])
{
	if (str == NULL || str[0] == '\0')
		return 0;
	int count[256] = { 0 };
	int i = 0;
	while (str[i++] != '\0')
	{
		count[str[i]]++;
		if (count[str[i]] == 2)
			return str[i];
	}
	return 0;
}
int main()
{
	char arr[] = "qywyer23tdd";
	printf("%c\n", FindFirstDoubleChar(arr));

	system("pause");
	return 0;
}
#endif
#if 0
void FindSingleNum(int a[], int size)
{
	int max = a[0];
	int i = 0;
	for (i = 1; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	int *count = (int *)malloc(sizeof(int)*(max + 1));
	for (i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		count[a[i]]++;
	}
	for (i = 0; i < size; i++)
	{
		if (count[a[i]] == 1)
			printf("%d ", a[i]);
	}
	printf("\n");
	free(count);
}
int main()
{
	int arr[] = { 1,3,5,7,1,3,5,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	FindSingleNum(arr, size);

	system("pause");
	return 0;
}
#endif

void DeleteChar(char s1[],int length1, char s2[],int length2)
{
	assert(s1 != NULL);
	for (int i = 0; i < length1; i++)
	{
		for (int j = 0; j < length2; j++)
		{
			if (s1[i] == s2[j])
				break;
			else if (j == length2 - 1)
				printf("%c", s1[i]);
		}
	}
	printf("\n");
}

int main()
{
	char str1[] = "They are students.";
	char str2[] = "aeiou";
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	DeleteChar(str1, length1, str2, length2);

	system("pause");
	return 0;
}