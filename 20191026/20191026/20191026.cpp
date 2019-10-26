#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

//前K个高频单词
class Soultion
{
public:
	class Compare
	{
	public:
		bool operator()(const pair<string, int>& left, const pair<string, int>& right)
		{
			return left.second > right.second;
		}
	};

	vector<string> topKFrequent(vector<string>& words,int k)
	{
		map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i)
			++(m[words[i]]);

		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());

		// 将相同次数的单词放在set中，然后再放到vector中         
		set<string> s;         
		size_t count = 0;   // 统计相同次数单词的个数
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms)
		{
			if (!s.empty())
			{
				// 相同次数的单词已经全部放到set中
				if (count != e.second)
				{
					if (s.size() < leftCount)
					{
						ret.insert(ret.end(), s.begin(), s.end());
						leftCount -= s.size();
						s.clear();
					}
					else
					{
						break;
					}
				}
			}
			count = e.second;
			s.insert(e.first);
		}
		for (auto& e : s)
		{
			if (0 == leftCount)
				break;

			ret.push_back(e);
			leftCount--;
		}
		return ret;
	}
};