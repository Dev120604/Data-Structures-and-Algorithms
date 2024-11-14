#include<iostream>
using namespace std;

void swapAlternate(int* arr,int size) {

    for(int i=0 ; i<size ; i+=2) {

        if(i+1 < size) {//if i is on last index then i+1 gives array out of bound error
        //that's why we have to check that i+1 remains in array 
            swap(arr[i],arr[i+1]);
        }
    }
}

int main() {

    int arr[6] = {1,2,3,4,5,6};

    cout << "---------- Before ----------" << endl;
    for(int i=0 ; i<6 ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    swapAlternate(arr,6);

    cout << "---------- After ----------" << endl;
    for(int i=0 ; i<6 ;i++) {
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}