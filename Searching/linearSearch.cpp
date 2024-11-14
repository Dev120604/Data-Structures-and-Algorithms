#include<iostream>
using namespace std;

bool isPresent(int arr[] , int size , int key) { //you can use int *arr also

    for(int i=0 ; i<size ; i++) {
        if(arr[i] == key) {
            return true;
        }
    }
    return false;
}

int main() {

    int arr[6] = {12,54,89,63,23,5};
    int size = 6;
    int key;
    cout << "Enter the Value you want to Search / Key : " << endl;
    cin >> key;

    if(isPresent(arr,size,key)) {
         cout << key << " is Present in the Array" << endl;
    }
    else {
        cout << key << " is Not Present in the Array" << endl;
    }

    return 0;
}