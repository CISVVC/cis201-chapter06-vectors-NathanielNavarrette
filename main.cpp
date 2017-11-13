/*
	*File: main.cpp
	*Developer: Nathaniel Navarrette
	*Email: nathaniel.navarrette96@gmail.com
	*Description: Take in transcactiosn during a month and print out 
		a bank statment for the end of the month.  */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>

double RATE = 5.0 / 100.0;

class Transaction
{
public:
	Transaction();
	void read();
	void print(bool check_last) const;
	double end_amount;
	void print_end_balance() const;
private:
	int day;

	double amount;
	std::string description;
	void set_account(double amount);
	
};

Transaction::Transaction()
{
	day = 0;
	amount = 0.0;
	description = "";
}

void Transaction::read()
{
	std::cout << "Day:";
	std::cin >> day;

	std::cout << "Amount Transacted:";
	std::cin >> amount;
	std::cin.ignore();

	std::cout << "Description:";
	std::getline(std::cin,description);
	set_account(amount);
}

void Transaction::set_account(double amount)
{
	end_amount += amount;
}



void Transaction::print(bool check_last) const
{
	std::cout << std::endl << "Day:" << day << std::endl;
	std::cout << "Amount:" << amount << std::endl;
	std::cout << "Description:" << description << std::endl;
	std::cout << "End Balance:" << end_amount << std::endl;

	if(check_last)
		std::cout  << "\n\nEnd of month:" 
		<< end_amount + end_amount * RATE << std::endl;
}


void print_transactions(const std::vector<Transaction> t)
{
	for(int i=0;i<t.size();i++)
	{
		if(i != t.size()-1)
			t[i].print(false);
		else
			t[i].print(true);
	}	
}

int main()
{
	std::vector<Transaction> transaction;
	bool more = true;
	while(more)
	{
		Transaction t;
		t.read();
		transaction.push_back(t);
		std::cout << std::endl << "Enter another (Y/N)";
		char response;
	 	std::cin >> response;

		if(response != 'y' && response != 'Y')
			more = false;
	}

	print_transactions(transaction);
	return 0;
}
