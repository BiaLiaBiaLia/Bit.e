#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

//求最小公倍数
#if 0
int main()
{
	int A, B;
	cin >> A >> B;

	int t1 = A > B ? A : B;//存大数
	int t2 = A > B ? B : A;//存小数
	int i = 1;
	while ((i*t1) % t2 != 0) {
		++i;
	}
	cout << i * t1 << endl;

	system("pause");
	return 0;
}
#endif

//两种排序方法
vector<string> vs;
//字典序排列
bool lexicographically() {
	int i = 0;
	while ((i + 1) < vs.size()) {//确保至少有两个字符串
		if (vs[i].compare(vs[i + 1]) > 0)
			return 0;
		++i;
	}
	return 1;
}

//长度排列
bool lengths() {
	int i = 0;
	while (i + 1 < vs.size()) {
		if (vs[i].size() > vs[i + 1].size())
			return 0;
		++i;
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		vs.push_back(s);
	}

	int a = lexicographically();
	int b = lengths();

	if (1 == a && 0 == b)
		cout << "lexicographically" << endl;
	else if (1 == a && 1 == b)
		cout << "both" << endl;
	else if (0 == a && 1 == b)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;

	system("pause");
	return 0;
}
