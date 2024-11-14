#include<iostream>
using namespace std;

// puts the smallest element of the array to it's right position
void selectionSort(int *arr , int size) {

    for(int i=0 ; i< size ; i++) {
        
        int minIndex = i;

        for(int j=i+1 ; j<size ; j++) {

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main() {

    int arr[6] = {12,54,89,63,23,5};
    int size = 6;

    cout << " ---------- Array Before Sorting ---------- " << endl;
    for(int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    selectionSort(arr,size);
    
    cout << " ---------- Array After Sorting ---------- " << endl;
    for(int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}