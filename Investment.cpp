//Emily Wood
//CS 210
//Project 2

#include "Investment.h"

Investment::Investment()
{
	initialInvestment = 0;
	monthlyDeposit = 0;
	annualInterest = 0;
	numberOfYears = 0;
}

void Investment::SetInitialInvestment(double initialInvestment)
{
	this->initialInvestment = initialInvestment;
}

void Investment::SetMonthlyDeposit(double monthlyDeposit)
{
	this->monthlyDeposit = monthlyDeposit;
}

void Investment::SetAnnualInterest(double annualInterest)
{
	this->annualInterest = (annualInterest / 100);
}

void Investment::SetNumberOfYears(int numberOfYears)
{
	this->numberOfYears = numberOfYears;
}

double Investment::GetInitialInvestment()
{
	return initialInvestment;
}

double Investment::GetMonthlyDeposit()
{
	return monthlyDeposit;
}

double Investment::GetAnnualInterest()
{
	return annualInterest;
}

int Investment::GetNumberofYears()
{
	return numberOfYears;
}
