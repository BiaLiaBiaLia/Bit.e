#include <iostream>
#include <string>

using namespace std;

//ÄæÖÃ×Ö·û´®ÖĞµ¥´ÊµÄÎ»ÖÃ
//ÊäÈë£ºI like beijing.
//Êä³ö£ºbeijing. like I
int main()
{
	int i=0, j;
	string str;
	char tmp;
	getline(cin, str);
	j = str.length() - 1;
		while (j > i)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			--j;
			++i;
		}

	int begin, end;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			begin = i;
			while (str[i] && str[i] != ' ')
			{
				++i;
			}
			i = i - 1;
			end = i;
		}


		while (end > begin)
		{
			tmp = str[begin];
			str[begin] = str[end];
			str[end] = tmp;
			++begin;
			--end;
		}
		++i;
	}
	cout << str << endl;

	system("pause");
	return 0;
}