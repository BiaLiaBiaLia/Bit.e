#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	using namespace std;
	int powR;
	while (cin >> powR) {
		int ans = 0;
		int max_num = sqrt((double)powR);
		for (int i = 0; i <= max_num; i++) {
			int temp = sqrt((double)(powR - i * i));
			if (temp * temp == powR - i * i) {
				if (i && temp) {
					ans += 4;
				}
				else {
					ans += 2;
				}
			}
		}
		cout << ans << endl;
	}

	system("pause");
	return 0;
}
