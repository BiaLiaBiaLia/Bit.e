#include <iostream>
#include <vector>
using namespace std;


//��������
//ʱ�临�Ӷ�O(n2)   �ռ临�Ӷ�O(1)    �ȶ�
void InsertSort(vector<int>& nums) {
	
	for (size_t i = 0; i < nums.size(); ++i) {
		//����������Ԫ��
		int tmp = nums[i];
		//������Ԫ��ǰһ��λ�õ��±�
		int last = i - 1;
		while (last >= 0 && tmp < nums[last]) { //������Ԫ��С��last�ͽ�last+1λ�õ�Ԫ�ظ��ǵ���lastǰ��һ��Ԫ��
			nums[last + 1] = nums[last];
			--last;
		}
		nums[last + 1] = tmp;
	}
}

void PrintVec(vector<int> nums) {
	for (auto e : nums)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> nums = { 3,8,2,9,5,6,0,7,1,4 };
	PrintVec(nums);
	InsertSort(nums);
	PrintVec(nums);

	system("pause");
	return 0;
}
