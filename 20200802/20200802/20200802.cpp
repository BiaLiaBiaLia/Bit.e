#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int> >result;
	//�����Ǹ������
	//��������λ�ã���ʾ��ʵ�ͽ�����start��end֮�����һ����������������
	//������㣬�൱�ڶ�̬���ڵ����ߣ������䴰���ڵ�ֵ�ĺ���ȷ�����ڵ�λ�úʹ�С
	//���ǲ��ñ����䷽ʽ���н��
	int low = 1;
	int high = 2;
	while(low < high){
		//�����������ģ���Ϊ1��һ�����У���ô��͹�ʽ��(a0+an)*n/2
		//����ĵ�low��high�������λ�ã�Ҳ�����Ӧ��ֵ
		int total = (low + high)*(high - low + 1)/2;
		//ע�⣬�Ǳ�����Ŷ 
		if(sum == total){
			//˵���������е����ݺͷ���Ҫ��
			vector<int> v;
			for(int i = low; i <= high; i++){
				v.push_back(i);
			}
		result.push_back(v);
	//ע�⣬����Ҫ��֤�õ�һ������֮����һ������ֻ�ܴ���һ�����ݿ�ʼ
	//��high���Զ�����
		low++;
		}
		else if(total < sum){
			//˵�������������е����ݺ�С��sum��Ӧ����������,�԰�����������
			high++;
		}
		else{
			//˵�������������е����ݺʹ���sum��Ӧ����С����,�԰�����������
			low++;
		}
	}
	return result;
	}
};

int main()
{

	Solution s;
	vector<vector<int>> vv = s.FindContinuousSequence(10);

	system("pause");
	return 0;
}