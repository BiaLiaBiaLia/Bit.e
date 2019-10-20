#include <iostream>
using namespace std;

#include <string>
#include <map>

#if 0
void TestMap1()
{
	map<string, string> m;
	m.insert(pair<string, string>("����", "������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("�ν�", "��ʱ��"));
	m.insert(make_pair("�����", "ĸҹ��"));

	cout << m.size() << endl;
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "<--->" << it->second << endl;
		++it;
	}
	cout << endl;

	m.insert(make_pair("����", "��ţ"));
	for (auto& e : m)
		cout << e.first << "<--->" << e.second << endl;
	cout << endl;

	cout << m["�ν�"] << endl;
	cout << m["����"] << endl;
	m["³��"] = "������";
	// <"³��"��"">
}
#endif

#if 0
// ����key����
void TestMap2()
{
	map<int, int> m;
	int array[] = { 5, 1, 0, 9, 7, 3, 6, 4, 2, 8 };
	for (size_t i = 0; i < 10; ++i)
		m.insert(make_pair(array[i], i));

	for (auto e : m)
		cout << e.first << "--->" << e.second << endl;
}

int main()
{
	//TestMap1();
	TestMap2();
	return 0;
}
#endif


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

	// map�е�key�����޸�
	//it->first = "����";   // ����ʧ��

	// ���һ��Ҫ�ģ���ɾ����key�������²���
	pair<string, string> data("����", it->second);
	if (it != m.end())
		m.erase(it);

	m.insert(data);

	m.clear();

	system("pause");
	return 0;
}
