#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Account {
    int accNo;
    float balance;
};

int main() {
    vector<Account> accounts;

    // Step 1: Read accounts from file
    ifstream infile("account.txt");

    if (!infile) {
        cout << "File not found!\n";
        return 0;
    }

    Account a;
    while (infile >> a.accNo >> a.balance) {
        accounts.push_back(a);
    }
    infile.close();

    // Step 2: Take account number
    int userAcc;
    cout << "Enter Account Number: ";
    cin >> userAcc;

    int index = -1;

    // Step 3: Search account
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accNo == userAcc) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found!\n";
        return 0;
    }

    int choice;
    float amount;

    cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\nEnter choice: ";
    cin >> choice;

    // Step 4: Perform operation
    if (choice == 1) {
        cout << "Balance: " << accounts[index].balance << endl;
    }

    else if (choice == 2) {
        cout << "Enter amount to deposit: ";
        cin >> amount;

        accounts[index].balance += amount;

        ofstream history("history.txt", ios::app);
        history << "Account " << userAcc << " Deposit " << amount << endl;
        history.close();
    }

    else if (choice == 3) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= accounts[index].balance) {
            accounts[index].balance -= amount;

            ofstream history("history.txt", ios::app);
            history << "Account " << userAcc << " Withdraw " << amount << endl;
            history.close();
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    else {
        cout << "Invalid choice!\n";
        return 0;
    }

    // Step 5: Rewrite account.txt
    ofstream outfile("account.txt");

    for (int i = 0; i < accounts.size(); i++) {
        outfile << accounts[i].accNo << " " << accounts[i].balance << endl;
    }

    outfile.close();

    cout << "Transaction complete.\n";

    return 0;
}
