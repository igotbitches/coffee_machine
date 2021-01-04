#include <iostream>
#include <windows.h>

#define SERVICE_PIN 1111
#define ESPRESSO_COST 1.0
#define CAPPUCCINO_COST 1.5
#define LATTE_COST 1.5

#define TEN_COINS 0.1
#define TWENTY_COINS 0.2
#define FIFTY_COINS 0.5
#define ONE_RUB 1
#define TWO_RUB 2

using namespace std;

void mainMenu(double cash);
void serviceMenu(double total, int cups);
void choiceMenu(int &choice);
void depositMenu();
void noCupsMenu();
void inputMoney(double &total, double &cash, double COIN);
bool checkPIN();
void addCups(int &cups);
void takeCash(double &total, double &cash);
void takeCoffee(int &cups, double &cash, double coffeeCost);
void progressBar();

int main(){
	int choice = 0, cups = 2;
	double total = 0, cash = 0;

	while (true){
	    if (cups <= 0){ // if we don't have cups
            noCupsMenu();
            choiceMenu(choice);

            if (choice == 5){
                goto service_menu;
            }
            else{
                cout << "Try again." << endl << endl;
            }
	    }
	    else {
            mainMenu(cash);
            choiceMenu(choice);

            if (choice == 1){
                while (true){ //menu for INPUT money
                    depositMenu();
                    choiceMenu(choice);

                    if (choice == 1){
                        inputMoney(total, cash, TEN_COINS);
                        break;
                    }
                    else if (choice == 2){
                        inputMoney(total, cash, TWENTY_COINS);
                        break;
                    }
                    else if (choice == 3){
                        inputMoney(total, cash, FIFTY_COINS);
                        break;
                    }
                    else if (choice == 4){
                        inputMoney(total, cash, ONE_RUB);
                        break;
                    }
                    else if (choice == 5){
                        inputMoney(total, cash, TWO_RUB);
                        break;
                    }
                    else if (choice == 6){
                        break;
                    }
                }
            }
            else if (choice == 2){
                takeCoffee(cups, cash, ESPRESSO_COST);
            }
            else if (choice == 3){
                takeCoffee(cups, cash, CAPPUCCINO_COST);
            }
            else if (choice == 4){
                takeCoffee(cups, cash, LATTE_COST);
            }
            else if (choice == 5){
                service_menu:
                if (checkPIN()){ //menu for SERVICE
                    while (true){
                        serviceMenu(total, cups);
                        choiceMenu(choice);

                        if (choice == 1){
                            addCups(cups);
                        }
                        if (choice == 2){
                            takeCash(total, cash);
                        }
                        if (choice == 3){
                            break;
                        }
                    }
                }
                else {
                    cout << "The machine is blocked.";
                    break;
                }
            }
            else {
                cout << endl << "Please, choice another." << endl << endl;
            }
        }
	}

	return 0;
}

void mainMenu(double cash)
{
	cout << "Dear Customer, make your choice:" << endl;
	cout << cash << " BYN" << endl << endl;
	cout << "1 - Deposit money" << endl;
    cout << "2 - Espresso" << "\t" << ESPRESSO_COST << " BYN" << endl;
    cout << "3 - Cappuccino" << "\t" << CAPPUCCINO_COST << " BYN" << endl;
    cout << "4 - Latte" << "\t" << LATTE_COST << " BYN" << endl;
    cout << "5 - Service" << endl << endl;
}

void serviceMenu(double total, int cups)
{
    cout << "Balance is " << total << " BYN" << endl;
    cout << "There are " << cups << " cups loaded." << endl << endl;
    cout << "Choice the option: " << endl;
    cout << "1 - Add cups" << endl;
    cout << "2 - Withdrawal of proceeds" << endl;
    cout << "3 - Back to main menu" << endl << endl;

}

void choiceMenu(int &choice)
{
    cout << "Your choose: ";
    cin >> choice;
    cout << endl;

}

void depositMenu()
{
    cout << "Pay attention that coffee machine doesn't give change!" << endl;
    cout << "Please deposit coins: " << endl << endl;
    cout << "1 - 10 coins" << endl;
    cout << "2 - 20 coins" << endl;
    cout << "3 - 50 coins" << endl;
    cout << "4 - 1 BYN" << endl;
    cout << "5 - 2 BYN" << endl;
    cout << "6 - Main Menu" << endl << endl;
}

void inputMoney(double &total, double &cash, double COIN)
{
    total += COIN;
    cash += COIN;
    cout << "Your deposit: " << COIN << " BYN" << endl << endl;
}

bool checkPIN()
{
	int counter = 3;
	int pin = 0;

	while (counter != 0){
		cout << "Please, input PIN: ";
		cin >> pin;
		cout << endl;

		if (pin == SERVICE_PIN){
			return true;
		}
		else {
			cout << "PIN is wrong." << endl;
			counter--;
		}
	}

	return false;
}

void addCups(int &cups)
{
    int inputCups = 0;

    cout << "How many cups are you adding?: " ;
    cin >> inputCups;

    cups += inputCups;
    cout << "Completed! "<< inputCups << " was added." << endl << endl;
}

void takeCash(double &total, double &cash)
{
    cout << total << " BYN were given away" << endl << endl;

    total = 0.0;
    cash = 0.0;
}

void takeCoffee(int &cups, double &cash, double coffeeCost)
{
    if (cash >= coffeeCost)
    {
        cash -= coffeeCost;
        cups--;
        cout << "Waiting for your coffee: " << endl;
        progressBar();
        cout << "Take your coffee!" << endl << endl;
    }
    else
    {
        cout << "Coffee which you choose cost " << coffeeCost << " BYN" << endl;
        cout << "Please deposit " << coffeeCost - cash << " BYN more." << endl << endl;
    }
}

void progressBar(){
    double progress = 0.0;
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

void noCupsMenu(){
    cout << "We are very sorry, but unfortunately there are no cups left." << endl;
    cout << "5 - Service " << endl << endl;
}
