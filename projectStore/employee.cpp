#include<iostream>
#include"Header.h"
#include<string.h>
#include<fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

using namespace std;

//Employee class
void Employee::Refill()
{
	fstream data, data1;
	Product P1, P2;
	int k = 0;
	display();
	cout << "\n\n============================================================\n";
	cout << "\n\nEnter the name of the product you want to refill: ";
	cin >> P1.name;

	do {
		cout << "\n\nEnter the quantity to add: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> P1.quantity;
	} while (!cin || P1.quantity <= 0);

	data.open("Products.txt", ios::in);

	if (!data)
	{
		cout << "File Does Not Exist!";
		cout << "\nPress Any Key To Continue...";
		_getch();
	}

	else
	{
		data1.open("Products1.txt", ios::app | ios::out);
		data >> P2.name >> P2.price >> P2.quantity;
		while (!data.eof())
		{
			if (strcmp(P1.name, P2.name) == 0)
			{
				data1 << left << setw(15) << P1.name << setw(7) << P2.price << P2.quantity + P1.quantity << endl;
				system("cls");
				cout << "\n\n\t\tStock Updated!\n";
				k++;
			}
			else
			{
				data1 << left << setw(15) << P2.name << setw(7) << P2.price << P2.quantity << endl;
			}
			data >> P2.name >> P2.price >> P2.quantity;
		}
		data.close();
		data1.close();
		remove("Products.txt");
		rename("Products1.txt", "Products.txt");

		if (k == 0)
		{
			system("cls");
			cout << "\n\n!!Item Not Found!!\n\n";
		}

		display();
		cout << "\nPress Any Key To Continue...";
		_getch();
	}
}

void Employee::menu()
{
	int choice = -1;
	//k:

	system("cls");
	cout << "||||||| WELCOME EMPLOYEE " << first_name << " " << last_name << " |||||||\n\n";
	cout << "=================================================================";
	cout << "\n\n\t\t\t    EMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Show History\n4. Back To Menu";
	cout << "\n\n\n==========================END OF MENU=============================";
	cout << "\n\n \t\tEnter your Choice :\t";

	while (true)
	{
		cin >> choice;
		if (!cin || choice <= 0 || choice > 4)
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
		cout << "\n\t\t\t    EMPLOYEE MENU\n1. Display stock ------> You Are Here!\n2. Refill\n3. Show History\n4. Back To Menu";
		cout << "\n\n\n==========================END OF MENU=============================\n\n";
		display();
		cout << "\n\nPress Any Key To Continue....";
		_getch();
		menu();
		break;
	case 2:
		system("cls");
		cout << "=================================================================";
		cout << "\n\t\t\t    EMPLOYEE MENU\n1. Display stock\n2. Refill ------> You Are Here!\n3. Show History\n4. Back To Menu";
		cout << "\n\n\n==========================END OF MENU=============================\n\n";
		Refill();
		menu();
		break;
	case 3:
		system("cls");
		cout << "=================================================================";
		cout << "\n\t\t\t    EMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Show History ------> You Are Here!\n4. Back To Menu";
		cout << "\n\n\n==========================END OF MENU=============================\n\n";
		Show_History();
		menu();
		break;
	case 4:
		Person::menu();
	}
}





Employee Employee::login()
{
	system("cls");
	cout << "=============================================================";
	cout << "\n\n\t\t   Employee Login\n\t\t";
	cout << "\n=============================================================\n";

	string user, pass;
	Employee temp;
	string  tempstr1, tempstr2, temp3, temp4;
	int l = 0, k = 0;

	// to calculate number of lines in the file :
	string line;
	int numlines = 0;
	ifstream reader("Emp.txt");
	while (!reader.eof())
	{
		getline(reader, line);
		numlines++;
	}
	reader.close();

	cout << "\n\t\tPleaser Enter Your Username:  ";
	cin >> user;

	ifstream infile;
	infile.open("Emp.txt");

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
		//return 0;
	}

	else
	{
		cout << "\n\t\tPlease Enter Your Password:   ";
		cin >> pass;

		infile.open("Emp.txt");

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


void Employee::Show_History()
{
	//to calculate number of lines in the file:
	string line;
	int numlines = 0;
	ifstream reader("History.txt");

	if (!reader)
	{
		cout << "No Receipts\n";
		cout << "\nPress Any Key To Continue...";
		_getch();
	}

	else
	{
		while (!reader.eof())
		{
			getline(reader, line);
			numlines++;
		}
		reader.close();

		if (numlines == 0)
		{
			cout << "No Receipts\n";
			cout << "\nPress Any Key To Continue...";
			_getch();

		}
		else
		{
			ifstream infile;
			infile.open("History.txt");

			cout << "\nHistory Of Receipts\n\n";
			cout << "--------------------------\n";
			string temp1, temp2, temp3, temp4, user1, user2;
			Product P1, P2;
			float t1, t2, person_total = 0;
			int  flag = 0;

			for (int i = 0; i < numlines / 2; i++)
			{
				flag = 0;
				infile >> temp1 >> temp2 >> user1 >> P1.name >> P1.quantity >> P1.price >> t1;

				if (i == 0)
				{
					person_total = t1;
					cout << left << setw(10) << P1.name << setw(5) << P1.price << setw(5) << P1.quantity << t1 << endl;
				}
				else
				{
					//if (temp1 == temp3 && temp2 == temp4)
					if (user1 == user2)
					{
						person_total += t1;
						cout << left << setw(10) << P1.name << setw(5) << P1.price << setw(5) << P1.quantity << t1 << endl;
					}
					else
					{
						cout << "--------------------------\n";
						cout << "Name : " << temp3 << " " << temp4;
						cout << "\nUsername : " << user2;
						cout << "\nTotal Amount : " << person_total << "$";
						cout << "\n\n\n--------------------------\n";

						cout << left << setw(10) << P1.name << setw(5) << P1.price << setw(5) << P1.quantity << t1 << endl;
						person_total = t1;
					}
				}
				infile >> temp3 >> temp4 >> user2 >> P2.name >> P2.quantity >> P2.price >> t2;
				if (!infile.eof())
				{
					flag = 1;
					//if (temp1 == temp3 && temp2 == temp4)
					if (user1 == user2)
					{
						cout << left << setw(10) << P2.name << setw(5) << P2.price << setw(5) << P2.quantity << t2 << endl;
						person_total += t2;
					}
					else
					{
						cout << "--------------------------\n";
						cout << "Name : " << temp1 << " " << temp2;
						cout << "\nUsername : " << user1;
						cout << "\nTotal Amount : " << person_total << "$";
						cout << "\n\n\n--------------------------\n";
						cout << left << setw(10) << P2.name << setw(5) << P2.price << setw(5) << P2.quantity << t2 << endl;
						person_total = t2;
					}
				}
			}

			if (flag == 0)
			{
				cout << "--------------------------\n";
				cout << "Name : " << temp1 << " " << temp2;
				cout << "\nUsername : " << user1;
				cout << "\nTotal Amount : " << person_total << "$";
			}

			else if (flag == 1)
			{
				cout << "--------------------------\n";
				cout << "Name : " << temp3 << " " << temp4;
				cout << "\nUsername : " << user2;
				cout << "\nTotal Amount : " << person_total << "$";
			}


			infile.close();
			cout << "\n\n\nPress Any Key To Continue...";
			_getch();
		}
	}
}
