#include <iostream>
#include <string>
#include <map>
using namespace std;

#if 0
void TestMap1()
{
	map<string, string>m;
	m.insert(pair<string, string>("����", "������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("�ν�", "��ʱ��"));
	m.insert(make_pair("�����", "ĸҹ��"));

	cout << m.size() << endl;
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "----" << it->second << endl;
		++it;
	}
	cout << endl;

	m.insert(make_pair("����","��ţ"));
	for (auto& e : m)
		cout << e.first << "----" << e.second << endl;
	cout << endl;

	cout << m["�ν�"] << endl;
	cout << m["����"] << endl;
	m["³��"] = "������";

	cout << m.size() << endl;
}

void TestMap2()
{
	map<int, int> m;
	int array[] = { 3,6,4,2,8,5,1,0,9,7 };
	for (size_t i = 0; i < 10; ++i)
		m.insert(make_pair(array[i], i));

	for (auto e : m)
		cout << e.first << "----" << e.second << endl;
}

int main()
{
	TestMap1();
	TestMap2();

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	map<string, string> m;
	m.insert(pair<string, string>("����", "������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("�ν�", "��ʱ��"));
	m.insert(make_pair("�����", "ĸҹ��"));

	cout << m.count("�ν�") << endl;
	cout << m.count("³��") << endl;

	auto it = m.find("�ν�");

	//map�е�key�����޸�
	//it->first="����";    //����ʧ��

	//���Ҫ�ģ���ɾ��������ֵ�ԣ������²���
	pair<string, string>data("����", it->second);
	if (it != m.end())
		m.erase(it);

	m.insert(data);

	m.clear();

	system("pause");
	return 0;
}
#endif

#include <functional>

#if 0
int main()
{
	//map�е�Ԫ��Ĭ�ϰ���less(С��)�ķ�ʽ���бȽ�---����
	map<int, int> m1;
	int array[] = { 3,6,4,2,8,5,1,0,9,7 };
	for (size_t i = 0; i < 10; ++i)
		m1.insert(make_pair(array[i], i));

	for (auto& e : m1)
		cout << e.first << "----" << e.second << endl;

	system("pause");
	return 0;
}
#endif

#include <set>
//set----ȥ�أ�����
int main()
{
	int array[] = { 5, 2, 9, 0, 8, 1, 7, 3, 6, 4, 5, 2, 9, 0, 8, 1, 7, 3, 6, 4 };
	set<int> s;
	for (auto& e : array)
		s.insert(e);

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	system("pause");
	return 0;
}