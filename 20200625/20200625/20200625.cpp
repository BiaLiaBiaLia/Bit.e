#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//1. ����ͬ������ĸ����һ��һ����ƴд����ȥ��һ���ľͺ��������� helllo -> hello
//2. ����һ������ĸ��AABB�ͣ�����һ��һ����ƴд����ȥ���ڶ��Ե�һ����ĸ�ͺ��������� helloo->hello
//3. ����Ĺ������ȡ������ҡ�ƥ�䣬�������AABBCC����ȻAABB��BBCC���Ǵ���ƴд��Ӧ�����ȿ����޸�AABB�����ΪAABCC
int main()
{
	int N;
	cin >> N;
	string str;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		for (int j = 0; j + 2 < str.size(); ) {
			if (str[j] == str[j + 1] && (str[j + 1] == str[j + 2])) {
				// ����ģʽ
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