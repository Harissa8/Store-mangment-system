#include<iostream>
#include"Header.h"
#include<string.h>
#include<fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

using namespace std;

// Dealer Class
void Dealer::Add()
{
	fstream data;
	Product P1;

	system("cls");
	cout << "=================================================================";
	cout << "\n\n\t\t\t    DEALER MENU\n\n1. Add new product ------> You Are Here!\n2. Display stock\n3. Refill\n4. Remove an item\n5. Show History\n6. Back to Menu";
	cout << "\n\n\n==========================END OF MENU=============================\n\n";
	display();
	int n;

	do {
		cout << "\n\nEnter the No. of Products that you wish to add: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> n;
	} while (!cin || n <= 0);

	for (int i = 0; i < n; i++)
	{
	flag:
		int k = 0;
		Product P2;
		cout << "\n\nEnter the name of the product: ";
		cin >> P2.name;

		do {
			cout << "\n\nEnter its price (in US Dollars $): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> P2.price;
		} while (!cin || P2.price <= 0);

		do {
			cout << "\n\nEnter its quantity: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> P2.quantity;
		} while (!cin || P2.quantity <= 0);

		data.open("Products.txt", ios::in);

		//File doesn't exist
		if (!data)
		{
			//data.open("C:\\C++\\Store_Management\\projectStore\\Products.txt");
			data.open("Products.txt", ios::app | ios::out);
			data << left << setw(15) << P2.name << setw(7) << P2.price << P2.quantity << endl;
			data.close();
		}

		//File already exists
		else
		{
			//check.open("C:\\C++\\Store_Management\\projectStore\\Products.txt");
			data >> P1.name >> P1.price >> P1.quantity;
			while (!data.eof())
			{
				if (strcmp(P1.name, P2.name) == 0) //Strings are equal
					k++;
				data >> P1.name >> P1.price >> P1.quantity;
			}
			data.close();

			if (k == 1)
			{
				cout << "Product Already Exists!";
				goto flag;
			}
			else
			{
				//data.open("C:\\C++\\Store_Management\\projectStore\\Products.txt");
				data.open("Products.txt", ios::app | ios::out);
				data << left << setw(15) << P2.name << setw(7) << P2.price << P2.quantity << endl;
				data.close();
			}
		}
		cout << "Item number " << i + 1 << " added.\n";
	}
	system("cls");
	cout << "\n\n\t\t\tStock Updated!\n\n";
	display();
	cout << "\nPress Any Key To Continue...";
	_getch();
	menu();
}


void Dealer::Remove()
{
	fstream data, data1;
	Product P1, P2;
	int k = 0;

	system("cls");
	cout << "=================================================================";
	cout << "\n\n\t\t\t    DEALER MENU\n\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item ------> You Are Here!\n5. Show History\n6. Back to Menu";
	cout << "\n\n\n==========================END OF MENU=============================\n\n";
	display();

	cout << "\n\n============================================================\n";
	cout << "\n\t\t\t\tDelete Record";
	cout << "\n\nEnter the name of the product:";
	cin >> P1.name;
	data.open("Products.txt", ios::in);

	if (!data)
	{
		cout << "File Does Not Exist!";
	}

	else
	{
		data1.open("Products1.txt", ios::app | ios::out);
		data >> P2.name >> P2.price >> P2.quantity;
		while (!data.eof())
		{
			if (strcmp(P1.name, P2.name) == 0)
			{
				system("cls");
				cout << "\n\n\t\t\tRecord deleted successfully\n";
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
			cout << "\n\n!!Item not found!!\n\n";
		}
		display();
		cout << "\nPress Any Key To Continue...";
		_getch();
		menu();
	}
}


void Dealer::menu()
{
	int choice;

	system("cls");
	cout << "||||||| WELCOME DEALER " << first_name << " " << last_name << " |||||||\n\n";
	cout << "=================================================================";
	cout << "\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Show History\n6. Back to Menu";
	cout << "\n\n\n==========================END OF MENU=============================";
	cout << "\n\n \t\tEnter your Choice :\t";

	while (true)
	{
		cin >> choice;
		if (!cin || choice <= 0 || choice > 6)
		{
			cout << "\n \t\tPlease choose a valid number!" << endl;
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
		Add();
		break;
	case 2:
		system("cls");
		cout << "=================================================================";
		cout << "\n\t\t\t    DEALER MENU\n\n1. Add new product\n2. Display stock ------> You Are Here!\n3. Refill\n4. Remove an item\n5. Show History\n6. Back to Menu";
		cout << "\n\n\n==========================END OF MENU=============================\n\n";
		display();
		cout << "\n\nPress Any Key To Continue....";
		_getch();
		menu();
		break;
	case 3:
		system("cls");
		cout << "=================================================================";
		cout << "\n\t\t\t    DEALER MENU\n\n1. Add new product\n2. Display stock\n3. Refill ------> You Are Here!\n4. Remove an item\n5. Show History\n6. Back to Menu";
		cout << "\n\n\n==========================END OF MENU=============================\n\n";
		Refill();
		menu();
		break;
	case 4:
		Remove();
		break;
	case 5:
		system("cls");
		cout << "=================================================================";
		cout << "\n\t\t\t    DEALER MENU\n\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Show History ------> You Are Here!\n6. Back to Menu";
		cout << "\n\n\n==========================END OF MENU=============================\n\n";
		Show_History();
		menu();
		break;
	case 6:
		Person::menu();
	}
}


Dealer Dealer::login()
{
	string user, pass;

	system("cls");
	cout << "=============================================================";
	cout << "\n\n\t\t   Dealer Login\n\t\t";
	cout << "\n=============================================================\n";

	Dealer temp;
	string  tempstr1, tempstr2, temp3, temp4;
	int l = 0, k = 0;

	//to calculate number of lines in the file  :
	string line;
	int numlines = 0;
	ifstream reader("Dealer.txt");
	while (!reader.eof())
	{
		getline(reader, line);
		numlines++;
	}
	reader.close();

	cout << "\n\t\tPleaser Enter Your Username:  ";
	cin >> user;

	ifstream infile;
	infile.open("Dealer.txt");

	// Finding the username first
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
		cout << "\n\t\tPlease Enter Your Password:   ";
		cin >> pass;

		//Finding the password matching the username entered
		infile.open("Dealer.txt");

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
