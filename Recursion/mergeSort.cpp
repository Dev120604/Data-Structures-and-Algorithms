#include<iostream>
using namespace std;

void merge(int arr[] , int start , int end) {

    int mid = start + (end-start)/2;

    int len1 = mid-start+1;
    int len2 = end-mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int mainArrayIndex = start;

    //copying values from main array(arr) to first
    for(int i=0 ; i<len1 ; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    //copying values from main array(arr) to second
    for(int i=0 ; i<len2 ; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //sorting arrays and merging them into sorted order(in the main array(arr))

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
            // mainArrayIndex++;
            // index1++;
        }
        else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    //now merge remaining part from both arrays

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int* arr , int start , int end) {

    //base case
    if(start >= end) {
        return ;
    }

    int mid = start + (end-start)/2;

    //left part sort kardo
    mergeSort(arr,start,mid);

    //right part sort kardo
    mergeSort(arr,mid+1,end);

    //now merge two sorted arrays
    merge(arr,start,end);
}

int main() {
    
    int arr[6] = {3,7,8,9,5,1};
    int n = 6;

    cout << "---------- Array Before Sorting ----------" << endl;
    for(int i=0 ; i<6 ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    mergeSort(arr,0,n-1);

    cout << "---------- Array After Sorting ----------" << endl;
    for(int i=0 ; i<6 ; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}