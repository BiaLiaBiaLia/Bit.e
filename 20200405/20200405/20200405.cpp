#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
	long f(long x, long y) {
		for (long z = x % y; z; z = x % y) {
			x = y;
			y = z;
		}
		return y;
	}
	long f1(long long num1, long num2) {//最小公倍数
		return num1 * num2 / f(num1, num2);
	}
	string f2(long mol, long den) {
		if (mol == 0) {
			return "0";
		}
		string res;
		long tmp = f(mol, den);
		mol /= tmp, den /= tmp;
		tmp = mol / den;
		if (tmp > 0) {
			res = to_string(tmp);
			tmp = mol % den;
			if (tmp) {
				res += (" " + to_string(labs(tmp)) + "/" + to_string(labs(den)));
			}
		}
		else if (tmp < 0) {
			res = "(" + to_string(tmp);
			tmp = mol % den;
			if (tmp) {
				res += (" " + to_string(labs(tmp)) + "/" + to_string(labs(den)));
			}
			res += ")";
		}
		else {//分子小于分母
			if ((mol < 0 && den < 0) || (mol > 0 && den > 0)) {
				res = (to_string(labs(mol)) + "/" + to_string(labs(den)));
			}
			else {
				res = "(-" + (to_string(labs(mol)) + "/" + to_string(labs(den))) + ")";
			}
		}
		return res;
	}
public:
	vector<string> fun(string& smol1, string& sden1, string& smol2, string& sden2) {
		long mol1 = atol(smol1.c_str());
		long den1 = atol(sden1.c_str());
		long mol2 = atol(smol2.c_str());
		long den2 = atol(sden2.c_str());
		vector<string> res(4);
		string num1 = f2(mol1, den1), num2 = f2(mol2, den2);
		long n = f1(den1, den2);//最小公倍数
		res[0] = num1 + " + " + num2 + " = " + f2(n / den1 * mol1 + n / den2 * mol2, n);
		res[1] = num1 + " - " + num2 + " = " + f2(n / den1 * mol1 - n / den2 * mol2, n);
		res[2] = num1 + " * " + num2 + " = " + f2(mol1 * mol2, den1 * den2);
		if (mol2 == 0) {
			res[3] = num1 + " / " + num2 + " = " + "Inf";
		}
		else {
			res[3] = num1 + " / " + num2 + " = " + f2(mol1 * den2, den1 * mol2);
		}
		return res;
	}
};

int main() {
	string mol1, mol2, den1, den2;
	Solution s;
	while (getline(cin, mol1, '/') && cin >> den1 && getline(cin, mol2, '/') && cin >> den2) {
		for (auto& s : s.fun(mol1, den1, mol2, den2)) {
			cout << s << endl;
		}
	}

	system("pause");
	return 0;
}