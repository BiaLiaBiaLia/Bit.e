#include <iostream>
using namespace std;

//��1+2+3+������+n  ����ʹ�ó˳����͹ؼ���
class Solution {
public:
	int Sum_Solution(int n) {
		int res = n;
		res && (res += Sum_Solution(n - 1));  //ǰ����������Ͳ���Ҫ�жϺ���ĵݹ��ˣ��ݹ����
		return res;
	}
};

int main()
{
	Solution s;
	int n;
	while (cin >> n) {
		cout << s.Sum_Solution(n) << endl;
	}

	system("pause");
	return 0;
}