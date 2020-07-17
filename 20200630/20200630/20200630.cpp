#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string str;
	cin >> str;
	str += ',';
	vector<int> arr;
	int num;
	char charset;
	istringstream is(str);
	while (is >> num >> charset)
	{
		arr.push_back(num);
	}
	int i = 0, j = arr.size() - 1;
	vector<int> ret;
	while (i <= j)
	{
		ret.push_back(arr[i]);
		if (i == j)
			break;
		ret.push_back(arr[j]);
		i++;
		j--;
	}
	for (int i = 0; i < ret.size(); i++)
	{
		if (i == ret.size() - 1)
		{
			cout << ret[i] << endl;
		}
		else
		{
			cout << ret[i] << ",";
		}
	}


	return 0;
}