#include <iostream>

using namespace std;

string ahmed;
int ahmed2;
void check () {
    cout << "enter : ";
    getline(cin, ahmed);
    cout << "enter u : ";
    cin >> ahmed2;
    cin.ignore();
}

int main() {
    for (int i = 0; i<5; i++) {
        check();
    }
    return 0;
}