#include <iostream>
#include <vector>
#include <string>
using namespace std;

//最近公共祖先
//有一颗无穷大的二叉树，节点按层序遍历依次排序，给出a，b两节点，求其最近公共祖先
#if 0
class LCA {
public:
	int getLCA(int a, int b) {  //父节点与子节点的关系：root=child/2
		// write code here
		if (a == b)
			return a;
		if (a < b)  //保证a>b
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
//二进制中最长连续1的个数
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
//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
class Solution {
public:
	void DFS(int pos, string digits) {
		if (pos == digits.size()) {
			res.push_back(tmp);
			return;
		}
		int num = digits[pos] - '0';  //取出输入字符串中的单个数字
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
		for (auto e : nums)  //将所有数全部异或==两个只出现一次元素之间的异或
			tmp ^= e;
		int i = 0;
		while (!(tmp&(1 << i)))  //找到tmp二进制中第一个1,说明两个只出现一次的元素在这个比特位是不一样的
			++i;
		for (auto e : nums) {
			if (e&(1 << i))  //二进制第i位为1的全部^
				a ^= e;
			else          //二进制第i位不为1的全部^
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