#include <iostream>
using namespace std;

#if 0
int sum(int n, int m) {
	if (0 == n || 0 == m)
		return 1;
	return sum(n - 1, m) + sum(n, m - 1);
}
int main()
{
	int n, m;
	while (cin >> n >> m)
		cout << sum(n, m) << endl;

	return 0;
}
#endif

#include <iostream>
using namespace std;

//Â·¾¶·½Ê½
int sum(int n, int m) {
	if (0 == n || 0 == m)
		return 1;
	return sum(n - 1, m) + sum(n, m - 1);
}
int main()
{
	int n, m;
	while (cin >> n >> m)
		cout << sum(n, m) << endl;

	return 0;
}