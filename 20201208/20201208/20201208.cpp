#include<iostream>
#include<vector>
#include<string>
using namespace std;


//²ÎÊı½âÎö
/*
int main() {
	string str, stt;
	int i = 0;
	bool flag = 0;
	vector<string> arr;
	while (getline(cin, str)) {
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '"') {
				flag = ~flag;
			}
			else {
				if (str[i] == ' ' && flag == 0) {
					arr.push_back(stt);
					stt = "";
				}
				else {
					if (str[i] != '"')
						stt += str[i];
				}
			}
		}
		arr.push_back(stt);
		cout << arr.size() << endl;
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << endl;
		}
	}

	system("pause");
	return 0;
}
*/

int main()
{
	vector<string> res;
	string str, tmp;
	while (getline(cin, str)) {
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == '"') {
				++i;
				while (str[i] != '"' && i < str.length()) {
					tmp += str[i];
					++i;
				}
			}
			else if (str[i] == ' ') {
				res.push_back(tmp);
				tmp = "";
			}
			else
				tmp += str[i];
		}
		res.push_back(tmp);
		cout << res.size() << endl;
		for (auto e : res)
			cout << e << endl;
	}
	return 0;
}