#include<iostream>
using namespace std;

bool isSorted(int *arr , int size) {

    //base case
    if(size == 0 || size == 1) {//already sorted
        return true;
    }

    if(arr[0] > arr[1]) {
        return false;
    }
    else {
        return isSorted(arr+1,size-1);
    }
}

int main() {

    int arr[6] = {1,5,7,8,47,89};
    // int arr[6] = {12,5,6,78,98,45};
    
    if(isSorted(arr,6)) {
        cout << "Array is Sorted" << endl;
    }
    else {
        cout << "Array is not Sorted" << endl;
    }

    return 0;
}