#include <iostream>
#include<vector>
#include<forward_list>
using namespace std;

int main()
{
	int tp;
	vector<int> m, n;
	while (cin.peek() != EOF && cin.peek() != '\n')
	{
		cin >> tp;
		m.push_back(tp);
	}
	cin.ignore();
	while (cin.peek() != EOF && cin.peek() != '\n')
	{
		cin >> tp;
		n.push_back(tp);
	}
	cin.ignore();
	forward_list<int> list1(m.begin(), m.end());
	forward_list<int> list2(n.begin(), n.end());
	list1.merge(list2);
	for (auto temp : list1)
		cout << temp << " ";

	system("pause");
	return 0;
}