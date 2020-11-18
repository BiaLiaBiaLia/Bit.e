#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int i = 0;  //�ӵ�0�ż���վ��ʼ����
		int n = gas.size();  //һ���ж��ټҼ���վ
		while (i < n) {
			int sumofgas = 0;  //�ܹ��ӵ���
			int sumofcost = 0;  //�ܹ����ĵ���
			int count = 0;  //��¼�߹�����վ�ĸ���
			while (count < n) {  //�˳��������߹������еļ���վ
				int j = (count + i) % n;  //վ��ѭ����  (�߹���+��ʼλ��)%n=��ǰλ��
				sumofgas += gas[j];
				sumofcost += cost[j];

				if (sumofcost > sumofgas)  //���Ĵ��ڻ�ȡ���˳�
					break;
				else
					++count;
			}
			if (count == n)  //˵������һȦ��
				return i;  //������ʼվ����
			else
				i = i + count + 1;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };

	cout << s.canCompleteCircuit(gas, cost) << endl;

	system("pause");
	return 0;
}