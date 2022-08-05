#include "labtaskk.h"

class Snake : public Reptile {
    public:
        int get_family(){
            return this->get_ID();
        }
        void tell_about_self() {
            cout << "CLASS SNAkE." << endl;
        }
        void Speak() {
            this->Reptile :: Speak();
            cout << "shhhh...." << endl;
        }
};

class Parrot : public Bird {
    public:
        int get_family() {
            return this->get_ID();
        }
        void tell_about_self() {
            cout << "CLASS PARROT." << endl;
        }
        void Speak() {
            this->Bird:: Speak();
            cout << "Trrrr....." << endl;
        }
};

class Horse : public Mamal {
    public:
        int get_family() {
            return this->get_ID();
        }
        void tell_about_self() {
            cout << "CLASS MAMAL." << endl;
        }
        void Speak() {
            this->Mamal :: Speak();
            cout << "Hurrr...." << endl;
        }
};



int main() {
    
    Horse obj;
    obj.Speak();
    return 0;
}