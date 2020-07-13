#include <iostream>
#include <vector>
using  namespace std;

//有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，
//求最后一个被删掉的数的原始下标位置。以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，
//0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。
int main()
{
	int n;
	while (cin >> n)
	{
		if (n > 1000)
			n = 1000;
		vector<int> num;
		for (int i = 0; i < n; i++)
			num.push_back(i);
		int i = 2;
		while (num.size() != 1)
		{
			vector<int>::iterator it = num.begin() + (i % num.size());
			num.erase(it);
			i = (i + 2) % num.size();
		}
		cout << num[0] << endl;
	}

	system("pause");
	return 0;
}