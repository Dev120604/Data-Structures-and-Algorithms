#include<iostream>
using namespace std;

string palindrome(string &str) { // linear space S.C : O(n) n:length of string

    string temp = "";

    for(int i=str.length()-1 ; i>=0 ; i--) {
        temp.push_back(str[i]);
    }
    return temp;
}

bool isPalindrome(string &str) { // constant space S.C : O(1)

    // two pointers approach
    int start = 0;
    int end = str.length() - 1;

    while(start <= end) {

        if(str[start] == str[end]) {
            start++;
            end--;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {

    string str;
    cout << "Enter a String : " << endl;
    getline(cin,str);

    // if(isPalindrome(str)) {
    //     cout << "String is Palindrome " << endl;
    // }
    // else {
    //     cout << "String is Not Palindrome " << endl;
    // }

    string temp = palindrome(str);

    // if(str == temp) {
    //     cout << "String is Palindrome" << endl;
    // }
    // else {
    //     cout << "String is Not Palindrome" << endl;
    // }

    if(!str.compare(temp)) {
        cout << "String is Palindrome" << endl;
    }
    else {
        cout << "String is Not Plaindrome" << endl;
    }

    return 0;
}