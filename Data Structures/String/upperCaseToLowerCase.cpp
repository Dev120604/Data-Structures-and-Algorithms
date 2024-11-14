#include<iostream>
using namespace std;

char toLowercase(char &ch) {

    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else {
        char small = (ch - 'A') + 'a';
        return small;
        // return (ch - 'A') + 'a';
    }
}

// void toLower(string &str) {
    
//     for(int i=0 ; i<str.length() ; i++) {
//         str[i] = (str[i] - 'A') + 'a';
//     }
// }

int main() {

    string str = "ABCD";
    
    // toLowercase(str);
    // cout << "Converted String : " << str << endl;

    for(int i=0 ; i<str.length() ; i++) {

        str[i] = toLowercase(str[i]);
    }

    cout << "Converted String : " << str << endl;

    return 0;
}