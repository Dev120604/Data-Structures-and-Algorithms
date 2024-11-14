#include<iostream>
using namespace std;

/* your array go through from diffrent rounds/passes and in each ith round
   you put ith largest element to it's right position */ 
void bubbleSort(int *arr , int size) {

    for(int i=1 ; i<size ; i++) {

        bool swapped = false;
        for(int j=0 ; j<size-i ; j++) {

            if(arr[j] > arr[j+1]) {
                swap(arr[j+1],arr[j]);
                swapped = true;
            }
        }
        if(swapped == false) { // Already Sorted
            break;
        }  
    }
}

int main() {

    int arr[6] = {12,54,89,63,23,5};
    int size = 6;

    cout << " ---------- Array Before Sorting ---------- " << endl;
    for(int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    bubbleSort(arr,size);
    
    cout << " ---------- Array After Sorting ---------- " << endl;
    for(int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}