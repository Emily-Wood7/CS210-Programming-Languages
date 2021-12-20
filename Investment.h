//Emily Wood
//CS 210
//Project 2

#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class Investment
{
public:
	Investment();
	void SetInitialInvestment(double initialInvestment);
	void SetMonthlyDeposit(double monthlyDeposit);
	void SetAnnualInterest(double annualInterest);
	void SetNumberOfYears(int numberOfYears);
	double GetInitialInvestment();
	double GetMonthlyDeposit();
	double GetAnnualInterest();
	int GetNumberofYears();
private:
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numberOfYears;
};

#endif