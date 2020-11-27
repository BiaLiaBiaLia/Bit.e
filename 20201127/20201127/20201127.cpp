#include <iostream>
#include <vector>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month) {
		vector<int> years = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)  //�������������
			years[2] = 29;
		return years[month];
	}


	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}


	// �������캯��
	// d2(d1)
	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{}


	// ��ֵ���������
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}


	// ��������
	~Date() {
		//cout << "~Date():" << this << endl;
	}


	// ����+=����
	Date& operator+=(int day) {
		if (day < 0) {
			*this = *this - day;
			return *this;
		}
		*this = *this + day;
		return *this;
	}


	// ����+����
	Date operator+(int day) {
		Date tmp(*this);
		if (day < 0) {  // ����һ���������������൱�ڼ�ȥһ������������
			day = -day;
			return tmp - day;
		}
		tmp._day += day;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month)) {  //�ж��Ƿ����tmp��ǰ�·ݵ��������
			tmp._day -= GetMonthDay(tmp._year, tmp._month);  //���ھͼ�ȥ���µ��������
			tmp._month++;                                    //�·�+1
			if (tmp._month > 12) {
				tmp._year++;
				tmp._month = 1;
			}
		}
		return tmp;
	}


	// ����-����
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


	// ����-=����
	Date& operator-=(int day) {
		if (day < 0) {
			*this = *this + day;
			return *this;
		}
		*this = *this - day;
		return *this;
	}


	// ǰ��++
	Date& operator++() {
		*this += 1;
		return *this;
	}


	// ����++
	Date operator++(int) {
		Date tmp(*this);
		*this += 1;
		return tmp;
	}


	// ����--
	Date operator--(int) {
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}


	// ǰ��--
	Date& operator--() {
		*this -= 1;
		return *this;
	}

	// >���������
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


	// ==���������
	bool operator==(const Date& d) {
		return ((_year == d._year) && (_month == d._month) && (_day == d._day));
	}


	// >=���������
	inline bool operator >= (const Date& d) {
		return *this > d || *this == d;
	}


	// <���������
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


	// <=���������
	bool operator <= (const Date& d) {
		return *this < d || *this == d;
	}


	// !=���������
	bool operator != (const Date& d) {
		return !(*this==d);
	}


	// ����-���� ��������
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