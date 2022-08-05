#include <iostream>
using namespace std;

class Moving_Van {
    protected:
        float payLoad;
        float weight;
        float mpg;
    public:
        Moving_Van() {
            cout << "MOVING VAN :: Default constructor " << endl;
            this->payLoad = 0;
            this->weight = 0;
            this->mpg = 0;
        }
        Moving_Van(float p, float w, float m) {
            cout << "MOVING VAN :: parameterized constructor " << endl;
            this->payLoad = p;
            this->weight = w;
            this->mpg = m;
        }
        Moving_Van(const Moving_Van& obj) {
            cout << "MOVING VAN :: copy constructor " << endl;
            this->payLoad = obj.payLoad;
            this->weight = obj.weight;
            this->mpg = obj.mpg;
        }
        ~Moving_Van() {
            cout << "MOVING VAN :: Destructor " << endl;
        }
        void initialize(float payLoad, float weight, float mpg) {
            this->payLoad = payLoad;
            this->weight = weight;
            this->mpg = mpg;
        }
        float efficiency() {
            return (payLoad / (payLoad + weight));
        }
        float cost_per_ton(float fuel_cost) {
            return (fuel_cost / (payLoad / 2000.0));
        }      
};

class Driver {
    protected:
        float hourly_pay;
        float weight;
    public:
        Driver() {
            cout << "Driver :: Default constructor " << endl;
            this->hourly_pay = 0;
            this->weight = 0;
        }
        Driver(float h, float w) {
            cout << "Driver :: parameterized constructor " << endl;
            this->hourly_pay = h;
            this->weight = w;
        }
        Driver(const Driver& obj) {
            cout << "Driver :: copy constructor " << endl;
            this->hourly_pay = obj.hourly_pay;
            this->weight = obj.weight;
        }
        ~Driver() {
            cout << "Driver :: Destructor " << endl;
        }
        void initialize(float hourly_pay, float weight) {
            this->hourly_pay = hourly_pay;
            this->weight = weight;
        }
        float cost_per_mile() {
            return (hourly_pay / 55.0);
        }
        float drivers_wieght() {
            return this->weight;
        }
};

class Driven_Truck : public Moving_Van, public Driver {
    public:
        Driven_Truck() {
            cout << "Driven Truck :: Default constructor " << endl;
        }
        Driven_Truck(float payLoad, float weight1, float mpg, float hourly_pay, float weight2) : Moving_Van(payLoad, weight1, mpg), Driver(hourly_pay, weight2) {
            cout << "Driven Truck :: parameterized constructor " << endl;
        }
        Driven_Truck(const Driven_Truck& obj) {
            cout << "Driven Truck :: copy constructor " << endl;
        }
        ~Driven_Truck() {
            cout << "Driven Truck :: Destructor " << endl;
        }
        void initialize(float payLoad, float weight1, float mpg, float hourly_pay, float weight2)  {
            this->payLoad = payLoad;
            Moving_Van :: weight = weight1;       
            this->mpg = mpg;
            this->hourly_pay = hourly_pay;
            Driver :: weight = weight2;
        }
        float cost_per_full_day(float cost_of_gas) {
            return ((8.0 * this->hourly_pay + 8.0 * cost_of_gas * 55.0) / this->mpg);
        }
        float total_weight() {
            return (Moving_Van :: weight + Driver :: weight);
        }
};

int main() {
    Driven_Truck chuck_ford;
    chuck_ford.initialize(10, 50, 100, 5, 60);
    chuck_ford.Driver :: initialize(23, 34);
    cout << "Efficiency    : " << chuck_ford.efficiency() << endl;
    cout << "Cost Per Mile : " << chuck_ford.cost_per_mile() << endl;
    cout << "Cost Per Day  : " << chuck_ford.cost_per_full_day(100) << endl;
    cout << "Total Weight  : " << chuck_ford.total_weight() << endl;
    return 0;
}