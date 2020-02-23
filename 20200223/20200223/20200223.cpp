#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

//°²ÖÃÂ·µÆ
int main()
{
	char ss[1005];
	int n, m;
	scanf("%d", &n);
	while (n--)
	{
		memset(ss, 0, sizeof(ss));
		scanf("%d", &m);
		getchar();

		scanf("%s", ss);
		int i = 0;
		int sum = 0;
		while (i < m)
		{
			if (ss[i] == '.')
			{
				i = i + 3;
				sum++;
			}
			else
			{
				i++;
			}
		}
		printf("%d\n", sum);
	}

	system("pause");
	return 0;
}