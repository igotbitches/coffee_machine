#include <iostream>

#define PIN 1111
#define ESPRESSO_COST 1
#define CAPPUCCINO_COST 1.5
#define LATTE_COST 1.5

using namespace std;

void mainMenu();
int customerChoose(int &choose);
int checkPin();
void serviceMenu(double &total, int &cups);
int addingCups(int &cups);
void givenTotal(double &total);
void coffeeMenu(double &cash);
void takeCoffee(int &cups, double &cash, double coffeeCost, double &total);
void inputCash(double &total, double &cash);
void infBalans(double &cash, double coffeeCost);

int main()
{
	int cups = 7, choose = 0;
	double total = 0.0, cash = 0.0;
	
	mainMenu:
	while (true)	
	{
		mainMenu();
		customerChoose(choose);
		
		if (choose == 1)
		{
			while (true)
			{
				if (cups == 0)
				{
					cout << "We are very sorry, but unfortunately there are no cups left" << endl << endl;
					goto mainMenu;
				}
				else
				{
					coffeeMenu(cash);
					customerChoose(choose);
					
					if (choose == 1)
					{
						takeCoffee(cups, cash, ESPRESSO_COST, total);
					}
					else if (choose == 2)
					{
						takeCoffee(cups, cash, CAPPUCCINO_COST, total);
					}
					else if (choose == 3)
					{
						takeCoffee(cups, cash, LATTE_COST, total);
					}	
					
					else if (choose == 4)
					{
						goto mainMenu;
					}	
				}
			}
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
		
	if (cups >= 0 and cups <= 7)
	{
		cout << "Input cups " << endl;
		cin >> cp;
		
		if ((cp + cups) >= 0 and (cp + cups <= 7))
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

void coffeeMenu(double &cash)
{
	cout << "What coffee do you prefer? " << endl;
	cout << cash << " BYN" << endl;
	cout << "1 - Espresso" << "\t  " << ESPRESSO_COST << " BYN" << endl;
	cout << "2 - Cappuccino" << "\t" << CAPPUCCINO_COST << " BYN" << endl;
	cout << "3 - Latte" << "\t" << LATTE_COST << " BYN" << endl;
	cout << "4 - Main Menu " << endl;
}

void takeCoffee(int &cups, double &cash, double coffeeCost, double &total)
{
	
	if (cash >= coffeeCost)
	{
		cash -= coffeeCost;
		cups--;
		cout << "Take your coffee!" << endl << endl;
	}
	else 
	{
		cout << "Please deposit " << coffeeCost - cash << " BYN" << endl;
		cout << "Minimal note is 1 BYN " << endl;
		cout << "Pay attention that the coffee machine doesen't give change" << endl;
		inputCash(total, cash);
	}
}

void inputCash(double &total, double &cash)
{
	double inputCash = 0;
	
	cout << "Input cash: ";
	cin >> inputCash;
	cout << endl;
	
	total += inputCash;
	cash += inputCash;	
}



