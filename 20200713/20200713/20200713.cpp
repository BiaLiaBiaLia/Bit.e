#include <iostream>
#include <vector>
using  namespace std;

//��һ������a[N]˳����0~N-1��Ҫ��ÿ��������ɾ��һ��������ĩβʱѭ������ͷ�������У�
//�����һ����ɾ��������ԭʼ�±�λ�á���8����(N=7)Ϊ��:��0��1��2��3��4��5��6��7����
//0->1->2(ɾ��)->3->4->5(ɾ��)->6->7->0(ɾ��),���ѭ��ֱ�����һ������ɾ����
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