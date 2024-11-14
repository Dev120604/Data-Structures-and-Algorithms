#include<iostream>
using namespace std;

bool isPresent(int* arr , int size , int k) {
    
    //base case
    if(size == 0) {
        return false;
    }

    if(arr[0] == k) {
        return true;
    }
    else {
        return isPresent(arr+1,size-1,k);
    }
}

int main() {

    int arr[6] = {22,56,89,74,12,23};
    int target;
    cout << "Enter Element you want to Search : " << endl;
    cin >> target;

    if(isPresent(arr,6,target)) {
        cout << target << " is Present in the Array" << endl;
    }
    else {
        cout << target << " is not Present in the Array" << endl;
    }

    return 0;
}