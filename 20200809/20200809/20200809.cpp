#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,
//���ֵ����ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
class Solution {
public:
	vector<string> result;
	vector<string> Permutation(string str) {
		if (str.length() == 0) {
			return result;
		}
		Permutation1(str, 0);
		sort(result.begin(), result.end());
		return result;
	}
	void Permutation1(string str, int begin) {
		if (begin == str.length()) {
			result.push_back(str);
			return;
		}
		for (int i = begin; str[i] != '\0'; i++) {

			if (i != begin && str[begin] == str[i])
				continue;
			swap(str[begin], str[i]);
			Permutation1(str, begin + 1);
			swap(str[begin], str[i]);
		}

	}
};

int main()
{
	Solution s;
	string str = "abc";
	vector<string> res = s.Permutation(str);
	for (auto &e : res)
		cout << e << ",";
	cout << endl;

	system("pause");
	return 0;
}