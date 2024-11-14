#include<iostream>
using namespace std;

void sortArray(int* arr , int n) {

    //base case
    if(n == 0 || n == 1) {
        return ;
    }

    for(int i=0 ; i<n-1 ; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i],arr[i+1]);
        }
    }
    sortArray(arr,n-1);
}

int main() {

    int arr[6] = {12,45,98,78,89,5};

    cout << "---------- Array Before Sorting ----------" << endl;
    for(int i=0 ; i<6 ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    sortArray(arr,6);

    cout << "---------- Array After Sorting ----------" << endl;
    for(int i=0 ; i<6 ; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}