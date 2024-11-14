#include<iostream>
using namespace std;

// i am using "1-based" indexing here
int fibo(int n) {

    //base case
    if(n == 1) {//first term
        return 0;
    }
    if(n == 2) {//second term
        return 1;
    }

    return fibo(n-1) + fibo(n-2);
}

int main() {

    int term;
    cout << "Enter the term of fibonacci series : " << endl;
    cin >> term;

    cout << "The " << term << " th term of fibonnaci series is : " << fibo(term) << endl;
    return 0;
}