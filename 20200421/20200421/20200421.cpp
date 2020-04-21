#include<iostream>
using namespace std;

int main()
{
	int n;
	int col[100];

	while (cin>>n)
	{
		int  havezero = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> col[i];
			if (col[i] == 0)
				havezero = 1;
		}
		int ans = 0;
		for (int i = 0; i <= 30; i++)
		{
			int ck;
			ck = 1 << i;
			int temp = 0;
			for (int j = ans; j < n; j++)
			{
				if (ck & col[j])
				{
					if (temp == 0)
					{
						temp = col[j];
						col[j] = col[ans];
						col[ans] = temp;
						ans++;
					}

					else
						col[j] ^= temp;
				}
			}

		}
		ans += havezero;
		cout << ans << endl;
	}

	system("pause");
	return 0;
}