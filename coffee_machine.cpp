#include <iostream>

#define SERVICE_PIN 9917

using namespace std;

void userMenu(double cash, int cups);
void serviceMenu();
int usChoice(int &choice);
void inputCash(double &balance, double &cash);
void takeCash(double &balance);
int checkPIN();


int main(){
	int choice = 0;
	double balance = 0;
	int cups = 7;
	double cash = 0;
	
	while(true){
		userMenu(cash, cups);
		usChoice(choice);
		
		if (choice == 1){
			inputCash(balance, cash);
		}
		else if (choice == 2){
			cout << "Espresso" << endl;
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
						cout << "The machine have " << balance << " BYN" << endl << endl;
					}
					else if (choice == 2){
						cout << "Empty cups: " << cups << " pieces." << endl;
					}
					else if (choice == 3){
						takeCash(balance);
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
	}
	
	return 0;
}


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


void inputCash(double &balance, double &cash){
	double input = 0;
	
	cout << "The machine does not give change." << endl;
	cout << "Input cash: ";
	cin >> input;
	cout << endl;
	
	balance += input;
	cash += input;
}


void takeCash(double &balance){ //we need also take money from cash! I dont know about this. I need to ask.
	cout << "You take: " << balance << " BYN" << endl << endl;
	balance = 0;
}


int checkPIN(){
	int counter = 3;
	int pin = 0;
	
	while (counter != 0){
		cout << "Please, input PIN: ";
		cin >> pin;
		cout << endl;
		
		if (pin == SERVICE_PIN){
			return counter;
		}
		else {
			counter--;
		}
	}
	
	return counter;	
}


