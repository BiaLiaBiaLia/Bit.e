#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0) return -1;
		vector<int> f;
		for (int i = 0; i < n; i++)
		{
			f.push_back(i);
		}
		int last = 0;
		while (f.size() > 1)
		{
			last = (m + last - 1) % f.size();
			f.erase(f.begin() + last);
		}
		return f[0];
	}
};

int main()
{
	Solution s;
	cout << s.LastRemaining_Solution(10, 3) << endl;

	system("pause");
	return 0;
}