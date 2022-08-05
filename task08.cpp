#include <iostream>
using namespace std;

class Ship {
    private:
        string name;
        string year;
    public:
        Ship(string name, string year) {
            this->setName(name);
            this->setYear(year);
        }
        void setName(string name) {
            this->name = name;
        }
        void setYear(string year) {
            this->year = year;
        }
        string getName() {
            return this->name;
        }
        string getYear() {
            return this->year;
        }
        virtual void print() {
            cout << "Ship Name : " << this->name << endl;
            cout << "Ship Year : " << this->year << endl;
        }
};

class CruiseShip : public Ship {
    private:
        int passenger_count;
    public:
        CruiseShip(int count, string name, string year) : Ship(name, year) {
            this->setPassenger_count(count);
        }
        void setPassenger_count(int count) {
            this->passenger_count = count;
        }
        int getPassenger_count() {
            return this->passenger_count;
        }
        void print() {
            Ship :: print();
            cout << "Max Passengers : " << this->passenger_count << endl;
        }
};

class CargoShip : public Ship {
    private:
        int cargo_capacity;
    public:
        CargoShip(int capacity, string name, string year) : Ship(name, year) {
            this->setCargo_capacity(capacity);
        }
        void setCargo_capacity(int capacity) {
            this->cargo_capacity = capacity;
        }
        int getCargo_capacity() {
            return this->cargo_capacity;
        }
        void print() {
            Ship :: print();
            cout << "Cargo capacity in tonns : " << this->cargo_capacity << endl;
        }
};

class Battleship : public Ship {
    private:
        int number_of_missiles;
    public:
        Battleship(int no_of_missiles, string name, string year) : Ship(name, year) {
            this->setNumber_of_missiles(no_of_missiles);
        }
        void setNumber_of_missiles(int no_of_missiles) {
            this->number_of_missiles = no_of_missiles;
        }
        int getNumber_of_missiles() {
            return this->number_of_missiles;
        }
        void print() {
            Ship :: print();
            cout << "Number of missiles : " << this->number_of_missiles << endl;
        }
};

int main() {
    CruiseShip* obj = new CruiseShip(100, "Cruiseship", "1998");
    CargoShip* obj1 = new CargoShip(500, "Cargoship", "2000");
    Battleship* obj2 = new Battleship(1000, "Battleship", "1950");
    Ship* array[] = {obj, obj1, obj2};
    for (int i = 0; i < 3; i++) {
        array[i]->print();
        cout << endl;
    }
    return 0;
}