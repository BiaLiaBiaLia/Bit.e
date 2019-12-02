#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Î¢ÐÅºì°ü
class Gift {
public:
	int getValue1(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		int x = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < gifts.size(); ++i) {
			if (x == gifts[i])
				++count;
		}
		if (count > n / 2)
			return x;
		else
			return 0;
	}

	int getValue2(vector<int> gifts, int n) {
		int max = gifts[0];
		for (int i = 1; i < n; ++i) {
			if (gifts[i] > max)
				max = gifts[i];
		}

		vector<int> v(max + 1);

		for (int i = 0; i < n ; ++i) {
			++v[gifts[i]];
		}

		int count = v[0], z = 0;
		for (int i = 1; i <= max; ++i) {
			if (v[i] > count) {
				count = v[i];
				z = i;
			}
		}
		if (count > n / 2)
			return z;
		else
			return 0;
	}

	int getValue3(vector<int> gifts, int n) {
		int x = gifts[0];
		int count = 1;
		for (int i = 1; i < n; ++i) {
			if (x == gifts[i])
				++count;
			else
				--count;

			if (0 == count)
				x = gifts[i];
		}

		if (count > 0)
			return x;
		else
			return 0;
	}
};

int main()
{
	Gift g;
	vector<int> v{ 1,2,3,2,2 };
	int size = v.size();

	cout << g.getValue1(v, size) << " " << g.getValue2(v, size) << endl;
	cout << g.getValue3(v, size) << endl;

	system("pause");
	return 0;
}