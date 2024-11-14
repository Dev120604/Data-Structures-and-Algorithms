#include<iostream>
using namespace std;

int length(string &str) {

    int count = 0;
    int i = 0;

    while(str[i] != '\0') {
        count ++;
        i++;
    }

    // for(int i=0 ; str[i] != '\0' ; i++) {
    //     count++;
    // }
    return count;
}

int main() {

    string str = "Hello World";
    string s ;
    cout << "Enter s : " << endl;
    getline(cin,s);

    cout << "Length of str is : " << length(str) << endl;
    cout << "Length of str by .length() is : " << str.length() << endl;
    cout << "Length of s is : " << length(s) << endl;
    cout << "Length of s by .length() is : " << s.length() << endl;

     return 0;
}