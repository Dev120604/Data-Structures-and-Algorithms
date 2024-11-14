#include<iostream>
using namespace std;

/*  */
void insertionSort(int *arr , int size) {

    for(int i=1 ; i<size ; i++) {

        int temp = arr[i];
        int j = i-1;

        for( ; j>=0 ; j--) {

            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }

}

int main() {

    int arr[6] = {12,54,89,63,23,5};
    int size = 6;

    cout << " ---------- Array Before Sorting ---------- " << endl;
    for(int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    insertionSort(arr,size);
    
    cout << " ---------- Array After Sorting ---------- " << endl;
    for(int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}