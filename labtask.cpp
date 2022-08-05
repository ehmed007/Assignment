#include <iostream>

using namespace std;

class Item {
    private:
        int item_Id;
        string item_name;
        int item_quantity;
        float item_cost;
    public:
    //mutators
    void set_Id(int num) {
        if (num > 0) {
            item_Id = num;
            return;
        }
        item_Id = 0;
    }
    void set_name(string name) {
        item_name = name;
    }
    void set_quantity(int num) {
        if (num > 0) {
            item_quantity = num;
            return;
        }
        item_quantity = 0;
    }
    void set_cost(float num) {
        if (num > 0) {
            item_cost = num;
            return;
        }
        item_cost = 0;
    }

    // accessors
    int get_number() {
        return item_Id;
    }
    string get_name() {
        return item_name;
    }
    int get_quantity() {
        return item_quantity;
    }
    float get_cost() {
        return item_cost;
    }

    //constructor
    Item(int num, string name, int quantity, float cost) {
        set_Id(num);
        set_name(name);
        set_quantity(quantity);
        set_cost(cost);
    }
    Item(int num, string name, int quantity) {
        set_Id(num);
        set_name(name);
        set_quantity(quantity);
        item_cost = 0;
    }
    Item(int num, string name, float cost) {
        set_Id(num);
        set_name(name);
        item_quantity = 0;
        set_cost(cost);
    }
    //copy constructor
    Item(const Item &obj) {
        item_Id = obj.item_Id;
        item_name = obj.item_name;
        item_quantity = obj.item_quantity;
        item_cost = obj.item_cost;
    }
    //default constructor
    Item() {
        item_Id = 0;
        item_name = "";
        item_quantity = 0;
        item_cost = 0;
    }
    //destructor
    ~Item() {
        cout << "destructor executed..." << endl;
    }

    //member function

    void set_item(int num, string name, int quantity, float cost) {
        set_Id(num);
        set_name(name);
        set_quantity(quantity);
        set_cost(cost);
    }

    void get_item() {
        cout << endl;
        cout << "enter the ID : ";
        cin >> this->item_Id;
        set_Id(this->item_Id);

        cout << "enter the name : ";
        cin.ignore();
        getline(cin, this->item_name);
        set_name(this->item_name);

        cout << "enter the quantity : ";
        cin >> this->item_quantity;
        set_quantity(this->item_quantity);
        
        cout << "enter the cost : ";
        cin >> this->item_cost;
        set_cost(this->item_cost);
        cout << endl;
    }
    
    void put_item() {
        cout << endl;
        cout << "Id of item       : " << item_Id <<endl;
        cout << "Name of item     : " << item_name << endl;
        cout << "Quantity of item : " << item_quantity << endl;
        cout << "Cost of item     : " << item_cost << endl;
    }
    
    float get_Total_Cost() {
        if (item_quantity >= 1) {
            return (item_quantity * item_cost);
        }
        return 0;
    }

    bool is_Equal(Item obj) {
        if (this->item_Id == obj.item_Id && this->item_name == obj.item_name && this->item_quantity == obj.item_quantity && this->item_cost == obj.item_cost) {
            return true;
        }
        return false;
    }

    void update_name(Item array[], int size) {
        for (int i = 0; i < size; i++) {
            if (array[i].item_Id == this->item_Id) {
                array[i].item_name = this->item_name;
            }
        }
    }

    Item get_min_cost_item(Item array[], int size) {
        float min = array[0].item_cost;
        for (int i = 0; i < size; i++) {
            if (min > array[i].item_cost) {
                min = array[i].item_cost;
            }
        }
        for (int i = 0; i < size; i++) {
            if (min == array[i].item_cost) {
                return array[i];
            }
        }
    }

    void get_average_price(Item array[], int size) {
        float average_cost = 0;
        for (int i = 0; i < size; i++) {
            average_cost += array[i].item_cost;
        }
        average_cost /= size;
        this->item_cost = average_cost;
    }
};


int main() {
    
    return 0;
}