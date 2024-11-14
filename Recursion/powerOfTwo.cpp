#include<iostream>
using namespace std;

int power(int n) {

    //base case 
    if(n == 0) {
        return 1;
    }

    return 2 * power(n-1);
}

int main() {

    int pow;
    cout << "Enter Power : " << endl;
    cin >> pow;

    cout << "2 to the power " << pow <<  " is : " << power(pow) << endl;;

    return 0;
}