#include<iostream>
using namespace std;

void merge(int* arr1,int n,int* arr2,int m,int* arr3) {

    int i , j , k;
    i = j = k = 0;

    while(i<n && j<m) {

        if(arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {//arr2[j] < arr1[i]
            arr3[k++] = arr2[j++];
        }
    }

    //if arr1's length is greater than arr2
    while(i < n) {  
        arr3[k++] = arr1[i++];
    }

    //if arr2's length is greater than arr1
    while(j < m) {
        arr3[k++] = arr2[j++];
    }
}

int main() {

    int arr1[5] = {1,3,5,7,9};
    int arr2[5] = {2,4,6,8,10};

    int arr3[10] = {0};

    merge(arr1,5,arr2,5,arr3);

    cout << "---------- Printing Resultant Array ----------" << endl;

    for(int i=0 ; i<10 ; i++) {
        cout << arr3[i] << " ";
    }cout << endl;

    return 0;
}