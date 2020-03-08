#include<iostream>
using namespace std;

struct hour
{
	int Hi, Mi;
};

int main()
{
	int N = 0, i, X, A, B;
	cin >> N;
	hour* t = new hour[N];
	for (i = 0; i < N; i++)
		cin >> t[i].Hi >> t[i].Mi;
	cin >> X;
	cin >> A >> B;

	for (i = 0; i < N - 1; i++)
	{
		int h, m;
		for (int j = i + 1; j < N; j++)
		{
			if (t[i].Hi < t[j].Hi)
				continue;
			else if (t[i].Hi == t[j].Hi)
			{
				if (t[i].Mi <= t[j].Mi)
				{
					continue;
				}
				else
				{
					m = t[i].Mi;
					t[i].Mi = t[j].Mi;
					t[j].Mi = m;
				}
			}
			else
			{
				h = t[i].Hi; m = t[i].Mi;
				t[i].Hi = t[j].Hi; t[i].Mi = t[j].Mi;
				t[j].Hi = h; t[j].Mi = m;
			}
		}
	}
	for (i = N - 1; i >= 0; i--)
	{
		if (((A - t[i].Hi) * 60 - t[i].Mi + B) >= X)
		{
			cout << t[i].Hi << " " << t[i].Mi << endl;
			break;
		}
	}
	delete[] t;

	system("pause");
	return 0;
}
