#include<iostream>
using namespace std;

bool binarySearch(int* arr , int start , int end , int k) {

    //base case
    if(start>end) {
        return false;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] == k) {
        return true;
    }

    if(arr[mid] > k) {
        return binarySearch(arr,start,mid-1,k);
    }
    else {
        return binarySearch(arr,mid+1,end,k);
    }
}

int main() {

    int arr[6] = {12,23,45,56,78,89};
    int target;
    cout << "Enter Element you want to Search : " << endl;
    cin >> target;

    if(binarySearch(arr,0,5,target)) {
        cout << target << " is Present in the Array" << endl;
    }
    else {
        cout << target << " is not Present in the Array" << endl;
    }

    return 0;
}