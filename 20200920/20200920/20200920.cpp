#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (cin >> str) {
		for (int i = 1; i <= str.size(); ++i) {  //str=abababab

			string res(str, 0, i);   //res=ab
			string tmp = res;      //tmp=ab
			while (tmp.size() < str.size()) {
				tmp += res;             //tmp=abababab
			}
			if (tmp.size() == str.size() && 0 == str.compare(tmp)) {
				cout << res << endl;
				break;
			}
			else
				continue;
		}
	}


	return 0;
}
