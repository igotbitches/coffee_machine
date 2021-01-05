#include <iostream>
#include <windows.h>

#define SERVICE_PIN 3442
#define ESPRESSO_COST 1.0
#define CAPPUCCINO_COST 1.5
#define LATTE_COST 1.5
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
void inputMoney(double &total, double &cash, double coin);
int checkPIN();
void addCups(int &cups);
void takeCash(double &total, double &cash);
void takeCoffee(int &cups, double &cash, double coffeeCost);
void progressBar();
void backToMainMenu(int &choice, double cash);

int main(){
    int choice = 0, cups = 2;
    double total = 0, cash = 0;

    while (true){
        mainMenu(cash, cups);
        choiceMenu(choice);

        if (choice == 1 and cups != 0){
            money_deposit:
            while (true){
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
            }
        }
        else if (choice == 2 and cups != 0){
            if (cash >= ESPRESSO_COST){
                takeCoffee(cups, cash, ESPRESSO_COST);
                backToMainMenu(choice, cash);
            } else goto money_deposit;
        }
        else if (choice == 3 and cups != 0){
            if (cash >= CAPPUCCINO_COST){
                takeCoffee(cups, cash, CAPPUCCINO_COST);
                backToMainMenu(choice, cash);
            } else goto money_deposit;
        }
        else if (choice == 4 and cups != 0){
            if (cash >= LATTE_COST){
                takeCoffee(cups, cash, LATTE_COST);
                backToMainMenu(choice, cash);
            } else goto money_deposit;
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

    return 0;
}

void mainMenu(double cash, int cups)
{
    if (cups == 0){
        cout << "We are very sorry, but unfortunately there are no cups left." << endl;
        cout << "5 - Service " << endl << endl;
    }
    else{
        cout << "Balance: " << cash << " BYN" << endl;
        cout << "Dear Customer, make your choice:" << endl << endl;
        cout << "1 - Deposit money" << endl;
        cout << "2 - Espresso" << "\t" << ESPRESSO_COST << " BYN" << endl;
        cout << "3 - Cappuccino" << "\t" << CAPPUCCINO_COST << " BYN" << endl;
        cout << "4 - Latte" << "\t" << LATTE_COST << " BYN" << endl;
        cout << "5 - Service" << endl << endl;
    }
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
    cout << "5 - 2 BYN" << endl << endl;
}

void inputMoney(double &total, double &cash, double coin)
{
    total += coin;
    cash += coin;
    cout << "Your deposit: " << coin << " BYN" << endl << endl;
}

int checkPIN()
{
    int counter = 3;
    int pin = 0;

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

    cout << "How many cups are you adding?: " ;
    cin >> inputCups;

    if (inputCups <= 0){
        cout << "You need to put 1 or more cups!" << endl << endl;
    }
    else{
        cups += inputCups;
        cout << "Completed! "<< inputCups << " was added." << endl << endl;
    }
}

void takeCash(double &total, double &cash)
{
    cout << total << " BYN were given away" << endl << endl;

    total = 0.0;
    cash = 0.0;
}

void takeCoffee(int &cups, double &cash, double coffeeCost)
{
    cash -= coffeeCost;
    cups--;

    cout << "Waiting for your coffee: " << endl;
    progressBar();
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

void backToMainMenu(int &choice, double cash)
{
    cout << "Balance: " << cash << " BYN" << endl;
    cout << "Here is the best Espresso/Cappuccino/Latte in the City. Please, help yourself!" << endl << endl;

    while (choice != 0){
        cout << "Press 0 for back to Main Menu."<< endl;
        choiceMenu(choice);
    }
}
