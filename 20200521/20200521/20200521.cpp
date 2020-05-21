#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�������ٳ��ж���λͬѧ��ʹ��ʣ�µ�ͬѧ�ųɺϳ�����
//˵����
//Nλͬѧվ��һ�ţ�������ʦҪ�����е�(N - K)λͬѧ���У�ʹ��ʣ�µ�Kλͬѧ�ųɺϳ����Ρ�
//�ϳ�������ָ������һ�ֶ��Σ���Kλͬѧ���������α��Ϊ1��2����K�����ǵ���߷ֱ�ΪT1��T2������TK��
//�����ǵ�����������i��1 <= i <= K��ʹ��T1 < T2<......<Ti - 1 < Ti > Ti + 1>......>TK
//��������ǣ���֪����Nλͬѧ����ߣ�����������Ҫ��λͬѧ���У�����ʹ��ʣ�µ�ͬѧ�ųɺϳ����Ρ�

void deal(vector<int>&stu, vector<int>&res) {
	vector<int> best(stu.size(), 9999);
	best[0] = stu[0];
	res.push_back(1);
	for (int i = 1; i < stu.size(); i++) {
		int pos = lower_bound(best.begin(), best.end(), stu[i]) - best.begin();
		res.push_back(pos + 1);
		best[pos] = stu[i];
	}
}

int main() {
	int num = 0;
	while (cin >> num) {
		vector<int> stu;
		vector<int> asc;
		vector<int> desc;
		while (num--) {
			int tmp = 0;
			cin >> tmp;
			stu.push_back(tmp);
		}
		deal(stu, asc);
		reverse(stu.begin(), stu.end());
		deal(stu, desc);
		reverse(desc.begin(), desc.end());
		int max_ = 0;
		for (int i = 0; i < stu.size(); i++)
			max_ = max(asc[i] + desc[i] - 1, max_);
		cout << stu.size() - max_ << endl;
	}

	system("pause");
	return 0;
}