#include<iostream>
using namespace std;

string reverse(string &str) { // linear space S.C : O(n) n:length of string

    string temp = "";

    for(int i=str.length()-1 ; i>=0 ; i--) {
        temp.push_back(str[i]);
        // temp.append(1,str[i]);
    }
    return temp;
}

void reverseTwoPointers(string &str) { // constant space S.C : O(1)

    // Two Pointers Approach
    int start = 0;
    int end = str.length() - 1;

    while(start <= end) {
        // swap(str[start],str[end]);
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start ++;
        end--;
    }
}

int main() {

    string str;
    cout << "Enter a String to Reverse : " << endl;
    getline(cin,str);

    // reverseTwoPointers(str);
    // cout << "Reversed String is : " << str << endl;

    string temp = reverse(str);
    cout << "Reversed String is : " << temp << endl;


    return 0;
}