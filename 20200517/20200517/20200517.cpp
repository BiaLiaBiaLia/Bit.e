#include <iostream>
using namespace std;

//数组中重复的数
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == nullptr || length <= 0)
			return false;
		for (int i = 0; i < length; ++i) {
			if (numbers[i] > (length - 1) || numbers[i] < 0)
				return false;
		}
		for (int i = 0; i < length; ++i) {
			while (numbers[i] != i) {
				if (numbers[i] == numbers[numbers[i]]) {
					*duplication = numbers[i];
					return true;
				}
				int temp = numbers[i];
				numbers[i] = numbers[temp];
				numbers[temp] = temp;
			}
		}
		return false;
	}
};

int main()
{
	int arr[] = { 2,3,1,0,2,5,3 };
	int len = sizeof(arr) / sizeof(int);
	int* res = new int;
	Solution s;
	cout << s.duplicate(arr, len, res) << endl;
	cout << *res << endl;

	system("pause");
	return 0;
}