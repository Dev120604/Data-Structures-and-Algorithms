#include<iostream>
using namespace std;

int partition(int arr[] , int start , int end) {

    int pivot = arr[start];
    int count = 0;

    for(int i=start+1 ; i<=end ; i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }

    //place pivot to the right index

    int pivotIndex = start + count;
    swap(arr[start],arr[pivotIndex]);

    //handle left and right portion

    int i = start , j = end;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        //we reaches here when i pointing greter element than pivot and j pointing lesser element than pivot
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i],arr[j]);
        }
    }

    return pivotIndex;
}

void quickSort(int* arr , int start , int end) {

    //base case
    if(start >= end) {
        return ;
    }

    int p = partition(arr,start,end); 

    //left part sort kardo
    quickSort(arr,start,p-1);

    //right part sort kardo
    quickSort(arr,p+1,end);
}

int main() {

    int arr[6] = {3,7,8,9,5,1};
    int n = 6;

    cout << "---------- Array Before Sorting ----------" << endl;
    for(int i=0 ; i<6 ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    quickSort(arr,0,n-1);

    cout << "---------- Array After Sorting ----------" << endl;
    for(int i=0 ; i<6 ; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}