#include<iostream>
using namespace std;

int binarySearch(int arr[] , int size , int key) {

    int start = 0;
    int end = size - 1;

    int mid = start + (end - start)/2;

    while(start <= end) {
           
        if(arr[mid] == key) {
            return mid;
        }

        if(key > arr[mid]) { // key may be present in the left part of the array
            start = mid + 1;
        }
        else { // key may be present in the right part of the array
            end = mid - 1;
        }

        /* now here either start or end was updated so we need to
        update our mid also according to new values that's why ->
        */
        mid = start + (end - start)/2;
    }
    return -1;
}

int main() {

    // Array must be sorted to apply binary search
    int arr[6] = {5,12,23,54,63,89};
    int size = 6;
    int key;
    cout << "Enter the Value you want to Search / Key : " << endl;
    cin >> key;

    int index = binarySearch(arr,size,key);

    if(index == -1) {
        cout << key << " is not Present in the Array" << endl;
    }
    else {
        cout << key << " is Present in the Array at index : " << index << endl;
    }

    return 0;
}