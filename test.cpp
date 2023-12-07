/*#include"User.h"
#include"Book.h"
#include"Library.h"*/
#include<iostream>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>

using namespace std;

class Date
{
public:
	int date;
	int month;
	int year;
	
	//Compare dates: 1 if x is the day before, 0 if y is the day before 
	Date() = default;
	Date(int d, int m, int y) : date(d), month(m), year(y) {}
	bool cmp(Date x, Date y)
	{
		if(x.year < y.year)
			return 1;
		else if(x.year == y.year)
		{
			if(x.month < y.month)
				return 1;
			else if(x.month == y.month)
			{
				if(x.date < y.date)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	friend ostream& operator<<(ostream& out, const Date& date)
	{
		out << date.date << "/" << date.month << "/" << date.year;
		return out;
	}
};

void mainMenu()
{
	cout << "Welcome to the Library Management System" << endl;
	cout << "1. Login" << endl;
	cout << "2. Register" << endl;
	cout << "3. Exit" << endl;
    int choice, choice2;
    cin >> choice;
	system("cls");
	if (choice == 1)
        cout << "Welcome and goodbye";
    cin >> choice2;
    cout << choice2;
}



int main()
{
	mainMenu();
}