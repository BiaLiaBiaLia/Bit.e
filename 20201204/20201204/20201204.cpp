#include <iostream>
#include <vector>
#include <string>
using namespace std;

//�����������
//��һ�������Ķ��������ڵ㰴��������������򣬸���a��b���ڵ㣬���������������
#if 0
class LCA {
public:
	int getLCA(int a, int b) {  //���ڵ����ӽڵ�Ĺ�ϵ��root=child/2
		// write code here
		if (a == b)
			return a;
		if (a < b)  //��֤a>b
			swap(a, b);
		while (a != b) {
			a /= 2;
			if (a == b)
				return a;
			else if (a > b)
				continue;
			else
				b /= 2;
		}
		return a;
	}
};

int main()
{
	LCA s;
	int a, b;
	while (cin >> a >> b)
		cout << s.getLCA(a, b) << endl;

	system("pause");
	return 0;
}
#endif

#if 0
//�������������1�ĸ���
int main()
{
	int n;
	while (cin >> n) {
		int count = 0;
		int temp = 0;
		for (int i = 0; i < 32; ++i) {
			if (n & (1 << i))
				temp++;
			else
				temp = 0;
			if (temp > count)
				count = temp;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif
/*
//����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
class Solution {
public:
	void DFS(int pos, string digits) {
		if (pos == digits.size()) {
			res.push_back(tmp);
			return;
		}
		int num = digits[pos] - '0';  //ȡ�������ַ����еĵ�������
		for (int i = 0; i < board[num].size(); ++i) {
			tmp.push_back(board[num][i]);
			DFS(pos + 1, digits);
			tmp.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		res.clear();
		tmp.clear();
		if (0 == digits.size())
			return res;
		DFS(0, digits);
		return res;
	}
	vector<string> res;
	string tmp;
	vector<string> board = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
};

int main()
{
	Solution s;
	string str;
	while (cin >> str) {
		vector<string> res=s.letterCombinations(str);
		for (auto e : res)
			cout << e << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
*/

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res;
		int a = 0, b = 0;
		int tmp = 0;
		for (auto e : nums)  //��������ȫ�����==����ֻ����һ��Ԫ��֮������
			tmp ^= e;
		int i = 0;
		while (!(tmp&(1 << i)))  //�ҵ�tmp�������е�һ��1,˵������ֻ����һ�ε�Ԫ�����������λ�ǲ�һ����
			++i;
		for (auto e : nums) {
			if (e&(1 << i))  //�����Ƶ�iλΪ1��ȫ��^
				a ^= e;
			else          //�����Ƶ�iλ��Ϊ1��ȫ��^
				b ^= e;
		}
		res.push_back(a);
		res.push_back(b);
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> vec = { 1,2,1,3,2,5 };
	vector<int> res=s.singleNumber(vec);

	system("pause");
	return 0;
}