#include <iostream>
#include <string>
using namespace std;

class atm
{
private:
    string name;
    int pin;
    double balance;

public:
    atm()
    {
        name = "";
        pin = 0;
        balance = 0;
    }

    atm(string n, int p, double b)
    {
        name = n;
        pin = p;
        balance = b;
    }

    string getName()
    {
        return name;
    }

    bool enterpin()
    {
        int enter;

        cout << "Please enter your PIN: ";
        cin >> enter;

        if (enter == pin)
        {
            cout << "Login successful!\n";
            return true;
        }
        else
        {
            cout << "Invalid PIN!\n";
            return false;
        }
    }

    void checkbalance()
    {
        cout << "Your balance is: $" << balance << endl;
    }

    void deposit()
    {
        double cash;

        cout << "Enter cash you want to deposit: ";
        cin >> cash;

        if (cash > 0)
        {
            balance += cash;
            cout << "Deposit successful!\n";
            cout << "Your new balance is: $" << balance << endl;
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw()
    {
        double cash;

        cout << "Enter amount you want to withdraw: ";
        cin >> cash;

        if (cash <= balance && cash > 0)
        {
            balance -= cash;
            cout << "Withdrawal successful!\n";
            cout << "Your new balance is: $" << balance << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void changePIN()
    {
        int oldpin;
        int newpin;
        int confirm;

        cout << "Enter current PIN: ";
        cin >> oldpin;

        if (oldpin == pin)
        {
            cout << "Enter new PIN: ";
            cin >> newpin;

            cout << "Enter new PIN again: ";
            cin >> confirm;

            if (newpin == confirm)
            {
                pin = newpin;
                cout << "PIN changed successfully!\n";
            }
            else
            {
                cout << "PIN does not match!\n";
            }
        }
        else
        {
            cout << "Wrong current PIN!\n";
        }
    }
};

int main()
{
    atm accounts[100];

    accounts[0] = atm("Ali", 1234, 5000);
    accounts[1] = atm("Sara", 2222, 3000);
    accounts[2] = atm("Ahmed", 3333, 7500);

    int totalAccounts = 3;
    string username;
    int foundIndex = -1;
    int attempts = 3;
    int choice;

    cout << "===== ATM SYSTEM =====" << endl;

    cout << "Enter your name: ";
    cin >> username;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].getName() == username)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        char createChoice;

        cout << "Account not found!" << endl;
        cout << "Would you like to create a new account? (Y/N): ";
        cin >> createChoice;

        if (createChoice == 'Y' || createChoice == 'y')
        {
            string newName;
            int newPin;
            double initialBalance;

            cout << "Enter your name: ";
            cin >> newName;

            cout << "Create your PIN: ";
            cin >> newPin;

            cout << "Enter initial deposit: ";
            cin >> initialBalance;

            accounts[totalAccounts] = atm(newName, newPin, initialBalance);

            foundIndex = totalAccounts;
            totalAccounts++;

            cout << "Account created successfully!" << endl;
        }
        else
        {
            cout << "Goodbye!" << endl;
            return 0;
        }
    }

    while (attempts > 0)
    {
        if (accounts[foundIndex].enterpin())
        {
            break;
        }

        attempts--;

        cout << "Attempts left: " << attempts << endl;

        if (attempts == 0)
        {
            cout << "ATM locked!" << endl;
            return 0;
        }
    }

    do
    {
        cout << "\n1. Check Balance";
        cout << "\n2. Withdraw";
        cout << "\n3. Deposit";
        cout << "\n4. Change PIN";
        cout << "\n5. Exit";

        cout << "\n\nChoose option: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            accounts[foundIndex].checkbalance();
            break;

        case 2:
            accounts[foundIndex].withdraw();
            break;

        case 3:
            accounts[foundIndex].deposit();
            break;

        case 4:
            accounts[foundIndex].changePIN();
            break;

        case 5:
            cout << "Thank you for using ATM!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}
