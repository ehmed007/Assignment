#include <iostream>

using namespace std;

void getData(int rows, int columns, int array[4][3]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout <<"enter value for "<<i<<" row and "<<j<<" column : ";
            cin >>array[i][j];
        }
    }
}

void display(int rows, int columns, int array[4][3]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            // cout <<"value at "<<i<<" row and "<<j<<" column : "<<array[i][j];
            cout <<array[i][j]<<" ";
        }
        cout <<endl;
    }
}

int getRowTotal(int rows, int columns, int array[][3], int rowIndex) {
    int total_of_row = 0;
    for (int j = 0; j<columns; j++) {
        total_of_row += array[rowIndex][j];
    }
    return total_of_row;
}

int main() {
    int array[4][3];
    getData(4, 3, array);
    cout <<endl;
    display(4, 3, array);
    cout <<endl;
    cout <<"Total of Row 3 : "<<getRowTotal(4, 3, array, 2);
    return 0;
}