#include <iostream>

using namespace std;

class Employee {
    private:
        string name;
        int year;
        string address;
    public:
        Employee() {
            this->name = "";
            this->year = 1990;
            this->address = "";
        }
        void get_data() {
            int year = 0;
            cout << "enter name : ";
            getline(cin, this->name);
            cout << "enter year : ";
            cin >> year;
            while (year < 1985 || year > 2020) {
                cout << "enter year : ";
                cin >> year;
            }
            this->year = year;
            cin.ignore();
            cout << "enter address : ";
            getline(cin, this->address);
        }
        void display_data() {
            cout << this->name << "\t" << this->year << "\t" << this->address <<endl;
        }
};

int main() {
    int n = 0;
    Employee arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i].get_data();
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << " Name " << "\t" << " Year " << "\t" << "Address" << endl << endl; 
    for (int i = 0; i < 10; i++) {
        arr[i].display_data();
    }
    cout << endl;
    cout << endl;
    while(1) {
        cout << "enter value of index n : ";
        cin >> n;
        if (n >= 0 && n <= 9) {
            break;
        }
    }
    // while (n < 0 || n > 9) {
    //     cout << "wrong!" <<endl;
    //     cout << "enter value of index n : ";
    //     cin >> n;
    // }
    cout << "\n Data for index u entered " <<endl;
    cout << " Name " << "\t" << " Year " << "\t" << "Address" << endl << endl; 
    arr[n].display_data();
    return 0;
}