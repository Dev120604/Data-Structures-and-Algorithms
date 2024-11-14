#include<iostream>
#include<string>
using namespace std;

int main() {

    string str1 = "hello";

    cout << "at() Method : " <<str1.at(0) << endl;

    cout <<  "front() Method : " << str1.front() << endl;

    cout <<  "back() Method : " << str1.back() << endl;

    cout <<  "data() Method : " << str1.data() << endl;

    cout <<  "empty() Method : " << str1.empty() << endl;

    cout <<  "size() or length() Method : " << str1.length() << endl;

    cout <<  "insert() Method : " << str1.insert(0,1,'i') << endl;
    cout <<  "insert() Method : " << str1.insert(0,"Hi") << endl;
    cout << "String : " << str1 << endl;

    cout <<  "erase() Method : " << str1.erase(0,1) << endl;
    cout << "String : " << str1 << endl;

    cout <<  "erase() Method : " << str1.erase(0,2) << endl;
    cout << "String : " << str1 << endl;

    cout <<  "push_back() Method : " << endl;
    str1.push_back('w');
    cout << "String : " << str1 << endl;

    cout <<  "pop_back() Method : " <<  endl;
    str1.pop_back();
    cout << "String : " << str1 << endl;

    cout <<  "append() Method : " << endl;
    str1.append(1,'w'); //count,character
    cout << "String : " << str1 << endl;
    
    str1.append("orld");
    cout << "String : " << str1 << endl;

    cout << "find() Method : ";
    cout << str1.find('h') << endl;
    cout << "find() Method : " << str1.find("ello") << endl;

    cout << "rfind() Method : " << str1.rfind('l') << endl;
    cout << "rfind() Method : " << str1.rfind("ello") << endl;

    string str2 = "hello";
    cout << "compare() Method : " << str1.compare(str2) << endl;

    cout << "substr() : " << str1.substr(1) << endl;
    cout << "String : " << str1 << endl;
    
    cout << "stoi() : " << stoi("10") << endl;

    cout << "to_string() : " << to_string(10) << endl;
    
    return 0;
}