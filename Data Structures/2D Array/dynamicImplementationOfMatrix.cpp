#include<iostream>
using namespace std;

int main() {

    int row,col;

    cout << "Enter Number of Rows : " << endl;
    cin >> row;

    cout << "Enter Number of Columns : " << endl;
    cin >> col;

    int** arr = new int*[row];

    for(int i=0 ; i<row ; i++) {
        
        arr[i] = new int[col];

        for(int j=0 ; j<col ; j++) {
            cout << "Enter Element : " << endl;
            cin >> arr[i][j];
        }
    }

    cout << "---------- Printing 2D Array ----------" << endl;

    for(int i=0 ; i<row ; i++) {
        
        for(int j=0 ; j<col ; j++) {
            
            cout << arr[i][j] << " ";
        }cout << endl;
    }

    return 0;
}