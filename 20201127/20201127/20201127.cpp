#include <iostream>
#include <vector>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month) {
		vector<int> years = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)  //满足闰年的条件
			years[2] = 29;
		return years[month];
	}


	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}


	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{}


	// 赋值运算符重载
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}


	// 析构函数
	~Date() {
		//cout << "~Date():" << this << endl;
	}


	// 日期+=天数
	Date& operator+=(int day) {
		if (day < 0) {
			*this = *this - day;
			return *this;
		}
		*this = *this + day;
		return *this;
	}


	// 日期+天数
	Date operator+(int day) {
		Date tmp(*this);
		if (day < 0) {  // 加上一个负数的天数，相当于减去一个正数的天数
			day = -day;
			return tmp - day;
		}
		tmp._day += day;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month)) {  //判断是否大于tmp当前月份的最大天数
			tmp._day -= GetMonthDay(tmp._year, tmp._month);  //大于就减去当月的最大天数
			tmp._month++;                                    //月份+1
			if (tmp._month > 12) {
				tmp._year++;
				tmp._month = 1;
			}
		}
		return tmp;
	}


	// 日期-天数
	Date operator-(int day) {
		Date tmp(*this);
		if (day < 0) {
			day = -day;
			return tmp + day;
		}
		tmp._day -= day;
		while (tmp._day < 0) {
			--tmp._month;        
			if (tmp._month < 1) {
				--tmp._year;
				tmp._month = 12;
			}
			tmp._day += GetMonthDay(tmp._year, tmp._month);
		}
		return tmp;
	}


	// 日期-=天数
	Date& operator-=(int day) {
		if (day < 0) {
			*this = *this + day;
			return *this;
		}
		*this = *this - day;
		return *this;
	}


	// 前置++
	Date& operator++() {
		*this += 1;
		return *this;
	}


	// 后置++
	Date operator++(int) {
		Date tmp(*this);
		*this += 1;
		return tmp;
	}


	// 后置--
	Date operator--(int) {
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}


	// 前置--
	Date& operator--() {
		*this -= 1;
		return *this;
	}

	// >运算符重载
	bool operator>(const Date& d) {
		if ((_year > d._year) ||
			(_year == d._year&&_month > d._month) ||
			(_year == d._year&&_month == d._month&&_day > d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	// ==运算符重载
	bool operator==(const Date& d) {
		return ((_year == d._year) && (_month == d._month) && (_day == d._day));
	}


	// >=运算符重载
	inline bool operator >= (const Date& d) {
		return *this > d || *this == d;
	}


	// <运算符重载
	bool operator < (const Date& d) {
		if ((_year < d._year) ||
			(_year == d._year&&_month < d._month) ||
			(_year == d._year&&_month == d._month&&_day < d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	// <=运算符重载
	bool operator <= (const Date& d) {
		return *this < d || *this == d;
	}


	// !=运算符重载
	bool operator != (const Date& d) {
		return !(*this==d);
	}


	// 日期-日期 返回天数
	int operator-(const Date& d) {
		int days = 0;
		Date max_date(*this);
		Date min_date(d);
		if (max_date < min_date) {
			max_date = min_date;
			min_date = *this;
		}
		while (max_date != min_date) {
			--max_date;
			++days;
		}
		return days;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 11, 27);
	Date d2(1999, 12, 1);
	cout << d2 - d1 << endl;
	d1++;
	d1--;
	--d1;
	++d1;
	d1-= 999;
	d1+=999;
	d1 += -999;
	d1 -= -999;
	 
	system("pause");
	return 0;
}