#include <iostream>

using namespace std;

int main() {
    int arr1[5] = {1,3,4,7,8};
    int arr2[5] = {0,2,5,6,9};
    int arr3[10];
    int j = 0;
    int k = 0;
    for (int i=0; i<10; i++) {
        if (arr1[j] <= arr2[k]) {
            arr3[i] = arr1[j];
            j++;
            continue;
        } 
        if (arr1[j] >= arr2[k]) {
            arr3[i] = arr2[k];
            k++;
            continue;
        }
    }

    for (int i=0; i<10; i++) {
        cout <<arr3[i]<<" ";
    }
    return 0;
}