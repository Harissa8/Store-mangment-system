#include<iostream>
#include"Header.h"
#include<string.h>
#include<fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

using namespace std;

int nb_of_customers = 0;

//Class Customer
void Customer::menu()
{
	system("cls");
	cout << "||||||| WELCOME CUSTOMER " << first_name << " " << last_name << " |||||||\n\n";
	cout << "=================================================================";
	cout << "\n\t\t\t   CUSTOMER MENU\n1. Display stock\n2. Purchase\n3. Back To Menu";
	cout << "\n\n\n==========================END OF MENU=============================";
	cout << "\n\n \t\tEnter your Choice :\t";

	int choice;
	while (true)
	{
		cin >> choice;
		if (!cin || choice <= 0 || choice > 3)
		{
			cout << "\n \t\tPlease choice a valid number! " << endl;
			cout << "\n \t\tEnter your Choice :\t";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}

	switch (choice)
	{
	case 1:
		system("cls");
		cout << "=================================================================";
		cout << "\n\t\t\t    CUSTOMER MENU\n1. Display stock ------> You Are Here!\n2. Purchase\n3. Back To Menu";
		cout << "\n\n\n==========================END OF MENU=============================\n\n";
		display();
		cout << "\n\nPress Any Key To Continue....";
		_getch();
		menu();
		break;
	case 2:
		purchase();
		break;
	case 3:
		Person::menu();
	}
}

void Customer::purchase()
{
	fstream data, data1;
	fstream data2;

	Product Array_P[100];
	int c = 0;
	char choice;
	double amount = 0;
	double total = 0;

	cout << "\n\n\t\t\t\t RECEIPT  ";
	data.open("Products.txt", ios::in);
	if (!data)
		cout << "\n\n Empty Database";
	else
	{
		data.close();

		system("cls");
		cout << "=================================================================";
		cout << "\n\t\t\t    CUSTOMER MENU\n1. Display stock\n2. Purchase ------> You Are Here!\n3. Back To Menu";
		cout << "\n\n\n==========================END OF MENU=============================\n\n";
		display();

		cout << "\n _________________________________________________\n|";
		cout << "                                                 |";
		cout << "\n|                                                 |";
		cout << "\n|            Please Place The Order               |\n";
		cout << "|                                                 |\n";
		cout << "|                                                 |\n";
		cout << " _________________________________________________\n";

		do
		{
		m:
			int index1 = 0, index2 = 0;
			cout << "\n\nEnter the Name of the Product: ";
			cin >> Array_P[c].name;

			do {
				cout << "\n\nEnter the Quantity: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> Array_P[c].quantity;
			} while (!cin || Array_P[c].quantity <= 0);

			data.open("Products.txt", ios::in);
			Product P1;
			data >> P1.name >> P1.price >> P1.quantity;

			while (!data.eof())
			{
				if (strcmp(P1.name, Array_P[c].name) == 0)
				{
					if (P1.quantity >= Array_P[c].quantity)
					{
						index2 = 1;
						break;
					}
					index1 = 1;
					break;
				}
				data >> P1.name >> P1.price >> P1.quantity;
			}
			data.close();

			if (index1 == 0 && index2 == 0)
			{
				cout << "\n\n Product Doesn't Exist. Please Try Again!";
				goto m;
			}

			if (index1 == 1)
			{
				cout << "\n\n Not Enough Quantity. Please Try Again!";
				goto m;
			}


			for (int i = 0; i < c; i++)
			{
				if (strcmp(Array_P[c].name, Array_P[i].name) == 0)
				{
					cout << "\n\n Duplicate Product Name. Please Try Again!";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do You Want to Buy Another Product?\nIf Yes then Press Y, else Press N.";
			cin >> choice;
		} while (choice == 'y' || choice == 'Y');

		system("cls");
		cout << "\n\n_________________________RECEIPT________________________________\n\n";
		cout << left << setw(18) << "Product Name" << setw(18) << "Product Quantity" << setw(18) << "Individual Price" << "Amount\n";

		data.open("Products.txt", ios::in);
		data1.open("Products1.txt", ios::app | ios::out);
		if (nb_of_customers == 0)
		{
			data2.open("History.txt", ios::out);
		}
		else
			data2.open("History.txt", ios::app | ios::out);
		Product P;
		data >> P.name >> P.price >> P.quantity;
		int k = 0;
		while (!data.eof())
		{
			for (int i = 0; i < c; i++)
			{
				if (strcmp(P.name, Array_P[i].name) == 0)
				{
					amount = P.price * Array_P[i].quantity;
					total += amount;
					cout << endl;
					cout << left << setw(18) << P.name << setw(18) << Array_P[i].quantity << setw(3) << P.price << setw(15) << "$" << amount << "$";
					data2 << left << setw(10) << first_name << setw(10) << last_name << setw(10) << get_username() << setw(18) << P.name << setw(5) << Array_P[i].quantity << setw(5) << P.price << amount << "\n";
					data1 << left << setw(15) << P.name << setw(7) << P.price << P.quantity - Array_P[i].quantity << endl;
				}
				else
				{
					k++;
				}
			}
			if (k == c)
				data1 << left << setw(15) << P.name << setw(7) << P.price << P.quantity << endl;
			data >> P.name >> P.price >> P.quantity;
			k = 0;
		}
		data.close();
		data1.close();
		data2.close();
		remove("Products.txt");
		rename("Products1.txt", "Products.txt");
	}

	cout << "\n\n____________________________________________________________";
	cout << "\n Name : " << first_name << " " << last_name;
	cout << "\n Total Amount : " << total << "$\n\n\n";
	nb_of_customers++;
	cout << "\nPress Any Key To Continue...";
	_getch();
	menu();
}

void Customer::adduser()
{
	int k = 0;
	fstream  file1;
	string u, p, tempstr1, tempstr2, fname, lname, temp3, temp4;
c:
	cout << "\n\n\t\tEnter Your First Name: ";
	cin >> fname;
	cout << "\n\t\tEnter Your Last Name: ";
	cin >> lname;
	cout << "\n\t\tEnter Your Username: ";
	cin >> u;
	cout << "\n\t\tEnter Your Password: ";
	cin >> p;
	ofstream fout;

	//num of lines
	string line;
	int m = 0, numlines = 0;
	ifstream reader("Costumer.txt");
	while (!reader.eof())
	{
		getline(reader, line);
		numlines++;
	}
	reader.close();

	file1.open("Costumer.txt");
	for (int i = 0; i < numlines; i++)
	{
		file1 >> tempstr1 >> tempstr2 >> temp3 >> temp4;

		if ((u == tempstr1))
		{
			cout << "\n\n\t\tThis Username Already Exists.";
			goto c;
		}
		else
		{
			m++;
			continue;
		}
		if (m == numlines)
			break;

	}
	fout.open("Costumer.txt", ios::app | ios::out);
	fout << "\n" << left << setw(10) << u << setw(10) << p << setw(10) << fname << lname;
	fout.close();
	cout << "\n\n\t\tYour Inputs Are Added into the Database!";
	cout << "\n\n\nPress Any Key To Continue...";
	_getch();
	system("cls");
	cout << "=============================================================";
	cout << "\n\n\t\t   Customer Login\n\t\t";
	cout << "\n=============================================================\n";

}



Customer Customer::login()
{
	int q;
	system("cls");
	cout << "=============================================================";
	cout << "\n\n\t\t   Customer Login\n\t\t";
	cout << "\n=============================================================\n";
	cout << "\t\t You Want To:\n\n \t\t 1.Login \n\n\t\t 2.Sign Up\n";

	do
	{
		cout << "\n\t\tEnter Your Choice (1 or 2): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> q;
	} while (!cin || q != 1 && q != 2);

	if (q == 2)
		adduser();

	string user, pass;
	Customer temp;
	string  tempstr1, tempstr2, temp3, temp4;
	int l = 0, k = 0;

	//to calculate number of lines in the file  :
	string line;
	int numlines = 0;
	ifstream reader("Costumer.txt");
	while (!reader.eof())
	{
		getline(reader, line);
		numlines++;
	}
	reader.close();

	cout << "\n\n\t\tPlease Enter Your Username:";
	cin >> user;

	ifstream infile;
	infile.open("Costumer.txt");

	for (int i = 0; i < numlines; i++)
	{
		infile >> tempstr1 >> tempstr2 >> temp3 >> temp4;

		if (user == tempstr1)
		{
			l = -99999;
			break;
		}
		else l++;
	}

	infile.close();

	if (l == numlines)
	{
		cout << "\nWrong Username (Not Found)";
		cout << "\n\nPress Any Key To Continue...";
		_getch();
		system("cls");
		Person::menu();
	}
	else
	{
		cout << "\n\t\tPlease Enter Your Password:";
		cin >> pass;

		infile.open("Costumer.txt");

		for (int i = 0; i < numlines; i++)
		{
			infile >> tempstr1 >> tempstr2 >> temp3 >> temp4;

			if ((user == tempstr1) && (pass == tempstr2))
			{
				k = -99999;
				break;
			}
			else k++;
		}

		infile.close();

		if (k == numlines)
		{
			cout << "\nWrong Password";
			cout << "\n\nPress Any Key To Continue...";
			_getch();
			system("cls");
			Person::menu();
		}
		else
		{
			temp.first_name = temp3;
			temp.last_name = temp4;
			temp.set(user, pass);
			return temp;
		}
	}
}