#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
//2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo->hello
//3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC
int main()
{
	int N;
	cin >> N;
	string str;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		for (int j = 0; j + 2 < str.size(); ) {
			if (str[j] == str[j + 1] && (str[j + 1] == str[j + 2])) {
				// 三连模式
				while ((j + 2 < str.size()) && (str[j + 1] == str[j + 2])) {
					str.erase(j + 2, 1);
				}
			}
			else if (j + 3 < str.size() && str[j] == str[j + 1] && str[j + 2] == str[j + 3]) {
				while (j + 3 < str.size() && str[j + 2] == str[j + 3]) {
					str.erase(j + 3, 1);
				}
			}
			else
				j++;
		}
		cout << str << endl;
	}

	system("pause");
	return 0;
}