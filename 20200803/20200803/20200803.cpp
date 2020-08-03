#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct comp {
	bool operator()(const int &a, const int &b) {
		return a < b;
		//我们需要大堆，所以我们采用降序排序
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
				//采用指定容器实现大堆
				for(int i = 0; i < input.size(); i++){ 
					if( i < k){
						//前k个元素，直接放入，priority_queue内部会降序排序
						queue.push(input[i]);
					}
					else{
						if(input[i] < queue.top()){
							//如果新的数据，小于queue首部元素（大值），进行更新
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