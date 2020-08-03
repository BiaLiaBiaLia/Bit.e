#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct comp {
	bool operator()(const int &a, const int &b) {
		return a < b;
		//������Ҫ��ѣ��������ǲ��ý�������
	}
};

		
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
				vector<int> list;
				if (input.size() == 0 || k <= 0 || k > input.size()) {
					return list;
				}
				priority_queue<int, vector<int>, comp> queue;
				//����ָ������ʵ�ִ��
				for(int i = 0; i < input.size(); i++){ 
					if( i < k){
						//ǰk��Ԫ�أ�ֱ�ӷ��룬priority_queue�ڲ��ή������
						queue.push(input[i]);
					}
					else{
						if(input[i] < queue.top()){
							//����µ����ݣ�С��queue�ײ�Ԫ�أ���ֵ�������и���
							queue.pop();
							queue.push(input[i]);
						}
					}
				}
				for(int i = 0; i < k; i++){
					list.push_back(queue.top());
					queue.pop();
				}
				return list;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 4,5,1,6,2,7,3,8 };

	vector<int> res = s.GetLeastNumbers_Solution(v, 4);

	system("pause");
	return 0;
}