#include <iostream>
<<<<<<< HEAD
#include <windows.h>

#define SERVICE_PIN 9917
#define ESPRESSO_COST 1.5
#define LATTE_COST 2.5
#define CAPPUCCINO 2.5

using namespace std;

void userMenu(double cash, int cups);
void serviceMenu();
int usChoice(int &choice);
void inputCash(double &total, double &cash);
void takeCash(double &total);
int checkPIN();

void takeCoffee(int &cups, double &cash, double coffeeCost, double &total); // experimental function // need to update
void progressBar(); // experimental, looks great

int main(){
	int choice = 0, cups = 7;
	double total = 0, cash = 0;
	
	while(true){
		userMenu(cash, cups);
		usChoice(choice);
		
		if (choice == 1){
			inputCash(total, cash);
		}
		else if (choice == 2){
			takeCoffee(cups, cash, ESPRESSO_COST, total);
		}
		else if (choice == 3){
			cout << "Cappuccino" << endl;
		}
		else if (choice == 4){
			cout << "Latte" << endl;
		}
		else if (choice == 5){
			if (checkPIN()){
				while (true) {
					serviceMenu();
					usChoice(choice);
				
					if (choice == 1){
						cout << "The machine have " << total << " BYN" << endl << endl;
					}
					else if (choice == 2){
						cout << "Empty cups: " << cups << " pieces." << endl;
					}
					else if (choice == 3){
						takeCash(total);
					}
					else if (choice == 0){
						break;
					}
				}
			}
			else {
				break;
			}				
		}
		else if (choice == 0){
			break;
		}
=======

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
>>>>>>> Artur2
	}
	
	return 0;
}

<<<<<<< HEAD

void userMenu(double cash, int cups){
	if (cups == 0){
		cout << "5 - Service Menu" << endl;
	}
	else {
	cout << "################" << endl;
	cout << "Balance: " << cash << " BYN" << endl;
	cout << "################" << endl << endl;
	cout << "1 - Input cash" << endl;
	cout << "2 - Espresso" << endl;
	cout << "3 - Cappuccino" << endl;
	cout << "4 - Latte" << endl;
	cout << "5 - Service Menu" << endl;
	cout << "0 - Exit" << endl;
	}	
}


void serviceMenu(){
	cout << "1 - Balance" << endl;
	cout << "2 - Empty cups" << endl;
	cout << "3 - Take cash" << endl;
	cout << "0 - Exit" << endl;
}


int usChoice(int &choice){

	cout << endl << "Your choice? ";
	cin >> choice;
	cout << endl;
	
	return choice;
}


void inputCash(double &total, double &cash){
	double inputCash = 0;
	
	cout << "The machine does not give change." << endl;
	cout << "Input cash: ";
	cin >> inputCash;
	cout << endl;
	
	total += inputCash;
	cash += inputCash;
}


void takeCash(double &total){ //we need also take money from cash! I dont know about this. I need to ask.
	cout << "You take: " << total << " BYN" << endl << endl;
	total = 0;
}


int checkPIN(){
	int counter = 3;
	int pin = 0;
	
	while (counter != 0){
		cout << "You have " << counter << " attempt(s)." << endl;
		cout << "Please, input PIN: ";
		cin >> pin;
		cout << endl;
		
		if (pin == SERVICE_PIN){
			return counter;
		}
		else {
=======
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
>>>>>>> Artur2
			counter--;
		}
	}
	
	return counter;	
}

<<<<<<< HEAD

void takeCoffee(int &cups, double &cash, double coffeeCost, double &total){
	if (cash >= coffeeCost){
		cash -= coffeeCost;
		cups--;
		cout << "Waiting for your coffee: " << endl;
		progressBar();
		cout << "Take your coffee!" << endl << endl;
		Sleep(1000);
	}
	else {
		cout << "Now you have " << cash << " BYN" << endl;
		cout << "Coffee cost " << coffeeCost << " BYN" << endl;
		cout << "You need to add " << coffeeCost - cash << " BYN" << endl << endl;
		inputCash(total, cash);
	}

}

void progressBar(){
	double progress = 0.0;
	while (progress <= 1.0) {
		
    	int barWidth = 20;

	    cout << "[";
	    int pos = progress * barWidth;
	    for (int i = 0; i < barWidth; i++) {
	    	Sleep(100);
	        if (i < pos){
	        	cout << "=";	
			}
	        else if (i == pos){
	        	cout << ">";
			}
	        else{
	        	cout << " ";
			} 
	    }
	    cout << "] " << progress * 100 << " %\r";
	
	    progress += 0.10;
	}
	
	cout << endl << endl;
}

=======
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
>>>>>>> Artur2
