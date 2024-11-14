#include<iostream>
using namespace std;

void reverse(int* arr,int size) {

    int start = 0;
    int end = size - 1;

    while(start <= end) {
        swap(arr[start++],arr[end--]);
    }
}

int main() {

    int arr[6] = {1,2,3,4,5,6};

    cout << "---------- Before ----------" << endl;
    for(int i=0 ; i<6 ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    reverse(arr,6);

    cout << "---------- After ----------" << endl;
    for(int i=0 ; i<6 ;i++) {
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}