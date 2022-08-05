#include <iostream>

using namespace std;

void getData(int rows, int columns, int array[4][4]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout <<"enter value for "<<i<<" row and "<<j<<" column : ";
            cin >>array[i][j];
        }
    }
}

void display(int rows, int columns, int array[4][4]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout <<array[i][j]<<" ";
        }
        cout <<endl;
    }
}

void transpose(int rows, int columns, int array1[4][4], int array2[4][4]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            array2[j][i] = array1[i][j];
        }
    }
}

int main() {
    int array1[4][4];
    int array2[4][4];
    getData(4, 4, array1);
    cout <<endl;
    display(4, 4, array1);
    transpose(4, 4, array1, array2);
    cout <<endl;
    display(4, 4, array2);
    return 0;
}