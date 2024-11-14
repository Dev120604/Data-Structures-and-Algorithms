#include<iostream>
using namespace std;

int factorial(int n) {

    //base case
    if(n==0 || n==1) {
        return 1;
    }

    return n * factorial(n-1);
}

int main() {

    int num;
    cout << "Enter the Number : " << endl;
    cin >> num;

    cout << "Factorial of " << num << " is : " << factorial(num) << endl;

    return 0;
}