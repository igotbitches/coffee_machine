#include <iostream>

#define PIN 1111

using namespace std;

void mainMenu();
int customerChoose(int &choose);
int checkPin();
void serviceMenu(double &total, int &cups);
int addingCups(int &cups);
void givenTotal(double &total);

int main()
{
	int cups = 1, choose = 0;
	double total = 0.0;
	
	mainMenu:
	while (true)	
	{
		mainMenu();
		customerChoose(choose);
		
		if (choose == 1)
		{
			cout << "UserMenu" << endl; break;
		}
		
		else if (choose == 2)
		{
			if (checkPin())
			{
				while (true)
				{
					serviceMenu(total, cups);
					customerChoose(choose);
					
					if (choose == 1)
					{
						addingCups(cups); 
					}
					
					else if (choose == 2)
					{
						givenTotal(total);
					}
					
					else if (choose == 3)
					{
						while (true)
						{
							goto mainMenu;
						}
					}

				}
			}
			else
				cout << "Error";
		}
		
		else
		{
			cout << "Input 1 or 2" << endl; break;
		}
		break;
	}
	
	return 0;
}

void mainMenu()
{
	cout << "\t\t\tMain Menu" << endl;
	cout << "Dear Customer, would you like to drink aromatic grain coffee?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - Service" << endl;
}

int customerChoose(int &choose)
{
	cout << "Your choose " << endl;
	cin >> choose;
	
	return choose;
}

int checkPin()
{
	int counter = 3;
	int pin = 0;
	
	while (counter != 0)
	{
		cout << "Please, input PIN " << endl;
		cin >> pin;
		
		if (pin == PIN)
		{
			return counter;
		}
		else 
		{
			cout << "PIN is Wrong" << endl;
			counter--;
		}
	}
	
	return counter;	
}

void serviceMenu(double &total, int &cups)
{
	cout << "Balance is " << total << " BYN" << endl;
	cout << "There are " << cups << " cups loaded" << endl;
	cout << "Choose the option: " << endl;
	cout << "1 - Add cups" << endl;
	cout << "2 - Withdrawal of proceeds" << endl;
	cout << "3 - Back to Main Menu" << endl;	
}

int addingCups(int &cups)
{
	int cp = 0;
		
	if (cups >= 0 and cups <= 3)
	{
		cout << "Input cups " << endl;
		cin >> cp;
		
		if ((cp + cups) >= 0 and (cp + cups <= 3))
		{
			cout << "Complite" << endl;
			cups += cp;
		}
		else
		{
			cout << "Sorry, max 3 cups" << endl;
		}
	}
	
	return cups;
}

void givenTotal(double &total)
{
	cout << total << " BYN were given away" << endl << endl;
}
