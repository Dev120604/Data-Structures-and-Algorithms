#include<iostream>
using namespace std;

char toUpperCase(char &ch) {

    if(ch >= 'A' && ch<= 'Z') {
        return ch;
    }
    else {
        char capital = (ch - 'a') + 'A';
        return capital;
    }
}

string toUpperCase(string &str) {

    string temp = "";

    for(int i=0 ; i<str.length() ; i++) {
        char ch = str[i];
        char capital_ch = (ch - 'a') + 'A';
        temp.push_back(capital_ch);
    }
    return temp;
}

int main() {

    string str = "abcd";

    for(int i=0 ; i<str.length() ; i++) {

        str[i] = toUpperCase(str[i]);
    }

    cout << "Converted String : " << str << endl;

    // cout << "Converted String : " << toUpperCase(str) << endl;

    return 0;
}