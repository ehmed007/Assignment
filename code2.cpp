#include <iostream>

using namespace std;

class ahmed {
    private:
        int roll;
        string ah;
        static int ahm;
    public:
        // void get_roll_no() {
        //     // cout << "enter your roll no : "; 
        //     // cin >> this->roll; 
        //     // cout << "addrress in this : "<< this->roll;
        // }
};

int ahmed :: ahm = 0;

int main() {
    cout << "size : " << sizeof(ahmed) << endl;
    // ahmed obj;
    // cout << "addrress of obj : "<<&obj;
    // cout << endl;
    // obj.get_roll_no();
    return 0;
}