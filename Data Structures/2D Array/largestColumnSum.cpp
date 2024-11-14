#include<iostream>
using namespace std;

int largestColSum(int** arr,int row , int col) {

    int maxi = INT32_MIN;

    cout << "----------Printing Array ColumWise----------" << endl;

    for(int i=0 ; i<col ; i++) {
        int sum = 0;
        for(int j=0 ; j<row ; j++) {
            sum += arr[j][i];
            cout << arr[j][i] << " ";
        }
        cout << " -> " << sum << endl;
        if(sum > maxi ) {
            maxi = sum;
        } 
    }
    return maxi;
}

int main() {

    int row,col;
    cin >> row >> col;

    int** arr = new int*[row];

    for(int i=0 ; i<row ; i++) {

        arr[i] = new int[col];
        for(int j=0 ; j<col ; j++) {
            cin >>arr[i][j];
        }
    }

    cout << "Largest Column Sum : " << largestColSum(arr,row,col);

    return 0;
}