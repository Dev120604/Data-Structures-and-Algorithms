#include<iostream>
using namespace std;

int main() {

    int row,col;

    cout << "Enter the Number of Row : " << endl;
    cin >> row;

    cout << "Enter the Number of Column : " << endl;
    cin >> col;

    int** arr = new int*[row];

    for(int i=0 ; i<row ; i++) {

        arr[i] = new int[col];

        for(int j=0 ; j<col ; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "----------Printing Array ----------" << endl;

    for(int i=0 ; i<row ; i++) {

        int sum = 0;
        for(int j=0 ; j<col ; j++) {
            sum += arr[i][j];
            cout << arr[i][j] << " ";
        }
        cout << " -> " << sum << endl;
    }

    return 0;
}