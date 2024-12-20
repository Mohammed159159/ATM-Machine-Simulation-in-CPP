#include <iostream>

using namespace std;

class Account {
private:
    long accountNum;
    int pin;
    long balance;

public:
    Account(long AccountNum, int Pin, long Balance) {
        accountNum = AccountNum;
        pin = Pin;
        balance = Balance;
    }

    void checkBalance() {
        cout << "Your account balance is: " << balance << endl;
    }

    void deposit(long b) {
        balance += b;
        cout << "Your NEW account balance is: " << balance << endl;

    }
    void withdraw(long b) {
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



int main()
{
    Account account1(253, 1234, 500000);
    account1.checkBalance();
    account1.changePIN();

}