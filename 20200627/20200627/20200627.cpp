#include <iostream>
using namespace std;

//С������������һ����¥����С������վ��¥���Ĳ�ͬ�㣬����С��վ��¥��������N�ף�
//����������������£�ÿ����غ������ϴ�����߶ȵ�һ�룬���Դ�����ֱ��ȫ���䵽���治����
//��4��С��һ�������˶����ף�(���ֶ�Ϊ����)
//
//�����ĸ�����A, B, C, D���뷵����������
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