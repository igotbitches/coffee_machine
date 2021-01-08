#include <iostream>
#include <windows.h>

#define SERVICE_PIN 3442
#define ESPRESSO_COST 1.0
#define CAPPUCCINO_COST 1.50
#define LATTE_COST 1.50
#define TEN_COINS 0.10
#define TWENTY_COINS 0.20
#define FIFTY_COINS 0.50
#define ONE_RUB 1.0
#define TWO_RUB 2.0

using namespace std;

void mainMenu(double cash, int cups);
void serviceMenu(double total, int cups);
void choiceMenu(int &choice);
void depositMenu();
double coinsDenomination(int &choice);
void inputMoney(double &total, double &cash, double coin);
int checkPIN();
void addCups(int &cups);
void takeCash(double &total, double &cash);
double coffeeCost(int choice);
void takeCoffee(int &cups, double &cash, double coffeeCost);
void progressBar();
void backToMainMenu(int &choice, double cash);

int main(){
    int choice = 0, cups = 7;
    double total = 0, cash = 0;

    while (true){
        mainMenu(cash, cups);
        choiceMenu(choice);

        if (choice == 1 and cups != 0){
            money_deposit:
            while (true){
                depositMenu();
                choiceMenu(choice);

                if (choice >= 1 and choice <= 5){
                    double coins = coinsDenomination(choice);
                    
                    inputMoney(total, cash, coins);
                    break;
                }
            	else{
            		cout << "Unknown coin!" << endl << endl;
            		Sleep(300);
            	}
            }
        }
        else if ((choice >= 2 and choice <= 4) and cups != 0){
            double cost = coffeeCost(choice);

            if (cash >= cost){
                takeCoffee(cups, cash, cost);
                backToMainMenu(choice, cash);
            }
            else goto money_deposit;
        }
        else if (choice == 5){
            int output = checkPIN();
            if (output == 1){}
            else if (output == 2){
                while (true){
                    serviceMenu(total, cups);
                    choiceMenu(choice);

                    if (choice == 1){
                        addCups(cups);
                    }
                    else if (choice == 2){
                        takeCash(total, cash);
                    }
                    else if (choice == 3){
                        break;
                    }
                    else {
	                	cout << "Try again!";
	                	Sleep(300);
                	}
				}
            }
            else {
                cout << "The machine is blocked.";
                return -1;
            }
        }
        else {
        	cout << "Unknown command!";
        	Sleep(300);
		}
    }
    return 0;
}

void mainMenu(double cash, int cups)
{
	system("cls");
	cout << "----------- MAIN MENU -----------" << endl;
    if (cups == 0){
        cout << "We are very sorry." << endl;
		cout << "But unfortunately there are no cups left." << endl << endl;
        cout << "5 - Service " << endl;
    }
    else{
    	
        cout << "Balance: " << cash << " BYN" << endl;
        cout << "Dear Customer, make your choice:" << endl << endl;
        cout << "1 - Deposit money" << endl;
        cout << "2 - Espresso" << "\t" << ESPRESSO_COST << " BYN" << endl;
        cout << "3 - Cappuccino" << "\t" << CAPPUCCINO_COST << " BYN" << endl;
        cout << "4 - Latte" << "\t" << LATTE_COST << " BYN" << endl;
        cout << "5 - Service" << endl;
    }
    cout << "---------------------------------" << endl << endl;
}

void serviceMenu(double total, int cups)
{
	system("cls");
	cout << "--------- SERVICE  MENU ---------" << endl;
    cout << "Balance is " << total << " BYN" << endl;
    cout << "There are " << cups << " cups loaded." << endl << endl;
    cout << "Choice the option: " << endl;
    cout << "1 - Add cups" << endl;
    cout << "2 - Withdrawal of proceeds" << endl;
    cout << "3 - Back to main menu" << endl;
    cout << "---------------------------------" << endl << endl;
}

void choiceMenu(int &choice)
{
    cout << "Your choose: ";
    cin >> choice;
    cout << endl;
}

void depositMenu()
{
	system("cls");
	cout << "--------- DEPOSIT  MENU ---------" << endl;
    cout << "Pay attention!" << endl;
	cout << "That coffee machine doesn't give change!" << endl << endl;
    cout << "Please deposit coins: " << endl << endl;
    cout << "1 - 10 coins" << endl;
    cout << "2 - 20 coins" << endl;
    cout << "3 - 50 coins" << endl;
    cout << "4 - 1 BYN" << endl;
    cout << "5 - 2 BYN" << endl;
    cout << "---------------------------------" << endl << endl;
}

double coinsDenomination(int &choice)
{
    if (choice == 1){
        return TEN_COINS;
    }
    else if (choice == 2){
        return TWENTY_COINS;
    }
    else if (choice == 3){
        return FIFTY_COINS;
    }
    else if (choice == 4){
        return ONE_RUB;
    }
    else if (choice == 5){
        return TWO_RUB;
    }
}

void inputMoney(double &total, double &cash, double coin)
{
    total += coin;
    cash += coin;
}

int checkPIN()
{
    int counter = 3;
    int pin = 0;
    
	system("cls");
    cout << "1 - Back to Main menu" << endl;

    while (counter != 0){
        cout << "Please, input PIN: ";
        cin >> pin;
        cout << endl;

        if (pin == 1 and counter == 3){  
            return 1;
        }
        else if (pin == SERVICE_PIN){
            return 2;
        }
        else {
            cout << "PIN is wrong." << endl;
            counter--;
        }
    }

    return -1;
}

void addCups(int &cups)
{
    int inputCups = 0;
    
	system("cls");
    cout << "How many cups are you adding?: " ;
    cin >> inputCups;

    if (inputCups > 0){
    	cups += inputCups;
	}
}

void takeCash(double &total, double &cash)
{
	
    cout << total << " BYN were given away" << endl << endl;
	Sleep(1000);
	
    total = 0.0;
    cash = 0.0;
}

double coffeeCost(int choice)
{
    if (choice == 2){
        return ESPRESSO_COST;
    }
    else if (choice == 3){
        return CAPPUCCINO_COST;
    }
    else if (choice == 4){
        return LATTE_COST;
    }
}

void takeCoffee(int &cups, double &cash, double coffeeCost)
{
    cash -= coffeeCost;
    cups--;

    progressBar();
}

void progressBar()
{
    double progress = 0.0;
    
	system("cls");
    cout << "Waiting for your coffee: " << endl;

    while (progress <= 1.0) {
        int barWidth = 20;

        cout << "[";
        int pos = progress * barWidth;
        for (int i = 0; i < barWidth; i++) {
            Sleep(5);
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

void backToMainMenu(int &choice, double cash)
{	
	system("cls");
    cout << "Balance: " << cash << " BYN" << endl;
    cout << "Here is the best ";

    if (choice == 2){
        cout << "Espresso";
    }
    else if (choice == 3){
        cout << "Cappuccino";
    }
    else if (choice == 4){
        cout << "Latte";
    }
    cout << " in the City. Please, help yourself!" << endl << endl;

    while (choice != 0){
        cout << "Press 0 for back to Main Menu."<< endl;
        choiceMenu(choice);
    }
}
