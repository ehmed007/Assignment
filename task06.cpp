#include <iostream>
using namespace std;

class IntegerSet {
    private:
        int* array;
        const int size = 10;
    public:
        IntegerSet(int size); //simple or default constructor
        IntegerSet(const IntegerSet& obj); // copy constructor
        ~IntegerSet(); // destructor
        friend ostream& operator<<(ostream& cout, const IntegerSet obj); // stream insetion operator overload
        IntegerSet operator=(const IntegerSet obj); // assignment operator
        bool operator==(const IntegerSet obj); // equal to operator overload
        IntegerSet operator!(); // for reversing the obj elements
        void insert_Element(int k); // to insert element
        void delete_Element(int k); // delete element
        IntegerSet union_of_set(const IntegerSet obj); // to find union
        IntegerSet intersection_of_set(const IntegerSet obj); // to find intersection 
        bool find_integer(int key); // to find integer
        bool isNullset(); // to check set is NULL
};

IntegerSet :: IntegerSet(int size) : size(size) {
    this->array = new int[size];
    for (int i = 0; i < this->size; i++) {
        this->array[i] = 0;
    }
}

IntegerSet :: IntegerSet(const IntegerSet& obj) : size(size) {
    this->array = new int[this->size];
    for (int i = 0; i < this->size; i++) {
        this->array[i] = obj.array[i];
    }
}

IntegerSet :: ~IntegerSet() {
    delete[] array;
}

ostream& operator<<(ostream& cout, const IntegerSet obj) {
    for (int i = 0; i < obj.size; i++) {
        if (obj.array[i] == 1) {
            cout << obj.array[i] << " ";
        }
    } return cout;
} 

IntegerSet IntegerSet :: operator=(const IntegerSet obj) {
    if (this != &obj) {
        if (this->size == obj.size) {
            for (int i = 0; i < this->size; i++) {
                this->array[i] = obj.array[i];
            }
        }
    } return *this;
}

bool IntegerSet :: operator==(const IntegerSet obj) {
    if (this->size == obj.size) {
        for (int i = 0; i < this->size; i++) {
            if (this->array[i] != obj.array[i]) {
                return false;
            }
        } return true;
    } return false;
}

IntegerSet IntegerSet :: operator!() {
    IntegerSet newobj(this->size);
    for (int i = 0; i < this->size; i++) {
        if (this->array[i] == 1) {
            newobj.array[i] == 0;
        } else {
            newobj.array[i] = 1;
        }
    } return newobj;
}

void IntegerSet :: insert_Element(int k) {
    if (k >= 0 && k < this->size) {
        this->array[k] = 1;
    } else {
        cout << "index is out-of-bound " << endl;
    }
}

void IntegerSet :: delete_Element(int k) {
    if (k >= 0 && k < this->size) {
        this->array[k] = 0;
    } else {
        cout << "index is out-of-bound " << endl;
    }
}

IntegerSet IntegerSet :: union_of_set(const IntegerSet obj) {
    if (this->size == obj.size) {
        IntegerSet union_obj(this->size);
        for (int i = 0; i < this->size; i++) {
            if (this->array[i] == 0 && obj.array[i] == 0) {
                union_obj.array[i] = 0;
            } else {
                union_obj.array[i] = 1;
            }
        } return union_obj;
    } cout << "Sizes are not same Union not possible!" << endl;
    exit(0);
}

IntegerSet IntegerSet :: intersection_of_set(const IntegerSet obj) {
    if (this->size == obj.size) {
        IntegerSet intersection_obj(this->size);
        for (int i = 0; i < this->size; i++) {
            if (this->array[i] == 1 && obj.array[i] == 1) {
                intersection_obj.array[i] = 1;
            } else {
                intersection_obj.array[i] = 0;
            }
        } return intersection_obj;
    } cout << "Sizes are not same Intersection not possible!" << endl;
    exit(0);
}

bool IntegerSet :: find_integer(int key) {
    if (this->array[key] == 1) {
        return true;
    } return false;
}

bool IntegerSet :: isNullset() {
    cout << "value " << this->size;
    for (int i = 0; i < this->size; i++) {
        if (this->array[i] != 0) {
            return false;
        }
    } return true;
}


int main() {
    return 0;
}