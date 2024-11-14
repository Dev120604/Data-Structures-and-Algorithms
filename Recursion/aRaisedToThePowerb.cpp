#include<iostream>
using namespace std;

int power(int a, int b) {

    //base case
    if(b == 0) {
        return 1;
    }
    if(b == 1) {
        return a;
    }

    int ans = power(a,b/2);

    if(b & 1) { // if power is odd then
        return a*ans*ans;
    }
    else { // power is even then
        return ans*ans;
    }
} 

int main() {

    int a,b;
    cout << "Enter a and b : "<<endl;
    cin >> a >> b;

    cout << a << " to the power " << b << " is : "<<power(a,b) << endl;

    return 0;
}