#include<iostream>
using namespace std;

bool isPalindrome(string &str , int start , int end) {

    //base case
    if(start>end) {
        return true;
    }

    if(str[start] != str[end]) {
        return false;
    }
    else {
        return isPalindrome(str,start+1,end-1);
    }
}

int main() {

    string str;
    cout << "Enter String : " << endl;
    getline(cin,str);

    if(isPalindrome(str,0,str.length()-1)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}