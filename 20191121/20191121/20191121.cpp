#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

//��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1��
//������������� a��b�������һ���㷨�����a��b�������������ȵı�š�
//��������int a, b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ��������
#if 0
class LCA {//���������и����ɣ����ڵ���=�ӽڵ���/2
public:
	int getLCA(int a, int b) {
		if (a == b)//����Ϊͬһ�ڵ�
			return a;
		while (a != b) {
			if (a > b) {
				a /= 2;
			}
			else
				b /= 2;
		}
		return a;
	}
};
#endif

//��ʯ��
//С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
//����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK��ʯ��,С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����
//������K + X(XΪK��һ����1�ͱ�����Լ��)��λ�á�
//С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե���

int main() {//������±�Ϊ��i��ʯ�壬�����ڴ�ŵ���������Ҫ���ٲ��ܵ���(���ٲ���)
	int N, M;
	while (cin >> N >> M) {
		vector<int> v(M + 1, INT_MAX);//��������v�����M+1�����ݣ���ʼ��ΪINT_MAX��Ҳ��Ϊ������
		v[N] = 0;//��ʼλ��Ϊv[N],
		for (int i = N; i <= M; i++) {
			if (v[i] == INT_MAX) {
				continue;
			}
			for (int j = 2; (j*j) <= i; j++) {
				if (i%j == 0) {
					if (i + j <= M) {
						v[i + j] = min(v[i] + 1, v[i + j]);//�Ƚϴ�����ٵĲ���
					}
					if (i + (i / j) <= M) {
						v[i + (i / j)] = min(v[i] + 1, v[i + (i / j)]);
					}
				}
			}
		}
		if (v[M] == INT_MAX) {
			v[M] = -1;
		}
		cout << v[M] << endl;
	}

	system("pause");
	return 0;
}