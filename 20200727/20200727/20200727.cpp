#include <iostream>
#include <vector>
using namespace std;

//����һ���ǿ��������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,������ ��No��
//�������������������������ֶ�������ͬ��
 
class Solution {
public:
	bool VerifySquenceOfBSTCore(vector<int> &sequence, int start, int end) {
	if (start >= end) {
		//�ڲ��ϲ��ҹ����У����򲻶���С��Ϊ��ʱ��֤��֮ǰ�����з�Χ������������
		//Ҳ������һ��BST
		return true;
	}
	//�õ�root�ڵ��ֵ
	int root = sequence[end];
	//�ȱ�����벿�֣�Ҳ�������嶼Ҫ��rootС���õ�����������
	int i = 0;
	while(i < end && sequence[i] < root){
		i++;
	}
	//�ڼ���������Ƿ���ϴ���root��������Ҫ��i��ʼ��Ҳ�����Ұ벿�ֵĿ�ʼ
	for(int j = i; j < end; j++){
		if(sequence[j] < root){
			//�ںϷ�λ�ô�����ǰֵС��root��������BST����
			return false;
		}
	}
	//�ߵ������˵������ǰ�����������󡣵�����������Ŀ������ˣ���Ҫ�ڼ��left��right�� ���Ƿ�Ҳ����
	return VerifySquenceOfBSTCore(sequence, 0, i-1) && VerifySquenceOfBSTCore(sequence, i, end-1);
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.empty()){
			return false;
		}
		return VerifySquenceOfBSTCore(sequence, 0, sequence.size()-1);
	}
};

