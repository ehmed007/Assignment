#include <iostream>

using namespace std;

class Rational_Number {
    private:
        int numerator;
        int denominator;
    public:
        // mutators
        void set_numerator(int num) {
            numerator = num;
        }
        void set_denominator(int num) {
            if (num > 0) {
                denominator = num;
            }
            denominator = 1;
        }
        // accessors
        int get_numerator() {
            return numerator;
        }
        int get_denominator() {
            return denominator;
        }
        // constructor
        Rational_Number() {}

        Rational_Number(int num, int den) {
            set_numerator(num);
            set_denominator(num);
        } 
        Rational_Number(int num) {
            set_numerator(num);
            set_denominator(1);
        }
        friend istream& operator>>(istream& cin, Rational_Number& obj);
        friend ostream& operator<<(ostream& cout, Rational_Number& obj);   
        Rational_Number operator+(Rational_Number obj);
        Rational_Number operator-(Rational_Number obj);
        Rational_Number operator*(Rational_Number obj);
        Rational_Number operator/(Rational_Number obj);
        bool operator<(Rational_Number obj);
        bool operator==(Rational_Number obj);
        Rational_Number operator-();
        bool operator!();
        bool operator=(Rational_Number obj) {
            cout << "ahmed " << this;
            this->numerator = obj.numerator;
            this->denominator = obj.denominator;
            return true;
        }
        
        void addd() {
            cout << this;
        }
};

istream& operator>>(istream& cin, Rational_Number& obj) {
    cout << "enter value of numerator : ";
    cin >> obj.numerator;
    obj.set_numerator(obj.numerator);
    cout << "enter value of denominator : ";
    cin >> obj.denominator;
    obj.set_denominator(obj.denominator);
    return cin;
}

ostream& operator<<(ostream& cout, Rational_Number& obj) {
    cout << "Rational number : " << obj.numerator << " / " <<obj.denominator << endl;
    return cout; 
}

Rational_Number Rational_Number :: operator+(Rational_Number obj) {
    Rational_Number temp;
    temp.set_numerator((this->numerator * obj.denominator) + (obj.numerator * this->denominator));
    temp.set_denominator(this->denominator * obj.denominator);
    return temp;
}
Rational_Number Rational_Number :: operator-(Rational_Number obj) {
    Rational_Number temp;
    temp.set_numerator((this->numerator * obj.denominator) - (obj.numerator * this->denominator));
    temp.set_denominator(this->denominator * obj.denominator);
    return temp;
}

Rational_Number Rational_Number :: operator*(Rational_Number obj) {
    Rational_Number temp;
    temp.set_numerator(this->numerator * obj.numerator);
    temp.set_denominator(this->denominator * obj.denominator);
    return temp;
}

Rational_Number Rational_Number :: operator/(Rational_Number obj) {
    Rational_Number temp;
    temp.set_numerator(this->numerator * obj.denominator);
    temp.set_denominator(this->denominator * obj.numerator);
    return temp;
}

bool Rational_Number :: operator<(Rational_Number obj) {
    return ((this->numerator * obj.denominator) < (obj.numerator / this->denominator));
}
bool Rational_Number :: operator==(Rational_Number obj) {
    return ((this->numerator / obj.denominator) == (obj.numerator / this->denominator));
}

Rational_Number Rational_Number :: operator-() {
    if ((this->numerator > 0) && (this->denominator > 0)) {
        this->numerator = -this->numerator;
        return *this;
    }
    return *this;
}

bool Rational_Number :: operator!() {
    if ((this->numerator < 0) || (this->denominator < 0)) {
        return true;
    }
    return false;
}
int main() {
    Rational_Number obj(4,6);
    Rational_Number obj2(3,4); 
    // obj = obj2;
    obj.operator=(obj2);
    cout << "address of obj ;" << &obj;
    // cout << obj;
    return 0;
}