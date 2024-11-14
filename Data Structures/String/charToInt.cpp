#include<iostream>
using namespace std;

int charToInt(char &ch) {

    if(ch >= '0' && ch <= '9') {
        // int temp = ch - '0';
        // return temp;
        return ch - '0';
    }
}

int main() {

    char ch = '7';

    cout << "Integer Value of Character " << ch << " is : " << charToInt(ch) << endl;

    return 0;
}