#include <iostream>
using namespace std;

//小东和三个朋友一起在楼上抛小球，他们站在楼房的不同层，假设小东站的楼层距离地面N米，
//球从他手里自由落下，每次落地后反跳回上次下落高度的一半，并以此类推直到全部落到地面不跳，
//求4个小球一共经过了多少米？(数字都为整数)
//
//给定四个整数A, B, C, D，请返回所求结果。
class Balls {
public:
	float cal(int y)
	{
		float x = (float)y;
		float sum = x;
		while (x > 0.01)
		{
			x = x / 2;
			sum += 2 * x;
		}
		return sum;
	}
	int calcDistance(int A, int B, int C, int D) {
		// write code here
		float dist = cal(A) + cal(B) + cal(C) + cal(D);
		int sum = dist + 0.5;
		return sum;
		/*
		sum+=B;
		while((B+1)/2){
			B=(B+1)/2;
			sum+=B;
		}
		sum+=C;
		while((C+1)/2){
			C=(C+1)/2;
			sum+=C;
		}
		sum+=D;
		while((D+1)/2){
			D=(D+1)/2;
			sum+=D;
		}
		*/
		return sum;
	}
};

int main()
{
	int A, B, C, D;
	while (cin >> A >> B >> C >> D) {
		Balls s;
		cout << s.calcDistance(A, B, C, D) << endl;
	}

	system("pause");
	return 0;
}