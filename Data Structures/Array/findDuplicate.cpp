#include<iostream>
using namespace std;

int duplicate(int arr[],int size) {

    // approach : 1

    // int sum = 0;
    // int ans = 0;

    // for(int i=0 ; i<size ; i++) {
    //     sum += arr[i];
    // }
    // for(int i=0 ; i<=size-2;i++) {
    //     ans += i;
    // }
    // return sum - ans;

    // approach : 2

    int ans = 0;

    for(int i=0 ; i<size ; i++) {
        
        ans = ans ^ arr[i];
    }
    for(int i=0 ; i<=size-2 ; i++) {

        ans = ans ^ i;
    }
    return ans;
}

int main() {

    int arr[6] = {0,1,2,3,4,4};

    cout << "Reapeated / Duplicate Element is : " << duplicate(arr,6) << endl;

    return 0;
}