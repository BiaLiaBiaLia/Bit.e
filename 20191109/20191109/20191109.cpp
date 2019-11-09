#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

#if 0
int main()
{
	string str;
	cin >> str;
	int i = 0;
	int max = 0;
	string ret;//记录最长数字串
	
	while (i < str.size())
	{
		string s;
		int len = 0;
		while (isdigit(str[i]))
		{
			s += str[i];
			++i;
			++len;
		}

		if (len > max)
		{
			max = len;
			ret = s;
		}
		++i;
	}

	cout << ret << endl;

	system("pause");
	return 0;
}
#endif

class Solution{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		if (numbers.size() <= 0)
			return 0;

		sort(numbers.begin(),numbers.end());
		int max = numbers[numbers.size()-1];

		vector<int> v(max+1);
		for (int i = 0; i < numbers.size(); ++i)
		{
			++v[numbers[i]];
		}
		int x = v[0];
		int y;
		for (int i = 1; i < v.size(); ++i)
		{
			if (v[i] > x)
			{
				x = v[i];
				y = i;
			}
		}
		if (x <= numbers.size()/2)
			return 0;
		else
			return y;
	}
};

int main()
{
	Solution s;
	vector<int> x = { 1,2,3,2,2,2,5,4,2 };

	cout << s.MoreThanHalfNum_Solution(x) << endl;

	system("pause");
	return 0;
}
