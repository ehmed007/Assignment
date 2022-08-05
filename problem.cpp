#include <iostream>

using namespace std;

int main() {
    int rows = 7;
    int columns = 7;
    int arr[7][7];
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<=i; j++) {
            if (j == 0) {
                arr[i][j] = 1;
            } 
            else if ( j == i) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
            }
        }
    }
    for (int i = 0; i< 7; i++) {
        for (int j = 0; j<=i; j++) {
            cout <<arr[i][j]<<" ";
        }
        cout <<"\n";
    }
    return 0;
}