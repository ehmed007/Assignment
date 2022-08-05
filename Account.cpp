#include <iostream>
#include <iomanip>
using namespace std;

class Account {
    protected:
        string first_name;
        string last_name;
        double current_balance;
    public:
        Account(string first_name, string last_name, double current_balance) {
            this->first_name = first_name;
            this->last_name = last_name;
            this->current_balance = current_balance;
        }
        virtual string get_Acc_type() const {
            return "Account";
        }
        virtual double debitTransaction(double transaction_amount) {
            this->current_balance -= transaction_amount;
            return this->current_balance; 
        }
        virtual double creditTransaction(double transaction_amount) {
            this->current_balance += transaction_amount;
            return this->current_balance;
        }
        void print() {
            cout << this->first_name << " " << this->last_name << "\t\t" << this->get_Acc_type() << "\t\t" << fixed << setprecision(2) << this->current_balance << endl;
        }
};

class CheckingAccount : public Account {
    private:
        void charge_fee() {
            this->current_balance -= 10;
        }
    public:
        CheckingAccount(string first_name, string last_name, double current_balance) : Account(first_name, last_name, current_balance) {}
        virtual string get_Acc_type() const {
            return "Checking Account";
        }
        double debitTransaction(double transaction_amount) {
            if (this->current_balance < 100) {
                this->charge_fee();
            }
            Account :: debitTransaction(transaction_amount);
            return this->current_balance;
        }
        double cretitTransaction(double transaction_amount) {
            if (this->current_balance < 100) {
                this->charge_fee();
            }
            Account :: creditTransaction(transaction_amount);
            return this->current_balance;
        }
};

class SavingsAccount : public Account {
    private:
        static int i;
        void payInterest() {
            this->current_balance += this->current_balance*0.02;
        }
    public: 
        SavingsAccount(string first_name, string last_name, double current_balance) : Account(first_name, last_name, current_balance) {} 
        virtual string get_Acc_type() const {
            return "Saving Account";
        }
        double debitTransaction(double transaction_amount) {
            if (i < 2) {
                Account :: debitTransaction(transaction_amount);
                payInterest();
                i++;
            }
            return this->current_balance;
        }
        double creditTransaction(double transaction_amount) {
            if (i < 2) {
                Account :: creditTransaction(transaction_amount);
                payInterest();
                i++;
            }
            return this->current_balance;
        }
};

int SavingsAccount  :: i = 0; 

int main() {
    Account* ac2 = new CheckingAccount("Saud", "Yaseen", 200.0);
    Account* ac1 = new SavingsAccount("Hunain", "Shahid", 1000.0);
    ac2->print();
    ac1->print();
    cout << endl;
    cout << endl;
    ac2->debitTransaction(150);
    // ac2->print();
    ac2->debitTransaction(5);
    // ac2->print();
    ac2->creditTransaction(200);
    ac2->print();
    ac1->debitTransaction(150);
    // ac1->print();
    ac1->creditTransaction(200);
    // ac1->print();
    ac1->debitTransaction(5);
    ac1->print();
    return 0;
}