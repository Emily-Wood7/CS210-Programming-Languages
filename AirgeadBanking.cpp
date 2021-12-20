//Emily Wood
//CS 210
//Project 2

#include "Investment.h"

void DisplayMenu(Investment& userData);
void DisplayWithoutMonthlyDeposits(Investment& userData);
void DisplayWithMonthlyDeposits(Investment& userData);

int main() 
{
	char userChoice = 'Y';
	Investment userData;

	while (userChoice == 'Y')
	{
		system("CLS");
		
		DisplayMenu(userData);
		DisplayWithoutMonthlyDeposits(userData);
		DisplayWithMonthlyDeposits(userData);

		cout << endl << "Do you want to try another? y/n: ";
		cin >> userChoice;
		userChoice = toupper(userChoice);
		cout << endl;

	}

	return 0;
}

void DisplayMenu(Investment& userData)
{
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numberOfYears;

	cout << endl;
	cout << "**************** Airgead Banking ***************" << endl;
	cout << "** Investing and Compound Interest Calculator **" << endl;
	cout << "****************** Data Input ******************" << endl;
	cout << "Inital Investment Amount: $ ";
	cin >> initialInvestment;
	userData.SetInitialInvestment(initialInvestment);
	cout << "Monthly Deposit: $ ";
	cin >> monthlyDeposit;
	userData.SetMonthlyDeposit(monthlyDeposit);
	cout << "Annual Interest: % ";
	cin >> annualInterest;
	userData.SetAnnualInterest(annualInterest);
	cout << "Number of Years: ";
	cin >> numberOfYears;
	userData.SetNumberOfYears(numberOfYears);
	system("pause");
}

void DisplayWithoutMonthlyDeposits(Investment& userData)
{
	system("CLS");

	double initialInvestment = userData.GetInitialInvestment();
	double annualInterest = userData.GetAnnualInterest();
	int numberOfYears = userData.GetNumberofYears();
	double balance = initialInvestment;
	double interest = balance * annualInterest;

	cout << endl;
	cout << setfill('=') << setw(67) << "" << endl;
	cout << "     Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(67) << "" << endl;
	cout << "  Year        Year End Balance        Year End Earned Interest" << endl;
	cout << setfill('-') << setw(67) << "" << endl;
	cout << setfill(' ');

	for (int i = 0; i < numberOfYears; i++)
	{
		balance = balance + interest; 

		cout << endl;
		cout << setw(6) << right << (i + 1);
		cout << setw(20) << right << "$" << fixed << setprecision(2) << balance;
		cout << setw(28) << right << "$" << fixed << setprecision(2) << interest;
		cout << endl;
		interest = balance * annualInterest;
	}
	system("pause");
}

void DisplayWithMonthlyDeposits(Investment& userData)
{
	double initialInvestment = userData.GetInitialInvestment();
	double annualInterest = userData.GetAnnualInterest();
	int numberOfYears = userData.GetNumberofYears();
	double monthlyDeposit = userData.GetMonthlyDeposit();
	double balance = initialInvestment;
	double interest = balance * annualInterest;
	double totalInterest;

	cout << endl;
	cout << setfill('=') << setw(67) << "" << endl;
	cout << "       Balance and Interest With Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(67) << "" << endl;
	cout << "  Year        Year End Balance        Year End Earned Interest" << endl;
	cout << setfill('-') << setw(67) << "" << endl;
	cout << setfill(' ');

	for (int i = 0; i < numberOfYears; i++)
	{
		totalInterest = 0;

		for (int j = 0; j < 12; j++)
		{
			interest = (balance + monthlyDeposit) * (annualInterest / 12);
			totalInterest = totalInterest + interest;
			balance = balance + monthlyDeposit + interest;
		}

		stringstream balanceOutput;
		balanceOutput << "$" << fixed << setprecision(2) << balance;
		stringstream totalInterestOutput;
		totalInterestOutput << "$" << fixed << setprecision(2) << totalInterest;

		cout << endl;
		cout << setw(6) << (i + 1);
		cout << setw(24) << right << balanceOutput.str();
		cout << setw(32) << right << totalInterestOutput.str();
		cout << endl;
	}

}