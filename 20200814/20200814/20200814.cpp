#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Ãû×ÖµÄÆ¯ÁÁ¶È
void solve()
{
	string name;
	cin >> name;
	int a[26] = { 0 };
	int k = 26;
	int res = 0;
	for (int i = 0; i < name.size(); i++)
	{
		a[tolower(name[i]) - 'a']++;
	}
	sort(a, a + 26);
	for (int i = 25; i >= 0; i--)
	{
		res += a[i] * k;
		k--;
	}
	cout << res << endl;
}
int main()
{
	int N;
	while (cin >> N)
	{
		for (int i = 0; i < N; i++)
		{
			solve();
		}
	}

	system("pause");
	return 0;
}