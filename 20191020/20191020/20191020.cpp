#include <iostream>
using namespace std;

#include <string>
#include <map>

#if 0
void TestMap1()
{
	map<string, string> m;
	m.insert(pair<string, string>("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("宋江", "及时雨"));
	m.insert(make_pair("孙二娘", "母夜叉"));

	cout << m.size() << endl;
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "<--->" << it->second << endl;
		++it;
	}
	cout << endl;

	m.insert(make_pair("李逵", "铁牛"));
	for (auto& e : m)
		cout << e.first << "<--->" << e.second << endl;
	cout << endl;

	cout << m["宋江"] << endl;
	cout << m["武松"] << endl;
	m["鲁达"] = "花和尚";
	// <"鲁达"，"">
}
#endif

#if 0
// 关于key有序
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
	m.insert(pair<string, string>("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("宋江", "及时雨"));
	m.insert(make_pair("孙二娘", "母夜叉"));

	cout << m.count("宋江") << endl;
	cout << m.count("鲁达") << endl;

	auto it = m.find("宋江");

	// map中的key不能修改
	//it->first = "黑三";   // 编译失败

	// 如果一定要改，先删除该key，再重新插入
	pair<string, string> data("黑三", it->second);
	if (it != m.end())
		m.erase(it);

	m.insert(data);

	m.clear();

	system("pause");
	return 0;
}
