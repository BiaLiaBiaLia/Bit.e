#include <iostream>
#include <vector>
using namespace std;


//十进制转其他进制
int main()
{
	vector<char> vec = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	int M, N;
	while (cin >> M >> N) {
		vector<char> res;
		while (M) {
			res.push_back(vec[M%N]);
			M /= N;
		}
		for (int i = res.size() - 1; i >= 0; --i)
			cout << res[i];
		cout << endl;
	}

	system("pause");
	return 0;
}
