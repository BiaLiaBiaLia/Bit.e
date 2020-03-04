#include <iostream>
#include <string.h>
using namespace std;

//����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ���ransom�ܲ����ɵڶ����ַ���magazines������ַ����ɡ�
//������Թ��ɣ����� true �����򷵻� false��

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int hash[26] = { 0 };
		for (int i = 0; magazine[i]; ++i) {
			hash[magazine[i] - 'a'] += 1;
		}
		for (int i = 0; ransomNote[i]; ++i) {
			hash[ransomNote[i] - 'a'] -= 1;
			if (hash[ransomNote[i] - 'a'] < 0)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	string s1 = "aa";
	string s2 = "aab";
	
	cout << s.canConstruct(s1, s2) << endl;

	system("pause");
	return 0;
}