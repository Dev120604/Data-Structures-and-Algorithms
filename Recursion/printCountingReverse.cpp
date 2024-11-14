#include<iostream>
using namespace std;

void print(int n) {

    //base case 
    if(n == 0) {
        return;
    }

    cout << n << " ";
    print(n-1);
}

int main() {

    int num;
    cout << "Enter Number : " << endl;
    cin >> num;

    print(num);

    return 0;
}