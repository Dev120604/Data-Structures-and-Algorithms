#include<iostream>
using namespace std;

int sumOfElement(int* arr , int size) {

    //base case
    if(size == 0) {
        return 0;
    }
    if(size == 1) {
        return arr[0];
    }

    int sum = 0;
    // int remainingArraySum = sumOfElement(arr+1,size-1);

    sum = arr[0] + sumOfElement(arr+1,size-1);

    return sum;
}

int main() {

    int arr[5] = {1,3,5,0,1};
    int ar[6] = {1,1,1,2,2,2};
    int a[1] = {1};

    cout << "Sum Of Array's Elements is : " << sumOfElement(arr,5) << endl;

    return 0;
}