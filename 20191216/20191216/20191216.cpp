#include <iostream>
#include <vector>
using namespace std;

//˳ʱ���ӡ����
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		result.clear();
		int row = matrix.size();  //����
		int collor = matrix[0].size();  //����
		int circle = ((row < collor ? row : collor) - 1) / 2 + 1;  //Ȧ��
		for (int i = 0; i < circle; ++i) {
			//��ӡ�����ҵ���
			for (int j = i; j < collor - i; ++j) {
				result.push_back(matrix[i][j]);
			}
			//��ӡ���ϵ��µ���
			for (int m = i + 1; m < row - i; ++m) {
				result.push_back(matrix[m][collor - i - 1]);
			}
			//��ӡ���ҵ������,�ж��Ƿ���ظ���ӡ
			for (int n = collor - i - 2; (n >= i) && (row - i - 1 != i); --n) {
				result.push_back(matrix[row - i - 1][n]);
			}
			//��ӡ���µ��ϵ���,�ж��Ƿ���ظ���ӡ
			for (int x = row - i - 2; (x > i) && (collor - i - 1 != i); --x) {
				result.push_back(matrix[x][i]);
			}
		}
		return result;
	}
};

int main()
{
	vector<vector<int> > vv{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	Solution s;
	vector<int> res = s.printMatrix(vv);
	for (auto &e : res)
		cout << e <<" ";
	
	cout << endl;

	system("pause");
	return 0;
}