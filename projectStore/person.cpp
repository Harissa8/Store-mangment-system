#include<iostream>
#include"Header.h"
#include<string.h>
#include<fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

using namespace std;

Person::Person()
{
	this->username = "empty";
	this->password = "empty";
}


void Person::set(string a, string b)
{
	this->username = a;
	this->password = b;
}

std::string Person::get_username()
{
	return username;
}

void Person::menu()
{
	int a = -1;
	system("cls");
	cout << "\n\t\t   STORE MANAGEMENT SYSTEM\n";
	cout << "=============================================================";
	cout << "\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu\n\n\t\t   4.Exit";
	cout << "\n\n=============================================================\n";
	cout << "\n Please Enter Your Choice (Numbers 1, 2, 3 or 4): ";

	while (true)
	{
		cin >> a;
		if (!cin || a <= 0 || a >= 5)
		{
			cout << "\n Please Enter Your Choice (Numbers 1, 2, 3 or 4): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}
	if (a == 1)
	{
		Dealer d;
		d = d.login();
		d.menu();
	}


	else if (a == 2)
	{
		Customer c;
		c = c.login();
		c.menu();
	}

	else if (a == 3)
	{
		Employee E;
		E = E.login();
		E.menu();
	}
	else if (a == 4)
	{
		remove("History.txt");
		exit(0);
	}
}


void Person::display()
{
	cout << "\n==================================================================";
	cout << "\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	cout << "\n\n==================================================================\n\n\n";
	cout << left << setw(20) << "PARTICULARS" << setw(20) << "STOCK AVAILABLE" << "PRICE";
	cout << "\n\n============================================================\n";

	fstream data;
	Product P;
	data.open("Products.txt", ios::in);
	data >> P.name >> P.price >> P.quantity;
	while (!data.eof())
	{
		cout << left << setw(20) << P.name << setw(20) << P.quantity << P.price << "$\n";
		data >> P.name >> P.price >> P.quantity;
	}
	data.close();
}
