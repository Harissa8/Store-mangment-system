#pragma once
#include <string>

class Person
{ 
public:
	std::string first_name, last_name;
	Person();
	void set(std::string, std::string);
	void display();
	void menu();
	std::string get_username();

private:
	std::string  username;
	std::string  password;
};

class Employee :public Person
{
public:
	void Refill();
	void menu();
	Employee login();
	void Show_History();
};

class Dealer :public Employee
{
public:
	void Add();
	void Remove();
	void menu();
	Dealer login();
};

class Customer :public Person
{
public:
	void purchase();
	void adduser();
	void menu();
	Customer login();
};

class Product
{
public:
	float price;
	int quantity;
	char name[30];
};
