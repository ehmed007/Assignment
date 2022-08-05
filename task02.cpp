#include <iostream>

using namespace std;

void getData(int size, int array[]) {
    for (int i=0; i<size; i++) {
        cout <<"enter value for "<<i<<" index : ";
        cin >>array[i];
    }
}

int getElement(int size, int array[], int index) {
    return array[index];
}

int countEvens(int size, int array[]) {
    int count = 0;
    for (int i=0; i<size; i++) {
        if (array[i]%2 == 0) {
            count++;
        }
    }
    return count;
}

void display(int size, int array[]) {
    for (int i=0; i<size; i++) {
        cout <<"value : "<<array[i]<<endl;
    }
} 

int main() {
    int array[10];
    getData(10, array);
    cout <<"Display Numbers you entered : "<<endl;
    display(10, array);
    cout <<"\nTotal evens : "<<countEvens(10, array);
    return 0;
}