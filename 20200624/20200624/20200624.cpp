#include <iostream>
using namespace std;

//Z���Ļ���ϵͳ������ֵ1Ԫ��4Ԫ��16Ԫ��64Ԫ����4��Ӳ�ң��Լ���ֵ1024Ԫ��ֽ�ҡ�
//����СYʹ��1024Ԫ��ֽ�ҹ�����һ����ֵΪN (0 < N \le 1024)N(0<N��1024)����Ʒ���������������յ�����Ӳ�ң�
//��������:
//һ�У�����һ����N��
//������� :
//һ�У�����һ��������ʾ�����յ���Ӳ������

int main() {
	int n;
	cin >> n;
	int m = 1024 - n;
	int count = 0;
	count += m / 64;
	m %= 64;
	count += m / 16;
	m %= 16;
	count += m / 4;
	m %= 4;
	count += m / 1;
	cout << count << endl;

	system("pause");
	return 0;
}