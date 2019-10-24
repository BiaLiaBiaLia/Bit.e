#include <iostream>
#include <string>
#include <map>
using namespace std;

#if 0
void TestMap1()
{
	map<string, string>m;
	m.insert(pair<string, string>("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("宋江", "及时雨"));
	m.insert(make_pair("孙二娘", "母夜叉"));

	cout << m.size() << endl;
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "----" << it->second << endl;
		++it;
	}
	cout << endl;

	m.insert(make_pair("李逵","铁牛"));
	for (auto& e : m)
		cout << e.first << "----" << e.second << endl;
	cout << endl;

	cout << m["宋江"] << endl;
	cout << m["武松"] << endl;
	m["鲁达"] = "花和尚";

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
	m.insert(pair<string, string>("李逵", "黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("宋江", "及时雨"));
	m.insert(make_pair("孙二娘", "母夜叉"));

	cout << m.count("宋江") << endl;
	cout << m.count("鲁达") << endl;

	auto it = m.find("宋江");

	//map中的key不能修改
	//it->first="张三";    //编译失败

	//如果要改，先删除此条键值对，再重新插入
	pair<string, string>data("张三", it->second);
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
	//map中的元素默认按照less(小于)的方式进行比较---升序
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
//set----去重，排序
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