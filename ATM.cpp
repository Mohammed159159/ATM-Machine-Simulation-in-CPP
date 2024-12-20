#include <iostream>
#include <vector>

using namespace std;

class Account {
private:
    double accountNum;
    int pin;
    double balance;

public:
    Account(double AccountNum, int Pin, double Balance) {
        accountNum = AccountNum;
        pin = Pin;
        balance = Balance;
    }
    double getBalance() const
    {
        return balance;
    }
    double getAccountNum() const {
        return accountNum;
    }
    bool verifyPin(int inputPin) const {
        return pin == inputPin;
    }

    void deposit(double b) {
        balance += b;
        cout << "Your NEW account balance is: " << balance << endl;

    }
    void withdraw(double b) {
        balance -= b;
        cout << "Your NEW account balance is: " << balance << endl;
    }

    void changePIN()
    {
        int tmp_currentPass;
        cout << "Please enter the Current PIN: ";
        cin >> tmp_currentPass;

        if (tmp_currentPass == pin)
        {
            int tmp_newPass1, tmp_newPass2;
            cout << "Please enter the New PIN: ";
            cin >> tmp_newPass1;
            cout << "Please enter the New PIN Again: ";
            cin >> tmp_newPass2;

            if (tmp_newPass1 == tmp_newPass2)
            {
                pin = tmp_newPass1; // Assign the new PIN to the member variable
                cout << "PIN changed successfully." << endl;
            }
            else
            {
                cout << "New PINs do not match. Please try again." << endl;
            }
        }
        else
        {
            cout << "Current PIN is incorrect." << endl;
        }
    }





};


bool login_System(double input_accountNum, int input_pin, const vector<Account>& account_db)
{

    for (int i = 0; i < account_db.size(); i++)
    {
        if (account_db[i].getAccountNum() == input_accountNum)
        {
            if (account_db[i].verifyPin(input_pin))
            {
                return true;
            }
            cout << "PIN Is Incorrect" << endl;
            return false;
        }

    }
    cout << "Incorrect Account Number" << endl;
    return false;
}




int main()
{

    // HARDCODED ACCOUNTS
    vector<Account> account_db;
    account_db.push_back(Account(1, 9999, 50));
    account_db.push_back(Account(2, 1234, 99));
    account_db.push_back(Account(3, 5678, 69));
    account_db.push_back(Account(4, 4321, 420));


    cout << "Welcome to OUR ATM Machine" << "\n";

    cout << "Please enter your account number: ";
    double input_accountNum;
    cin >> input_accountNum;

    cout << "Please enter your 4-digit PIN: ";
    int input_pin;
    cin >> input_pin;

    // We need this to keep track of which account the user is currently using
    int current_account_index = 0;
    for (int i = 0; i < account_db.size(); i++) {
        if (account_db[i].getAccountNum() == input_accountNum) {
            current_account_index = i;
            break;
        }
    }

    if (login_System(input_accountNum, input_pin, account_db)) {
        cout << "Login successful." << endl;
        int choice;
        do {
            string menuFunctions[5] = { "Check Balance", "Deposit Money", "Withdraw Money", "Change PIN", "Exit" };
            cout << "\nATM Menu:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << menuFunctions[i] << endl;
            }

            cout << "Enter your choice (1-5): ";
            cin >> choice;

            if (choice == 1) {
                cout << "Your balance is: $" << account_db[current_account_index].getBalance() << endl;
            }
            else if (choice == 2) {
                double amount;
                cout << "Enter amount to deposit: $";
                cin >> amount;
                if (amount > 0) {
                    account_db[current_account_index].deposit(amount);
                }
                else {
                    cout << "Please enter a valid amount greater than $0." << endl;
                }
            }
            else if (choice == 3) {
                double amount;
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                if (amount <= 0) {
                    cout << "Please enter a valid amount greater than $0." << endl;
                }
                else if (amount <= account_db[current_account_index].getBalance()) {
                    account_db[current_account_index].withdraw(amount);
                }
                else {
                    cout << "Your balance is insufficient. Your current balance is: $"
                        << account_db[current_account_index].getBalance() << endl;
                }
            }
            else if (choice == 4) {
                account_db[current_account_index].changePIN();
            }
            else if (choice == 5) {
                cout << "Thank you for using our ATM. Goodbye!" << endl;
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 5);
    }
    return 0;




}
