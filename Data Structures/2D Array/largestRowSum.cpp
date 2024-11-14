#include<iostream>
using namespace std;

int largestRowSum(int** arr , int row , int col) {

    int maxi = INT32_MIN;

    cout << "----------Printing Array ----------" << endl;

    for(int i=0 ; i<row ; i++) {
        int sum = 0;
        for(int j=0 ; j<col ; j++) {
            sum += arr[i][j];
            cout << arr[i][j] << " ";
        }
        cout << " -> " << sum << endl;
        if(sum > maxi) {
            maxi = sum;
        }
    }
    return maxi;
}

int main() {

    // 3 3
    // 1 2 3 4 5 6 7 8 9
    int row,col;
    cin >> row >> col;

    int** arr = new int*[row];

    for(int i=0 ; i<row ; i++) {

        arr[i] = new int[col];
        for(int j=0 ; j<col ; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Largest Row Sum : " << largestRowSum(arr,row,col) << endl;

    return 0;
}