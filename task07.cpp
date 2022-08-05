#include <iostream>
using namespace std;

class Num_Days {
    private:
        float number_of_hours;
        float number_of_days;
    public:
        // constructor
        Num_Days(float hours = 0) {
            this->set_hours(hours);
        }
        void set_hours(float hours);
        void set_days(float hours);
        float get_hours();
        float get_days();
        Num_Days operator+(const Num_Days obj);
        Num_Days operator-(const Num_Days obj);
        Num_Days operator++(); //pre-increment
        Num_Days operator++(int); //post-increment
        Num_Days operator--(); //pre-decrement
        Num_Days operator--(int); //post-decrement 
        void display() {
            cout << "hours : " << this->number_of_hours << endl;
            cout << "days : " << this->number_of_days << endl;
        }
};
// setter && getter
void Num_Days :: set_hours(float hours) {
        if (hours <= 240) {
            this->number_of_hours = hours;
            this->set_days(hours);
        }
}
void Num_Days :: set_days(float hours) {
    this->number_of_days = hours/8;
}

float Num_Days :: get_hours() {
    return number_of_hours;
}
float Num_Days :: get_days() {
    return (number_of_hours/8);
}

// operator overloading

Num_Days Num_Days :: operator+(const Num_Days obj) {
    Num_Days newobj(obj);
    newobj.number_of_hours = this->number_of_hours + obj.number_of_hours;
    newobj.set_hours(newobj.number_of_hours);
    return newobj;
}

Num_Days Num_Days :: operator-(const Num_Days obj) {
    Num_Days newobj(obj);
    newobj.number_of_hours = this->number_of_hours - obj.number_of_hours;
    newobj.set_hours(newobj.number_of_hours);
    return newobj;
}

Num_Days Num_Days :: operator++() {
    this->set_hours(this->number_of_hours + 1);
    return *this;
}

Num_Days Num_Days :: operator++(int) {
    Num_Days old_state(*this);
    this->set_hours(this->number_of_hours + 1);
    return old_state;
}

Num_Days Num_Days :: operator--() {
    this->set_hours(this->number_of_hours - 1);
    return *this;
}

Num_Days Num_Days :: operator--(int) {
    Num_Days old_state(*this);
    this->set_hours(this->number_of_hours - 1);
    return old_state;
}

class DaysOff {
    private:
        Num_Days max_sick_days;
        Num_Days sick_taken;
        Num_Days max_vacation;
        Num_Days vacation_taken;
        Num_Days max_unpaid;
        Num_Days unpaid_taken;
        string employee_name;
        string identification_num;
    public:
        // constructor
        DaysOff(string name, string id, float months);
        // setters
        void set_max_sick_days(float hours); 
        void set_sick_taken(float hours); 
        void set_max_vacation(float hours); 
        void set_vacation_taken(float hours);  
        void set_max_unpaid(float hours); 
        void set_unpaid_taken(float hours); 
        // getters
        float get_max_sick_days(); 
        float get_sick_taken(); 
        float get_max_vacation(); 
        float get_vacation_taken(); 
        float get_max_unpaid(); 
        float get_unpaid_taken(); 
        void display() { 
            cout << "max days of vacation : " << this->get_max_vacation() << endl; 
            cout << "max days of sick leave : " << this->get_max_sick_days() << endl; 
        } 
}; 

DaysOff :: DaysOff(string name, string id, float months) {
    this->employee_name = name;
    this->identification_num = id;
    this->set_max_sick_days(months * 240);
    this->set_max_vacation(months * 240);
}

// setter

void DaysOff :: set_max_sick_days(float hours) {
    float month = hours / 240;
    hours = month * 8;
    this->max_sick_days.set_hours(hours);
}
void DaysOff :: set_sick_taken(float hours) {
    this->sick_taken.set_hours(hours);
}
void DaysOff :: set_max_vacation(float hours) { 
    float month = hours / 240;
    hours = month * 12;
    if (hours <= 240) {
        this->max_vacation.set_hours(hours);
    }
}
void DaysOff :: set_vacation_taken(float hours) {
    this->vacation_taken.set_hours(hours);
}
void DaysOff :: set_max_unpaid(float hours) {
    float month = hours / 240;
    hours = month * 12;
    this->max_unpaid.set_hours(hours);
}
void DaysOff :: set_unpaid_taken(float hours) {
    this->unpaid_taken.set_hours(hours);
}
// getters

float DaysOff :: get_max_sick_days() {
    return this->max_sick_days.get_days();
}
float DaysOff :: get_sick_taken() {
    return this->sick_taken.get_days();
}
float DaysOff :: get_max_vacation() {
    return this->max_vacation.get_days();
}
float DaysOff :: get_vacation_taken() { 
    return this->vacation_taken.get_days();
}
float DaysOff :: get_max_unpaid() {
    return this->max_unpaid.get_days();
}
float DaysOff :: get_unpaid_taken() {
    return this->unpaid_taken.get_days();
}



int main() {
    float months;
    cout << "\nenter number of months(which employee has worked) : ";
    cin >> months;
    DaysOff obj("ahmed", "34101", months);
    obj.display();
    return 0;
}