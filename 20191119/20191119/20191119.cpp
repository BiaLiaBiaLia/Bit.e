#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//参数解析
/*
在命令行输入如下命令：
xcopy  / s c:\ d : \，
各个参数如下： 
参数1：命令字xcopy 
参数2：字符串 / s
参数3：字符串c : \
参数4 : 字符串d : \
请编写一个参数解析程序，实现将命令行各个参数解析出来。
解析规则： 
1.参数分隔符为空格 
2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。
比如在命令行输入xcopy  / s “C:\program files” “d : \”时，参数仍然是4个，
第3个参数应该是字符串C : \program files，而不是C : \program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
3.参数不定长
4.输入由用例保证，不会出现不符合要求的输入 
*/
#if 0
int main()
{
	string str,s,r;
	getline(cin, str);
	int len = str.length();
	vector<string> tmp;
	int count = 0;

	for (int i = 0; i < len; ++i) {

		if (str[i] != ' ') {
			if (str[i] == '\"') {
				continue;
			}
			s += str[i];
		}
		else {
			tmp.push_back(s);
			s = r;
			++count;
		}
	}
	tmp.push_back(s);
	cout << ++count << endl;

	for (auto &e:tmp)
	{
		cout << e << endl;
	}

	system("pause");
	return 0;
}
#endif

//跳石板
int main() {
	int N, M;
	while (cin >> N >> M) {
		vector<int> steps(M + 1, INT_MAX);
		steps[N] = 0;
		for (int i = N; i <= M; i++) {
			if (steps[i] == INT_MAX) {
				continue;
			}
			for (int j = 2; (j*j) <= i; j++) {
				if (i%j == 0) {
					if (i + j <= M) {
						steps[i + j] = min(steps[i] + 1, steps[i + j]);
					}
					if (i + (i / j) <= M) {
						steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
					}

				}

			}
		}
		if (steps[M] == INT_MAX) {
			steps[M] = -1;
		}
		cout << steps[M] << endl;
	}

	system("pause");
	return 0;
}