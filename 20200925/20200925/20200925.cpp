#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0
class Solution {
public:
	//Ω‚√‹
	string deciphering(vector<string>& s1, vector<string>& s2) {
		string res;
		for (int i = 0; i < s1.size(); ++i) {
			for (int j = 0; j < s1.size(); ++j) {
				if (s1[i][j] == '0')
					res += s2[i][j];
			}
		}

		for (int j = 0; j < s1.size(); ++j) {
			for (int i = s1.size()-1; i >= 0; --i) {
				if (s1[i][j] == '0')
					res += s2[j][3 - i];
			}
		}

		for (int i = s1.size() - 1; i >= 0; --i) {
			for (int j = s1.size() - 1; j >= 0; --j) {
				if (s1[i][j] == '0')
					res += s2[3 - i][3 - j];
			}
		}

		for (int j = s1.size() - 1; j >= 0; --j) {
			for (int i = 0; i < s1.size(); ++i) {
				if (s1[i][j] == '0')
					res += s2[3 - j][i];
			}
		}

		return res;
	}
};

int main()
{
	vector<string> s1 = { "1101","1010","1111","1110" };
	vector<string> s2 = { "ABCD","EFGH","IJKL","MNPQ" };
	Solution s;
	cout << s.deciphering(s1, s2) << endl;
	//CFHQGLMPAIKNBDEJ

	system("pause");
	return 0;
}
#endif